/////////////////////////////////////////////////////////////////
//
//					
//					menue.cpp
//					draws menus
//					
//
/////////////////////////////////////////////////////////////////

#include <vector>

#include "menue.h"
#include "options.h"
#include "settings.h"


#include "exit.h"
#include "mainmenu.h"
#include "newmenu.h"
/*
 *
 * switches interface to main menu
 *
 */
		


std::vector <MenuButton*> ActiveMenu::menu;


//initiales default buttons
VillageMenu::VillageMenu(){

};

void VillageMenu::addRessourceButton(GameObject::gameObject_ID){
	
};	
	
void VillageMenu::removeRessourceButton(GameObject::gameObject_ID){
};
	//removeSoldierType(GameObject::gameObject_ID);
	//addSoldierType(GameObject::gameObject_ID);
	//later add research
void VillageMenu::makeActive(){
		ActiveMenu::setMenuList(villageMenuList);
				
	};
	
