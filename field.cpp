/////////////////////////////////////////////////////////////////
//
//					
//					field.cpp
//					Field class
//					
//
/////////////////////////////////////////////////////////////////

#include "field.h"
/*
 *
 * calculated type of field(needed display lists)
 *
 */
void Field::calcType() {
	if		(this->lt->getHeigth() == this->rt->getHeigth() && 
			 this->lt->getHeigth() == this->rb->getHeigth() && 
			 this->lt->getHeigth() == this->lb->getHeigth()) 
			 this->type = (this->rb->getHeigth() == 0)?1:2;
	int heigth[4];
	heigth[0] = this->lt->getHeigth();
	heigth[1] = this->rt->getHeigth();
	heigth[2] = this->rb->getHeigth();
	heigth[3] = this->lb->getHeigth();
	if ((heigth[0] < heigth[1]) && (heigth[2] < heigth[1]) && (heigth[3] < heigth[1]))		
		this->type = 3;
	else if (heigth[0] < heigth[1] && heigth[3] < heigth[1] && heigth[2] == heigth[1]) 
		this->type = 4;
	else if (heigth[0] < heigth[2] && heigth[1] < heigth[2] && heigth[3] < heigth[2]) {
		this->type = 5;
	}
	else if (heigth[0] < heigth[2] && heigth[1] < heigth[2] && heigth[2] == heigth[3])
		this->type = 6;
	

	else if (heigth[0] < heigth[3] && heigth[1] < heigth[3] && heigth[2] < heigth[3]) 
		this->type = 7;
	else if (heigth[1] < heigth[0] && heigth[2] < heigth[0] && heigth[3] == heigth[0]) 
		this->type = 8;
	else if (heigth[1] < heigth[0] && heigth[2] < heigth[0] && heigth[3] < heigth[0]) 
		this->type = 9;
	else if (heigth[2] < heigth[0] && heigth[3] < heigth[0] && heigth[1] == heigth[0]) 
		this->type = 10;
	else if (heigth[0] < heigth[1] && heigth[2] < heigth[1] && heigth[1] == heigth[3])
		this->type = 11;
	else if (heigth[1] < heigth[0] && heigth[3] < heigth[0] && heigth[2] == heigth[0])
		this->type = 12;
	else if (heigth[0] < heigth[1] && heigth[0] < heigth[2] && heigth[0] < heigth[3]) 
		this->type = 13;
	else if (heigth[1] < heigth[0] && heigth[1] < heigth[2] && heigth[1] < heigth[3]) 
		this->type = 14;
	else if (heigth[2] < heigth[0] && heigth[2] < heigth[1] && heigth[2] < heigth[3]) 	
		this->type = 15;
	else if (heigth[3] < heigth[0] && heigth[3] < heigth[1] && heigth[3] < heigth[2])
		this->type = 16;
	if (this->type == 1)
		this->costs = 99999;
	else if (this->type == 2)
		this->costs = 10;
	else this->costs = 20;
}