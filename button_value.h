/////////////////////////////////////////////////////////////////
//
//					
//					button_value.h
//					button class with extra value
//					
//
/////////////////////////////////////////////////////////////////

#include "menu_button.h"

class ButtonValue : public MenuButton {
	private:
		float relativeX;  //position of value relative to original x position
		float relativeY;
		void drawBorders();
		
	public:
		ButtonValue(float x1, float x2, float y1, float y2, float relX, float relY, void (*f)(int, MenuButton*), int id);
		void draw();
		static void changeValue(int x, MenuButton*); //(value,pointer to itself)
		static void click(int button, MenuButton*); //(button,pointer to itself)
		
};