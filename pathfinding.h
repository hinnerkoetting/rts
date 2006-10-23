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
#include <list>
#ifndef PATHFINDING_H_DEF
#define PATHFINDING_H_DEF
class Node { // divide world into grid for pathfinding
	public:
		int x;
		int y;
		int costs; 
		int approxCosts;
		Node* parent;
		Node(int xPos, int yPos, int c, Node* p) { x = xPos; y = yPos; costs = c; parent = p; approxCosts = 0; }
};


class Pathfinding {
	private:
		
		bool onList(std::list<Node*> list, Node* node);
		Node* Pathfinding::findLowestCosts(std::list<Node*> list, int desX, int desY);
		std::list<Node*> giveOutResult(Node*, int orX, int orY);
		
		
		bool atDestination(int x, int y, Node*);
	
	public:
		int desX;
		int desY;


		std::list<Node*> getPath() { return path; }
		std::list<Node*> path;
		void nextField();
		Node* getNextField() { std::list<Node*>::value_type tmp = *path.begin(); return tmp; }
		void initPath(int x, int y) { path.clear(); 
		path.push_front(new Node(x, y, 0,0)); 
		desX = x; desY = y; }
		void findPath(int fromX, int fromY);
		
		
		void setDestination(int x, int y);
		Pathfinding(int x, int y) {desX = x; desY = y; }
		
};
#endif