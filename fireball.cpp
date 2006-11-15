/////////////////////////////////////////////////////////////////
//
//					
//					fireball.cpp
//					
//					
//
/////////////////////////////////////////////////////////////////

#include "fireball.h"
#include "spells.h"
#include "point.h"

#include <cmath>
#include <math.h>
#include "gameViewAndControl.h"
#include "settings.h"


/* 
 *
 * creates a fireball
 * TODO: rework
 */
bool Fireball::Create(Hero* Hero)
{ return true;}
	/*Fireball* lpFireball;
	 (Hero->lpNextFireball == 0)
	{
		
		lpFireball = new Fireball;
		Hero->lpNextFireball = lpFireball;
		lpFireball->lpNextFireball = 0;
	}
	else
	{
		lpFireball = new Fireball;
		lpFireball->lpNextFireball = Hero->lpNextFireball;
		Hero->lpNextFireball = lpFireball;
	}
	lpFireball->Parent = Hero;
	lpFireball->iTimeLived = 0;
	lpFireball->xPos = Hero->xPos;
	lpFireball->yPos = Hero->yPos;
	lpFireball->Direction.r = 0.8f;
	lpFireball->Direction.g	= 0.2f;
	lpFireball->Direction.b = 0.0f;
	float x = float(Hero->xPos - Map::PixelToEdge(true));
	float y = float(Hero->yPos - Map::PixelToEdge(false));
	lpFireball->Direction.x = float(x / sqrt(x * x + y * y))/4;
	lpFireball->Direction.y = float(y / sqrt(x * x + y * y))/4;
	lpFireball->Direction.z = 0.01f;
	return true;/*
}

/*
 *
 * draws a 'fireball'
 * TODO: rework
 */
void Fireball::Draw(Fireball* Fireball)
{
/*	if ((Fireball->xPos >= ViewAndControl::iCurXPos - 20) && (Fireball->xPos <= ViewAndControl::iCurXPos + 20)
		&& (Fireball->yPos >= ViewAndControl::iCurYPos - 20) && (Fireball->yPos <= ViewAndControl::iCurYPos + 20))
	{
		float x = float(0.2f + (Fireball->xPos - ViewAndControl::iCurXPos) /40 * 1.6);
		float y = (Fireball->yPos - ViewAndControl::iCurYPos) /20;
		Gra::g.DrawPixel(Point(x, y, Fireball->Direction.z, Fireball->Direction.r, Fireball->Direction.g, Fireball->Direction.b), 5.0f);
	}*/
}

/*
 *
 * moves a fireball
 * TODO: rewrite
 */
void Fireball::Move(Fireball* Fireball)
{
	/*Fireball->xPos -= Fireball->Direction.x;
	Fireball->yPos -= Fireball->Direction.y;
	if (Fireball->iTimeLived > Settings::FireballTimeToLive) // if fireball has lived to long, all values are set to 0; no 'clean' solution, but easy ;)
	{
		Fireball->lpNextFireball = 0;
		Fireball->xPos = 0;
		Fireball->yPos = 0;
		Fireball->Direction.x = 0.0f;
		Fireball->Direction.y	= 0.0f;
		Fireball->Direction.z = 0.0f;
		return;
	}
	Fireball->iTimeLived += 1;
	Unit* lpHero = ViewAndControl::Heroes;
	while (lpHero != 0)
	{
		if (!(lpHero == Fireball->Parent))
			if ((Fireball->xPos >= lpHero->getX() - 0.125f) && (Fireball->xPos <= lpHero->getX() + 0.125f) &&
				(Fireball->yPos >= lpHero->getY() - 0.25f ) && (Fireball->yPos <= lpHero->getY() + 0.25f ))
				{
					lpHero->changeHp(-Settings::FireballDamaga);
					Fireball->lpNextFireball = 0;
					Fireball->xPos = 0;
					Fireball->yPos = 0;
					Fireball->Direction.x = 0.0f;
					Fireball->Direction.y	= 0.0f;
					Fireball->Direction.z = 0.0f;
				}
		lpHero = lpHero->next;
	}*/

}