
#include "errors.h"
#include "villageNameButton.h"
#include "graphic_interface.h"


VillageNameButton::VillageNameButton(float x1, float x2, float y1, float y2, Village* v){
	this->x1 = x1;
	this->x2 = x2;
	this->y1 = y1;
	this->y2 = y2;
//	this->relativeX = relX;
//a	this->relativeY = relY;
	this->v=v;

}
	
	void VillageNameButton::draw(){
		std::string vName=v->getName();
		GraphicInterface::drastring2d(x1,y1,v->getName());
	
	};


	void VillageNameButton::click(int button){
		Error::MesBoxOk("Click","Click");
	};

