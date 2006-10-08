/////////////////////////////////////////////////////////////////
//
//					
//					field.cpp
//					Field class
//					
//
/////////////////////////////////////////////////////////////////

#include "field.h"
#include "gra_ingame.h"
/*
 *
 * calculated type of field(needed display lists)
 *
 */
void Field::calcType() {
	if		(this->lt->getHeigth() == this->rt->getHeigth() && 
			 this->lt->getHeigth() == this->rb->getHeigth() && 
			 this->lt->getHeigth() == this->lb->getHeigth()) 
			 this->type = (this->rb->getHeigth() == 0)?FIELD_WATER:FIELD_PLAIN;
	int heigth[4];
	heigth[0] = this->lt->getHeigth();
	heigth[1] = this->rt->getHeigth();
	heigth[2] = this->rb->getHeigth();
	heigth[3] = this->lb->getHeigth();
	if ((heigth[0] < heigth[1]) && (heigth[2] < heigth[1]) && (heigth[3] < heigth[1]))		
		this->type = FIELD_GRAD1;
	else if (heigth[0] < heigth[1] && heigth[3] < heigth[1] && heigth[2] == heigth[1]) 
		this->type = FIELD_GRAD2;
	else if (heigth[0] < heigth[2] && heigth[1] < heigth[2] && heigth[3] < heigth[2]) {
		this->type = FIELD_GRAD3;
	}
	else if (heigth[0] < heigth[2] && heigth[1] < heigth[2] && heigth[2] == heigth[3])
		this->type = FIELD_GRAD4;
	

	else if (heigth[0] < heigth[3] && heigth[1] < heigth[3] && heigth[2] < heigth[3]) 
		this->type = FIELD_GRAD5;
	else if (heigth[1] < heigth[0] && heigth[2] < heigth[0] && heigth[3] == heigth[0]) 
		this->type = FIELD_GRAD6;
	else if (heigth[1] < heigth[0] && heigth[2] < heigth[0] && heigth[3] < heigth[0]) 
		this->type = FIELD_GRAD7;
	else if (heigth[2] < heigth[0] && heigth[3] < heigth[0] && heigth[1] == heigth[0]) 
		this->type = FIELD_GRAD8;
	else if (heigth[0] < heigth[1] && heigth[2] < heigth[1] && heigth[1] == heigth[3])
		this->type = FIELD_GRAD9;
	else if (heigth[1] < heigth[0] && heigth[3] < heigth[0] && heigth[2] == heigth[0])
		this->type = FIELD_GRAD10;
	else if (heigth[0] < heigth[1] && heigth[0] < heigth[2] && heigth[0] < heigth[3]) 
		this->type = FIELD_GRAD11;
	else if (heigth[1] < heigth[0] && heigth[1] < heigth[2] && heigth[1] < heigth[3]) 
		this->type = FIELD_GRAD12;
	else if (heigth[2] < heigth[0] && heigth[2] < heigth[1] && heigth[2] < heigth[3]) 	
		this->type = FIELD_GRAD13;
	else if (heigth[3] < heigth[0] && heigth[3] < heigth[1] && heigth[3] < heigth[2])
		this->type = FIELD_GRAD14;
	if (this->type == FIELD_WATER)
		this->costs = 1048576;
	else if (this->type == FIELD_PLAIN)
		this->costs = 10;
	else this->costs = 20;
}