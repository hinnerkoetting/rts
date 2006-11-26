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
#include "button_display.h"
#include "button_ressource.h"
//#include "village.h"

typedef  std::vector<MenuButton*> MenuList;

class ActiveMenu {
	private:
		static MenuList menu;	
	public:		
		static std::vector<MenuButton*>	getMenuList() { return menu; }
		static void		setMenuList(std::vector<MenuButton*> btnmenue) { menu = btnmenue; };



};

class Village;

/**
 * manages a menus for a villages
 * cares about layout of the menu
 */
class VillageMenu{
private:
	MenuList villageMenuList;
	//BtnRessourceHandler* mRessourceHandler;
	//ButtonValueReader* mButtonValueReader;
	Village* assignedVillage;
	//TODO: Das Village muss sinnvollerweise rein
public:
	VillageMenu(){
		assignedVillage=NULL;	
	};

	//erstmal nicht nutzen
	VillageMenu(Village* v);


	void setVillage(Village *v);

	
	
	void addRessourceButton(GameObject::gameObject_ID);
	//addSoldierType(GameObject::gameObject_ID);
	void removeRessourceButton(GameObject::gameObject_ID);
	//removeSoldierType(GameObject::gameObject_ID);
	//later add research
	void makeActive();
};


#endif