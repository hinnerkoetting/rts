

#ifndef VILLAGENAME_DEF_H
#define VILLAGENAME_DEF_H


#include "village.h"

#include "menu_button.h"






class VillageNameButton:public MenuButton{
	Village* v;

public:
    VillageNameButton(float x1, float x2, float y1, float y2, Village* v);	
	Village* getVillage(){ return v;};
	
	void draw();

};


#endif