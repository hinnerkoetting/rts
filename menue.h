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

class Menu {
	private:
		static std::vector<MenuButton*> menu;	
	public:		
		static std::vector<MenuButton*>	getMenuList() { return menu; }
		static void		setMenuList(std::vector<MenuButton*> btnmenue) { menu = btnmenue; };
};


#endif