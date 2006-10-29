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
		static void deletePointer(std::list<Node*>*);
};

/*
 * calculates a list of Nodes giving a path from origin to destination
 * based on A* algorithm. Short: from actual position, all neigbour fiels are added to an open list
 * then the field with estimated lowest costs it set as new actual position. that loop
 * break when a field next to destination is found. if that field is blocked, the unit
 * moves till that field else it moves to destination field. This algo. is stopped after a constant number of tries
 * so the game doesn't freeze if a path is very long
 * This algorithm doesn't necessarily find the shortest path. If a path is found is stops immediately to
 * save CPU cycles
 * 
 * When a path is found there may be units which block another faster path so it's important
 * when a unit reaches a field to check next two fields for barriers
 * so the unit doesn't make a silly "dodge" movement but there isn't anymore a barrier
 */
class Pathfinding {
	private:
		
		bool onList(std::list<Node*> list, Node* node);
		Node* Pathfinding::findLowestCosts(std::list<Node*> list, int desX, int desY);
		std::list<Node*> giveOutResult(Node*, int orX, int orY);
		
		
		bool atDestination(int x, int y, Node*);
		std::list<Node*> path;
		int desX;
		int desY;
	public:
		int getDesX() { return desX; }
		int getDesY() { return desY; }

		void checkPath(int actualX, int actualY);
		std::list<Node*> getPath() { return path; }
		void nextField();
		Node* getNextField() { std::list<Node*>::value_type tmp = *path.begin(); return tmp; }
		void initPath(int x, int y) { path.clear(); path.push_front(new Node(x, y, 0,0)); desX = x; desY = y; }
		void findPath(int fromX, int fromY);

		
		
		
		void setDestination(int x, int y);
		Pathfinding(int x, int y) {desX = x; desY = y; }
		
};
#endif


//finds free position near defined position
		//x: INOUT x in:X-Position, where to find. out:X-where free
		//y: INOUT y in:Y-Position, where to find. out:Y-where free
		void findFreePlace(int& x, int& y);
