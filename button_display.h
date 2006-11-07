/////////////////////////////////////////////////////////////////
//
//					
//					button_display.h
//					button class with extra numeric value
//					number is read from ButtonHandlerInterface
//
/////////////////////////////////////////////////////////////////

#ifndef BUTTON_VALUE_H_DEF
#define BUTTON_VALUE_H_DEF
#include "menu_button.h"
#include "game_object.h"






class ButtonValueReader abstract{
	public:
		virtual int getDisplayButtonValue(GameObject::gameObject_ID)=0;
};


class ButtonDisplay : public MenuButton {
	protected:
		ButtonDisplay() {}
		float relativeX;  //position of value relative to original x position
		float relativeY;
		GameObject::gameObject_ID displayID;

		void drawBorders(); //draws a quad around image + value
		int village;		// id of village
		int party;			// id of party
		int (*get)(int, int);	// get value of this button
		ButtonValueReader* handler;

	public:
		//obsolete
	//	ButtonDisplay(float x1, float x2, float y1, float y2, float relX, float relY, int id, int (*get)(int, int), int party, int village);	
		ButtonDisplay(float x1, float x2, float y1, float y2, float relX, float relY, int id, ButtonValueReader* handler, GameObject::gameObject_ID dID);	

		//draws the button (OPENGL)
		virtual void draw();

		//obsolete
		virtual void click(int button);

		//obsolete
		int getValue() { return get(village, party); }//if wish and current, wished values

};


/*
 *  Interface for reading display Value
 */



#endif


