/////////////////////////////////////////////////////////////////
//
//					
//					button_change.h
//					button class with extra value which can be in/de-creased by click
//					
//
/////////////////////////////////////////////////////////////////

#ifndef BUTTON_CHANGE_H_DEF
#define BUTTON_CHANGE_H_DEF
#include "menu_button.h"

#include "button_display.h"
#include "game_object.h"





class ButtonValueChangerHandler abstract{


	public:
		virtual int getCurrentValue(GameObject::gameObject_ID ch_id)=0;
		virtual int getWishedValue(GameObject::gameObject_ID ch_id)=0;
		virtual void changeValue(GameObject::gameObject_ID, int change)=0;
};


class ButtonChangeValue : public ButtonDisplay {

	private:

		
		void (*inc)(int party, int village, int number); //increase item
		int (*getCurrent)(int, int);	// get value of item
		ButtonValueChangerHandler* handler;
		GameObject::gameObject_ID changeID;

	public:
	//	ButtonChangeValue(float x1, float x2, float y1, float y2, float relX, float relY, int id, int (*getWish)(int, int),int (*getCurrent)(int,int), void (*inc)(int, int, int), int party = 0, int village= 0);
		ButtonChangeValue(float x1, float x2, float y1, float y2, float relX, float relY, int id, ButtonValueChangerHandler* handler, GameObject::gameObject_ID ch_ID);
		virtual void draw();


		void click(int button);

		//obsolet	
		int getCurrentValue() { return getCurrent(village, party); }

			
		
		
};

#endif