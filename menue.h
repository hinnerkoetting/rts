/////////////////////////////////////////////////////////////////
//
//					
//					menue.h
//					draws menus
//					
//
/////////////////////////////////////////////////////////////////

#ifndef DEF_MENUE
#define DEF_MENUE
#include <vector>
#include "menu_button.h"

namespace Menu
{
	
	std::vector<MenuButton>	getMenuList();
	void				setMenuList(std::vector<MenuButton> btnmenue);
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

/*class Menu{
private:
	//MenuButton* IngameMenu::buttonList;
	static 

public:
	
};*/


#endif