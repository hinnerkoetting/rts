/////////////////////////////////////////////////////////////////
//
//					
//					fireball.h
//					
//					
//
/////////////////////////////////////////////////////////////////

#include "hero.h"
#include "point.h"

class Fireball
{
	public:
		float xPos;
		float yPos;
		Point Direction;
		int iTimeLived;
		Hero* Parent;

		Fireball* lpNextFireball;
		static bool Create(Hero*);
		void Draw(Fireball*);
		void Move(Fireball*);
};