/////////////////////////////////////////////////////////////////
//
//					
//					settings.cpp
//					game settings
//					
//
/////////////////////////////////////////////////////////////////

#include "settings.h"

#include "gl/glut.h"

namespace Settings
{
	char* lpchProgName = "Multi";
	float HeroHealth = 10.0f;
	float HeroMana = 10.0f;
	float fSizeFireball = 2.0f;
	int FireballTimeToLive = 100;
	float FireballDamaga = 1.0f;
	const char cchVersionNumber[8] = "0.0.0.1";
}

/*
 *
 * returns intervall how long a key should be locked
 *
 */
short Settings::RepeatLock(int iNumber)
{
	switch(iNumber)
	{
		case 'W':
				return 1;
		case 'A':
				return 1;
		case 'S':
				return 1;
		case 'D':
				return 1;
		case ' ':
				return 10;
		case GLUT_KEY_LEFT:
				return 1;
		case GLUT_KEY_RIGHT:
				return 1;		
		case GLUT_KEY_UP:
				return 1;		
		case GLUT_KEY_DOWN:
				return 1;
		case '+':
			return 5;
		case '-':
			return 5;
		case GLUT_LEFT_BUTTON+260:			//mouse1
				return 10;
		case GLUT_RIGHT_BUTTON+260:			//mouse2
				return 10;
		default:
				return 0;
	}
}