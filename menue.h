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
#include "game_object.h"

typedef  std::vector<MenuButton*> MenuList;

class ActiveMenu {
	private:
		static MenuList menu;	
	public:		
		static std::vector<MenuButton*>	getMenuList() { return menu; }
		static void		setMenuList(std::vector<MenuButton*> btnmenue) { menu = btnmenue; };



};

/**
 * manages a menus for a villages
 * cares about layout of the menu
 */
class VillageMenu{
private:
	MenuList villageMenuList;
public:
	VillageMenu();
	void addRessourceButton(GameObject::gameObject_ID);
	//addSoldierType(GameObject::gameObject_ID);
	void removeRessourceButton(GameObject::gameObject_ID);
	//removeSoldierType(GameObject::gameObject_ID);
	//later add research
	void makeActive();
};


#endif