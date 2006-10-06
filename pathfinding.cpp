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
//Node* Pathfinding::openList = 0;
//Node* Pathfinding::closedList = 0;
/*
 *
 * resets open and closed list
 *
 */
void Pathfinding::clearLists() {
	Node* lpNode1 = openList;
	Node* lpNode2;
	while (lpNode1 != 0) {
		lpNode2 = lpNode1->next;
		delete lpNode1;
		lpNode1 = lpNode2;
	}
	lpNode1 = closedList;
	while (lpNode1 != 0) {
		lpNode2 = lpNode1->next;
		delete lpNode1;
		lpNode1 = lpNode2;
	}
	
}

/* 
 *
 * adds a note to a list
 * TODO: in closed list new nodes dont need to be created at end of the list
 */
Node* Pathfinding::addToList(Node* list, Node* node) {
	Node* tmp = new Node(node->x, node->y, node->costs, node->parent);
	if (list != 0) {
		tmp->next = list->next;
		list->next = tmp;
	}
	else
		list = tmp;
	return list;
}

/*
 *
 * deletes a node from a list
 *
 */
Node* Pathfinding::deleteFromList(Node* list, Node* node) {
	if (list == 0)
		return 0;
	if (list== node) 
		return list->next;
	Node* lpNode = list;
	while (lpNode->next != node && lpNode->next != 0) {
		lpNode = lpNode->next;
	}
	if (lpNode->next == 0)
		return list;
	Node* help = lpNode->next->next;
	//delete (lpNode->next);
	lpNode->next = help;
	return list;
}

Node* Pathfinding::deleteList(Node* list) {
	Node* lpNode = list;
	while (list != 0 && lpNode->next != 0) {
		lpNode = lpNode->next;
		delete(list);
		list = lpNode;
	}
	return 0;
}
/*
 *
 * check if a node is on a list
 *
 */
bool Pathfinding::onList(Node* list, Node* node) {
	Node* lpNode = list;
	while (lpNode != 0) {
		if (lpNode->x == node->x && lpNode->y == node->y)
			return true;
		lpNode = lpNode->next;
	}
	return false;
}
/*int abs(int x) {
	if (x >= 0)
		return x;
	return -x;
}*/
/*
 *
 * looks for node with estimated lowest costs to destination
 *
 */
Node* Pathfinding::findLowestCosts(Node* list, int desX, int desY) { 
	Node* lpNode = list;
	Node* resNode = list;
	int lowestCosts = 99999;
	while (lpNode != 0){
		int costs = lpNode->costs + abs(desX - lpNode->x) * 100 + abs(desY - lpNode->y) * 100; // approx costs
		if (costs < lowestCosts) {
			resNode = lpNode;
			lowestCosts = costs;
		}
		lpNode = lpNode->next;
	}
	return resNode;
}
/* 
 * list is in wrong direction and needs to be copied so its not deleted later
 * due to the fact, that the unit may moving while its given another moveorder there is the following problem: the unit moves at first to the field nearest to its actual position
 * and then moves the right way. so it can happen that the first field is wrong direction, this is here corrected 
 */
Node* Pathfinding::giveOutResult(Node* n, float orX, float orY) {
	Node* res;
	if (n != 0) {
		 res = new Node(n->x, n->y, n->costs, 0); //change direction
		Node* tmp = res;
		while (n->parent != 0) {
			Node* temp = n;
			n = n->parent;
			temp->parent = 0;
			tmp = new Node(n->x, n->y, n->costs, 0);
			tmp->next = res;
			res = tmp;
		}
	}
	else 
		return new Node(orX, orY, 0, 0);
	if (res->next != 0)
		if (((orX - res->x) * (orX - res->next->x) < 0) || ((orY - res->y) * (orY - res->next->y)) < 0)	//first field is whrong direction
		{
			Node* tmp = res;
			res =res->next;
			res->parent = 0;
			delete(tmp);
		}
	return res;
	
}

/* 
 *
 * checks if unit has reached a field
 *
 */
bool Pathfinding::atDestination(float x, float y, Node* n) {
	if (abs(n->x - x) <=0.05 && abs(n->y - y) <= 0.05)
		return true;
	return false;
}
/* 
 *
 * returns a list of nodes from original position to destination
 * does a maximum of 50 steps every ????
 */
void Pathfinding::findPath(float orX, float orY) {
	if (atDestination(orX, orY, path) && path->next != 0) {	//unit has reached next field 
		Node* tmp = path;
		path = path->next;
		delete tmp;
	}
	if (atDestination(desX, desY, path))		// unit has reached its destination
		return;
	int x;
	int y;
	int counter = 0;
	while (openList != 0 && (abs(actual->x - desX) >0.05|| abs(actual->y-desY)>0.05) && counter < 50) { // openlist not empty and not at destinaton
		
		x = actual->x;
		y = actual->y;
		closedList = addToList(closedList, actual);
		openList = deleteFromList(openList, actual);
		if (y < Options::iNumberEdgesY - 1) { // upper field
			//if(Ingame::fields[x][y+1].type != 1) {// no water field 
				Node* n = new Node(x, y+1, actual->costs + Ingame::fields[x, y+1]->getCosts() * 2, actual);
				if (!onList(closedList, n) && !onList(openList, n))
					openList = addToList(openList, n);
			
			if (x < Options::iNumberEdgesX - 1)  {//upperright field
			//	if(Ingame::fields[x+1][y+1].type != 1) {// no water field 
				Node* n = new Node(x+1, y+1, actual->costs + (Ingame::fields[x+1, y+1]->getCosts()) *3, actual);
				if (!onList(closedList, n) && !onList(openList, n))
					openList = addToList(openList, n);
			}
			if (x > 0) {							//upperleft
			//	if(Ingame::fields[x-1][y+1].type != 1) {// no water field 
				Node* n = new Node(x-1, y+1, actual->costs + Ingame::fields[x-1, y+1]->getCosts() * 3, actual);
				if (!onList(closedList, n) && !onList(openList, n))
					openList = addToList(openList, n);
			}
		}
		if (y > 0) {
			Node* n = new Node(x, y-1, actual->costs + Ingame::fields[x, y-1]->getCosts() * 2, actual);
			if (!onList(closedList, n) && !onList(openList, n))
				openList = addToList(openList, n);
			
			if (x < Options::iNumberEdgesX - 1)  {//upperright field
					Node* n = new Node(x+1, y-1, actual->costs + Ingame::fields[x+1, y-1]->getCosts()*3, actual);
				if (!onList(closedList, n) && !onList(openList, n))
					openList = addToList(openList, n);
			}
			if (x > 0) {							//upperleft
				Node* n = new Node(x-1, y-1, actual->costs + Ingame::fields[x-1, y-1]->getCosts() * 3, actual);
				if (!onList(closedList, n) && !onList(openList, n))
					openList = addToList(openList, n);
			}
		}
		
		if (x > 0) {

				Node* n = new Node(x-1, y, actual->costs + Ingame::fields[x-1, y]->getCosts()*2, actual);
				if (!onList(closedList, n) && !onList(openList, n))
					openList = addToList(openList, n);
			}
		if (x < Options::iNumberEdgesX) { 
				Node* n = new Node(x+1, y, actual->costs + Ingame::fields[x+1, y]->getCosts()*2, actual);
				if (!onList(closedList, n) && !onList(openList, n))
					openList = addToList(openList, n);
			}
		actual = findLowestCosts(openList, desX, desY);
		counter++; //wenn ich eins rausgelöscht hab aus der acutal list rauslöschen!!!!!!!!!!!

	}
	this->path = giveOutResult(actual, orX, orY);
	openList = deleteFromList(openList, actual);
	//deleteFromList(openList, actual);
	//Node* res = giveOutResult(actual, orX, orY);
	//if (abs(actual->x - desX) <=0.05 && abs(actual->y-desY)>0.05) { //path is found
		openList = deleteList(openList);
		closedList = deleteList(closedList);
	//}
	
}

void Pathfinding::setDestination(int x, int y) {
	desX = x;
	desY = y;
}

void Pathfinding::nextField() {
	Node* tmp = path;
	path = path->next;
	delete(tmp);
	tmp = actual;
	if (tmp != 0)
		if (tmp->parent != 0) {
			while (tmp->parent->parent != 0)
				tmp = tmp->parent;
			tmp->parent = 0;
		}
}
