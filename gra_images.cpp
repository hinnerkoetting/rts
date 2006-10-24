/////////////////////////////////////////////////////////////////
//
//					
//					gra_images.cpp
//					
//					
//
/////////////////////////////////////////////////////////////////

#include "gra_ingame.h"
#include "graphic.h"
#include "devil/include/IL/ilut.h"
#include "hero.h"
#include "worker.h"
#include "defines.h"
void GraIngame::loadImages() {
	ilInit();
	Graphic::bindImage();
	ilutRenderer(ILUT_OPENGL);
	Graphic::loadImage("data/att.gif",BUTTON_ATTACK_ID);
	Graphic::loadImage("data/house.gif", BUTTON_HOUSE_ID);
	Graphic::loadImage("data/worker2.gif", WORKER_ID);
	Graphic::loadImage("data/goldmine.bmp", GOLDMINE_ID);
	Graphic::loadImage("data/village.jpg", VILLAGE_ID);
	Graphic::loadImage("data/headquarter.gif", HEADQUARTER_ID);
}