/////////////////////////////////////////////////////////////////
//
//					
//					menue.h
//					draws menus
//					
//
/////////////////////////////////////////////////////////////////


namespace Menu
{
	namespace MainMenu
	{
		void switchTo();
		void DrawMenu();
		void DrawBG();
		void DrawButtons();
		void DrawVersion();
		void input(unsigned char key, int x, int y);
		void inputSp(int key, int x, int y);
	}
	namespace NewGame
	{
		void DrawMenu();
		void DrawBG(const short);
		void DrawButtons();
		void Input();
	}
}