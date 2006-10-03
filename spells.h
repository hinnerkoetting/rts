/////////////////////////////////////////////////////////////////
//
//					
//					spells.h
//					spells a hero can cast
//					
//
/////////////////////////////////////////////////////////////////

#ifndef SPELLS_H_DEF
#define SPELLS_H_DEF



#include "field.h"
#include "edge.h"

namespace Spells {
	bool spIncrease();
	bool spDecrease();
	bool incField(Edge*, Field*);
	bool decField(Edge*, Field*);
}

#endif