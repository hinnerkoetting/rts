/////////////////////////////////////////////////////////////////
//
//					
//					field
//					Field class
//					
//
/////////////////////////////////////////////////////////////////
#ifndef DEF_INCLUDEField_H
#define DEF_INCLUDEField_H
#include "edge.h"

class Field {
	public:
		Field() { lt = 0; rt = 0; lb = 0; rb = 0; left = 0; rigth = 0; top = 0; bottom = 0; type = -1; properties = -1; }
		Edge* lt;		// edge at left top
		Edge* rt;		// right top
		Edge* lb;		// left bottom
		Edge* rb;		// right bottom
		Field* left;
		Field* rigth;
		Field* top;
		Field* bottom;
		void calcType();
		int type;		// water, field plane...
	private:
		
		int properties;
};
#endif