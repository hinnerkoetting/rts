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
//TODO defines anders integrieren
#include "defines.h"
#include "button_display.h"
#include "button_ressource.h"
#include "village.h"
#include "villageNameButton.h"
/*
 *
 * switches interface to main menu
 *
 */
		


std::vector <MenuButton*> ActiveMenu::menu;


//initiales default buttons
VillageMenu::VillageMenu(Village* v){
	assignedVillage=v;
	//TODO: optimize code
	
	assignedVillage=NULL;
	MenuButton* m1;
//	ButtonValueReader bla=*assignedVillage;
	//Village v1=*assignedVillage;
	//ButtonValueReader* br=&v1;
	m1 = new ButtonDisplay	(0		, 0.05	, 0.1, 0.15, 0.02, 0.08, BUTTON_UNIT_ID		, assignedVillage, GameObject::TOTAL_UNITS);
	
	
	villageMenuList.push_back(m1);

	m1 = new ButtonDisplay	(0		, 0.05	, 0.2, 0.25, 0.02, 0.08, BUTTON_HOUSE_ID	, assignedVillage, GameObject::IDLEWORKER);
 	villageMenuList.push_back(m1);

	m1 = new ButtonRessource (0.05	, 0.1	, 0.2, 0.25, 0.02, 0.08, BUTTON_ATTACK_ID	, assignedVillage, GameObject::SOLDIER);
	
	villageMenuList.push_back(m1);
}


void VillageMenu::addRessourceButton(GameObject::gameObject_ID){
	//MenuButton* m1;
	//m1 = new ButtonRessource (0.1	, 0.15	, 0.2, 0.25, 0.02, 0.08, BUTTON_GOLDMINE_ID	, assignedVillage, GameObject::GOLD);
	//villageMenuList.push_back(m1);
	
	
};	
	
void VillageMenu::removeRessourceButton(GameObject::gameObject_ID){
};
	//removeSoldierType(GameObject::gameObject_ID);
	//addSoldierType(GameObject::gameObject_ID);
	//later add research
void VillageMenu::makeActive(){
		ActiveMenu::setMenuList(villageMenuList);
				
	};
	
//WIRD NOCH OPTIMIERT!!!!!!!!ENTWICKLUNGSCODE!!!!!!!!!!!!!!!
	void VillageMenu::setVillage(Village *v){ 
		this->assignedVillage=v;
		
	MenuButton* m1;
//	ButtonValueReader bla=*assignedVillage;
	//Village v1=*assignedVillage;
	//ButtonValueReader* br=&v1;
	//m1 = new ButtonDisplay	(0		, 0.05	, 0.1, 0.15, 0.02, 0.08, BUTTON_UNIT_ID		, assignedVillage, GameObject::TOTAL_UNITS);
	
	
	//villageMenuList.push_back(m1);

	//m1 = new ButtonDisplay	(0		, 0.05	, 0.2, 0.25, 0.02, 0.08, BUTTON_HOUSE_ID	, assignedVillage, GameObject::IDLEWORKER);
 	//villageMenuList.push_back(m1);

	//m1 = new ButtonRessource (0.05	, 0.1	, 0.2, 0.25, 0.02, 0.08, BUTTON_ATTACK_ID	, assignedVillage, GameObject::SOLDIER);
	
	//villageMenuList.push_back(m1);

	//Village name
	
	MenuButton* villageButton=new VillageNameButton(0.05,0.2,0.05,0.62, assignedVillage);


	villageMenuList.push_back(villageButton);
	

	};

	//NORMALER CODE
