/////////////////////////////////////////////////////////////////
//
//					
//					Edge.h
//					
//					
//
/////////////////////////////////////////////////////////////////
#ifndef DEF_INCLUDEEdge_H
#define DEF_INCLUDEEdge_H
#include "field.h"

class Edge {
	public:
		Edge(int h = 0) { heigth = h;}
		void inc() { heigth++; }
		void dec() { heigth--; }
		int	getHeigth() { return heigth; }
	private:
		int heigth;
};
#endif