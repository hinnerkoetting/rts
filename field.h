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
#define MAX_FIELDS_X 512
#define MAX_FIELDS_Y 512
#include "edge.h"

class Field {
	public:
		Edge* lt;		// edge at left top
		Edge* rt;		// right top
		Edge* lb;		// left bottom
		Edge* rb;		// right bottom
		Field() { properties = -1; lt = 0; rt = 0; lb = 0; rb = 0;}
		void calcType();
		int type;		// water, field plane...
	private:
		int properties;
};
#endif