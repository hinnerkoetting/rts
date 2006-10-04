/////////////////////////////////////////////////////////////////
//
//					
//					newmenu.h
//					
//					
//
/////////////////////////////////////////////////////////////////
#include "menue.h"
#define LANG_GERMAN 0
class NewGame {
	private:
		static void DrawBG(const short);
		static void DrawButtons();
	public:
		static void draw();
		static void Input();
};