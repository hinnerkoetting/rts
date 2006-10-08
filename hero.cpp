/////////////////////////////////////////////////////////////////
//
//					
//					hero.cpp
//					class hero
//					
//
/////////////////////////////////////////////////////////////////

#include "hero.h"
#include "errors.h"
#include "ingame.h"
#include "settings.h"
#include "graphic.h"
#include "gra_ingame.h"
/*
 *
 * draws the hero
 * TODO: rework
 */
void Hero::draw() {
	//Graphic::drawLine3D(Point(this->xPos * GraIngame::getLength(), this->yPos * GraIngame::getHeigth(), 0.0f, 1.0f, 1.0f, 1.0f),
	//					Point((this->xPos + 1 )* GraIngame::getLength(), this->yPos * GraIngame::getHeigth(), 0.0f, 1.0f, 1.0f, 1.0f));
	/*
	if ((xPos >= Ingame::iCurXPos - 20) && (xPos <= Ingame::iCurXPos + 20)
		&& (yPos >= Ingame::iCurYPos - 20) && (yPos <= Ingame::iCurYPos + 20))
	{
		float x = float(0.2f + (xPos - Ingame::iCurXPos) /40 * 1.6);
		float y = (yPos - Ingame::iCurYPos) /20;*/
		/*Gra::g.DrawQuad(	Point(x + 0.01f	, y + 0.02f	, 0.02f, 1.0f),
							Point(x + 0.01f	, y	- 0.02f	, 0.02f, 1.0f),
							Point(x - 0.01f	, y	- 0.02f	, 0.02f, 1.0f),
							Point(x - 0.01f	, y + 0.02f	, 0.02f, 1.0f));*/
	//}
	//Unit* u;
}


/*
 *
 * sets Hero to default values
 * TODO: rework
 */
void Hero::clearHero()
{
	//xPos = 0.0f;
	//yPos = 0.0f;
	//fMana = Settings::HeroMana;
	//lpNextFireball = 0;
}
