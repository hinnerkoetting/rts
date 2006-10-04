/////////////////////////////////////////////////////////////////
//
//					
//					mainmenu.h
//					
//					
//
/////////////////////////////////////////////////////////////////

#include "menue.h"

class MainMenu {
	private:
		static void DrawBG();
		static void DrawButtons();
		static void DrawVersion();
	public:
		static void draw();
		static void input(unsigned char key, int x, int y);
		static void inputSp(int key, int x, int y);
};