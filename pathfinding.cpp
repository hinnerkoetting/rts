/////////////////////////////////////////////////////////////////
//
//					
//					pathfinding.cpp
//					
//					
//
/////////////////////////////////////////////////////////////////
#include "pathfinding.h"
#include "field.h"
#include "ingame.h"
#include "errors.h"
#include "mymath.h"
#include <algorithm>

/*
 *
 * check if a node is on a list
 *
 */
bool Pathfinding::onList(std::list<Node*> list, Node* node) {
	for (std::list<Node*>::iterator i = list.begin(); i != list.end(); i++)
		if (node == *i)
			return true;
	return false;
}
/*int abs(int x) {
	if (x >= 0)
		return x;
	return -x;
}*/

bool Pathfinding::finalFieldOnList(std::list<Node*> list) {
	for (std::list<Node*>::iterator i = list.begin(); i != list.end(); i++) {
		std::list<Node*>::value_type tmp = *i;
		if (tmp->x == this->desX && tmp->y == this->desY)
			return true;
	}
	return false;
}

int sqr(int i) {
	return i * i;
}

int min(int a, int b) {
	if ( a < b)
		return a;
	return b;
}
/*
 *
 * looks for node with estimated lowest costs to destination
 *
 */
Node* Pathfinding::findLowestCosts(std::list<Node*> list, int desX, int desY) { 
	int lowestCosts = 99999;
	Node* result = 0;
	for (std::list<Node*>::iterator i = list.begin(); i != list.end(); i++) {
		std::list<Node*>::value_type tmp = *i;
		if (tmp->approxCosts == 0)
			tmp->approxCosts = tmp->costs + abs(desX - tmp->x) *60 + abs(desY - tmp->y) * 60;
		if (tmp->approxCosts < lowestCosts) {
			result = tmp;
			lowestCosts = tmp->approxCosts;
		}
	}
	return result;
}
/* 
 * list is in wrong direction and needs to be copied so its not deleted later
 * due to the fact, that the unit may moving while its given another moveorder there is the following problem: the unit moves at first to the field nearest to its actual position
 * and then moves the right way. so it can happen that the first field is wrong direction, this is here corrected 
 */
std::list<Node*> Pathfinding::giveOutResult(Node* n, int orX, int orY) {
	std::list<Node*> res;
	if (n != 0) {
		//res.push_front(new Node(n->x, n->y, n->costs, 0)); //change direction  of list
		while (n->parent != 0) {
			
			res.push_front(new Node(n->x, n->y, n->costs, 0));
			n = n->parent;
		}
	}
	else {
		res.push_back(new Node(orX, orY, 0, 0));
		return res;
	}
	res.push_front(new Node(orX, orY, 0, 0));
	return res;
	
}

/* 
 *
 * checks if unit has reached a field
 *
 */
bool Pathfinding::atDestination(int x, int y, Node* n) {
	if (n->x == x && n->y == y)
		return true;
	return false;
}

/*
 *
 * checks next 2 fields for barriers
 *
 */
void Pathfinding::checkPath(int actX, int actY) {
	if (this->getPath().size() > 2) { 
		//std::list<Node*>::iterator i = getPath().begin(); // dont know why, but it doesnt work with an iterator
		std::list<Node*>::value_type actual = *(++getPath().begin());	// its a little ugly, but shouldnt matter
		std::list<Node*>::value_type next = *(++(++getPath().begin()));
		int deltaX1 = actX - actual->x;
		int deltaY1 = actY - actual->y;
		int deltaX2 = actual->x - next->x;
		int deltaY2 = actual->y - next->y;
		int tmp = abs(deltaX1 * deltaX2) + abs(deltaY1 * deltaY2);
		if (tmp == 1)   { //actual position and next two fields are not "in a line"
			int a = 0;
			if (!Ingame::fields[actual->x][actual->y].blocked()) {
				int x = actual->x;
				int y = actual->y;
				this->path.pop_front();
				this->path.push_front(new Node(x, y, 0,0));
			}
		}
	}
}

/* 
 *
 * returns a list of nodes from original position to destination
 * does a maximum of 50 steps every ????
 */
void Pathfinding::findPath(int orX, int orY) {
	if (atDestination(desX, desY, getNextField()))		// unit has reached its destination
		return;
	Node* actual = new Node(orX, orY, 0,0);
	if (actual == 0) // dont know why but sometimes actual isnt created, so this is checked to avoid errors
		return;
	std::list<Node*> openList;
	std::list<Node*> closedList;
	int x;
	int y;
	int counter = 0;
	openList.push_front(actual);
	while (openList.size() != 0 && (abs(actual->x - desX) >= 1|| abs(actual->y-desY)>= 1) && counter < 100) { // openlist not empty and not at destinaton
		if (finalFieldOnList(openList))
			break;;
		x = actual->x;
		y = actual->y;
		closedList.push_back(actual);
		openList.remove(actual);
		if (y < Options::iNumberEdgesY - 1) { // upper field
				Node* n = new Node(x, y+1, actual->costs + Ingame::fields[x][ y+1].getCosts() * 2, actual);
				if (!onList(closedList, n) && !onList(openList, n))
					openList.push_back(n);
			
			if (x > 0) {							//upperleft
				Node* n = new Node(x-1, y+1, actual->costs + Ingame::fields[x-1][ y+1].getCosts() * 3, actual);
				if (!onList(closedList, n) && !onList(openList, n))
					openList.push_back(n);
			}
			
		}
		if (y > 0) {
			Node* n = new Node(x, y-1, actual->costs + Ingame::fields[x][ y-1].getCosts() * 2, actual);
			if (!onList(closedList, n) && !onList(openList, n))
				openList.push_back(n);
			
			if (x < Options::iNumberEdgesX - 1)  {//upperright field
					Node* n = new Node(x+1, y-1, actual->costs + Ingame::fields[x+1][ y-1].getCosts()*3, actual);
				if (!onList(closedList, n) && !onList(openList, n))
					openList.push_back(n);
			}
			if (x > 0) {							//upperleft
				Node* n = new Node(x-1, y-1, actual->costs + Ingame::fields[x-1][ y-1].getCosts() * 3, actual);
				if (!onList(closedList, n) && !onList(openList, n))
					openList.push_back(n);
			}
			
		}
		if (x < Options::iNumberEdgesX - 1 && y < Options::iNumberEdgesY - 1)  {//upperright field // this is supposed to be not in upper if (else units would cross their way)
				Node* n = new Node(x+1, y+1, actual->costs + (Ingame::fields[x+1][ y+1].getCosts()) *3, actual);
				if (!onList(closedList, n) && !onList(openList, n))
					openList.push_back(n);
			}
		
		if (x > 0) {

				Node* n = new Node(x-1, y, actual->costs + Ingame::fields[x-1][ y].getCosts()*2, actual);
				if (!onList(closedList, n) && !onList(openList, n))
					openList.push_back(n);
			}
		if (x < Options::iNumberEdgesX) { 
				Node* n = new Node(x+1, y, actual->costs + Ingame::fields[x+1][ y].getCosts()*2, actual);
				if (!onList(closedList, n) && !onList(openList, n))
					openList.push_back(n);
			}
		actual = findLowestCosts(openList, desX, desY);
		counter++; 

	}
	this->path = giveOutResult(actual, orX, orY);
	//std::list<Node*>::iterator i;
	//openList.erase(findNode(openList, actual, i));
	//deleteFromList(openList, actual);
	//Node* res = giveOutResult(actual, orX, orY);
	//if (abs(actual->x - desX) <=0.05 && abs(actual->y-desY)>0.05) { //path is found
	openList.clear();
	closedList.clear();
	//}
	
}

void Pathfinding::setDestination(int x, int y) {
	desX = x;
	desY = y;
}

void Pathfinding::nextField() {
	path.pop_front();
}


 void findFreePlace(int& x, int& y){
	//TODO
	
}