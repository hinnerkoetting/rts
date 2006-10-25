/////////////////////////////////////////////////////////////////
//
//					
//					button_value_inc.h
//					button class with extra value which can be in/de-creased by click
//					
//
/////////////////////////////////////////////////////////////////

#include "button_value.h"

class ButtonValueInc : public ButtonValue {
	private:
		void (*inc)(int party, int village, int number);

	public:
		ButtonValueInc(float x1, float x2, float y1, float y2, float relX, float relY, int id, int (*get)(int, int),void (*inc)(int, int, int), int party = 0, int village= 0);
		void draw();
		void click(int button);
		
};