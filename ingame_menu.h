/////////////////////////////////////////////////////////////////
//
//					
//					ingame_menu.h
//					
//					
//
/////////////////////////////////////////////////////////////////
#ifndef DEF_INGAME_MENU_H
#define DEF_INGAME_MENU_H
#include "menu_button.h"
class IngameMenu {
	public:
		static MenuButton* buttonList;
		static void calcFPS(int time);
		static void drawMenu();
		static void drawMiniMap();
		static void miniMapClick(int button, int state, int x, int y);
		static void drawButtons();
		static void test(int button);
};
#endif