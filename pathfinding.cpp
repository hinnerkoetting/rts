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

Node* Pathfinding::openList = 0;
Node* Pathfinding::closedList = 0;
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
	if (list != 0) {
		node->next = list->next;
		list = node;
	}
	else
		list = node;
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
	Node* lpNode = list;//????
	while (lpNode->next != node && lpNode->next != 0) {
		lpNode = lpNode->next;
	}
	if (lpNode->next == 0)
		return list;
	Node* help = lpNode->next->next;
	delete lpNode->next;
	lpNode->next = help;
	return list;
}

/*
 *
 * check if ad node is on a list
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
		int costs = lpNode->costs + abs(desX - lpNode->x) * 10 + abs(desY - lpNode->y) * 10;
		if (lowestCosts > costs) {
			resNode = lpNode;
			lowestCosts = costs;
		}
		lpNode = lpNode->next;
	}
	return resNode;
}
/* 
 *
 * returns list of nodes from given origin and destination
 * TODO free pointers
 */
Node* Pathfinding::findPath(float orX, float orY, float desX, float desY) {
	Field* lpField = Ingame::firstField;
	for(int i = 0; i < orX; i++) 
		lpField = lpField->rigth;
	for(int i =0; i < orY; i++)
		lpField = lpField->top;
	Node* actual = new Node(orX, orY, 0, 0);
	openList = addToList(openList, actual);
	while (openList != 0 && (actual->x != desX || actual->y != desY) ) { // openlist not empty and not at destinaton
		closedList = addToList(closedList, actual);
		openList = deleteFromList(openList, actual);
		if (lpField->top != 0)
			if(lpField->top->type != 1) {// water field 
				Node* n = new Node(orX+1, orY, actual->costs +10, actual);
				if (!onList(closedList, n))
					openList = addToList(openList, n);
			}
		actual = findLowestCosts(openList, desX, desY);
	}
	return openList;
}