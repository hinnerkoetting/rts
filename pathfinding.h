/////////////////////////////////////////////////////////////////
//
//					
//					pathfinding.h
//					
//					
//
/////////////////////////////////////////////////////////////////

#include "field.h"
#include "options.h"
#ifndef PATHFINDING_H_DEF
#define PATHFINDING_H_DEF
class Node { // divide world into grid for pathfinding
	public:
		int x;
		int y;
		int costs;
		Node* next; 
		Node* parent;
		Node(int xPos, int yPos, int c, Node* p) { x = xPos; y = yPos; costs = c; parent = p; next = 0;}
};


class Pathfinding {
	private:
		Node* openList;
		Node* closedList;
		void clearLists();
		Node* addToList(Node* list, Node* node);
		Node* deleteFromList(Node* list, Node* node);
		
		bool onList(Node* list, Node* node);
		Node* Pathfinding::findLowestCosts(Node* list, int desX, int desY);
		Node* giveOutResult(Node*, float orX, float orY);
		int desX;
		int desY;
		
		bool atDestination(float x, float y, Node*);
		Node* actual;
	public:
		Node* path;
		void nextField();
		Node* getPath() { return path; }
		Node* deleteList(Node* list);
		void findPath(float fromX, float fromY);
		void setDestination(int x, int y);
		Pathfinding(int x, int y) {openList = 0; closedList = 0; desX = x; desY = y; path = 0;}
		void initPath(int x, int y) { actual = new Node(x, y, 0,0); path = actual; openList = actual; desX = x; desY = y; closedList = 0; }
};
#endif