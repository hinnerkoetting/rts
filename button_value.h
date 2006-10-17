/////////////////////////////////////////////////////////////////
//
//					
//					button_value.h
//					button class with extra value
//					
//
/////////////////////////////////////////////////////////////////

#include "menu_button.h"

class ButtonValue : MenuButton {
	private:
		int value;
		int relativeX;  //position of value relative to original x position
		int relativey;
	public:
		ButtonValue(int x1, int x2, int y1, int y2, int relX, int relY, void (*f)(int));
		void draw();
};