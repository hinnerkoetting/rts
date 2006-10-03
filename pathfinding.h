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
		Node(int xPos, int yPos, int c, Node* p) { x = xPos; y = yPos; costs = c; parent = p; }
};


class Pathfinding {
	private:
		static Node* openList;
		static Node* closedList;
		static void clearLists();
		static Node* addToList(Node* list, Node* node);
		static Node* deleteFromList(Node* list, Node* node);
		static bool onList(Node* list, Node* node);
		static Node* Pathfinding::findLowestCosts(Node* list, int desX, int desY);
	public:
		static Node* findPath(float fromX, float fromY, float desX, float desY);
};
#endif