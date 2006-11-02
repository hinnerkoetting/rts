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

typedef  std::vector<MenuButton*> MenuList;

class Menu {
	private:
		static MenuList menu;	
	public:		
		static std::vector<MenuButton*>	getMenuList() { return menu; }
		static void		setMenuList(std::vector<MenuButton*> btnmenue) { menu = btnmenue; };
};


#endif