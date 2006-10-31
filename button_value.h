/////////////////////////////////////////////////////////////////
//
//					
//					button_value.h
//					button class with extra value
//					
//
/////////////////////////////////////////////////////////////////

#ifndef BUTTON_VALUE_H_DEF
#define BUTTON_VALUE_H_DEF
#include "menu_button.h"

class ButtonValue : public MenuButton {
	protected:
		ButtonValue() {}
		float relativeX;  //position of value relative to original x position
		float relativeY;
		void drawBorders(); //draws a quad around image + value
		int village;		// id of village
		int party;			// id of party
		int (*get)(int, int);	// get value of this button
	public:
		ButtonValue(float x1, float x2, float y1, float y2, float relX, float relY, int id, int (*get)(int, int), int party, int village);	
		virtual void draw();
		virtual void click(int button);
		int getValue() { return get(village, party); }//if wish and current, wished values

};
#endif