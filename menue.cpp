/////////////////////////////////////////////////////////////////
//
//					
//					menue.cpp
//					draws menus
//					
//
/////////////////////////////////////////////////////////////////
#define LANG_GERMAN 0
#include "menue.h"

#include "options.h"

#include "ingame.h"
#include "settings.h"
#include "point.h"
#include "graphic.h"
#include "errors.h"
#include "gl/glut.h"
#include "exit.h"

/*
 *
 * switches interface to main menu
 *
 */
		
/*
 *
 * draws the main menu (background & buttons)
 *
 */

std::vector <MenuButton> Menu::menu;



	std::vector<MenuButton>	 Menu::getMenuList(){return menu;};
	void				Menu::setMenuList(std::vector<MenuButton> btnmenue){menu=btnmenue;};

void Menu::MainMenu::DrawMenu()
{
	DrawBG();
	DrawButtons();
	DrawVersion();
}

/*
 *
 * draws version number
 * TODO: Rework
 */
void Menu::MainMenu::DrawVersion()
{
	/*char buffer[80] = "Multi sein Spiel,  V.";
	strcat_s(buffer, Settings::cchVersionNumber);	
	DrawString(Point(-1.0f, -1.0f, 0.0f, 0.5f, 0.5f, 0.5f) , buffer);*/
}
/*
 *
 * draws the background of the main menue
 *
 */
void Menu::MainMenu::DrawBG()
{
	//Grafik::DrawImage("bla");
	//Grafik::DrawRectangle(Point(-5.0f, 5.0f, 0.0f, 0.5f), Point(5.0f, 5.0f, 0.0f, 0.5f), Point(5.0f, -5.0f, 0.0f, 0.5f), Point(-5.0f, -5.0f, 0.0f, 0.5f));
}

/*
 *
 * draws buttons
 * TODO: rework
 */
void Menu::MainMenu::DrawButtons()
{
	int iLang = LANG_GERMAN;
	switch(iLang)
	{
		case LANG_GERMAN:
		{
			/*Gra::g.DrawLine(Point(-0.25f, 0.5f, -0.1f, 0.5f, 0.5f, 0.5f), Point(-0.25f, 1.05f, 1.0f, 1.0f, 1.0f, 1.0f));
			Gra::g.DrawString(Point(-0.25f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f),  "1  : Spielstart");
			Gra::g.DrawString(Point(-0.25f, 0.25f, -0.2f, 0.5f, 0.5f, 0.5f), "2  : Optionen(disabled)");
			Gra::g.DrawString(Point(-0.25f, 0.0f, 0.0f, 0.5f, 0.5f, 0.5f), "F12 : Beenden");*/
		}
		default:
			return;	}
}

/*
 *
 * handles input in main menu
 *
 */
void Menu::MainMenu::input(unsigned char key, int x, int y)
{
	switch (key) {
		case 27: //escape
			Options::WriteCfg();
			Exit::doIt();
			break;
		default:
			break;
	}
}

/*
 *
 * input in main menu for special keys
 *
 */

void Menu::MainMenu::inputSp(int key, int x, int y) {
	switch (key) {
		case GLUT_KEY_F11:
			glColor3f(0.3,0.1,0.5);
			break;
	}
}
/*
 *
 * draws New Game menu (background & buttons)
 *
 */

void Menu::NewGame::DrawMenu()
{
	DrawBG(0);
	DrawButtons();
}

/*
 *
 * draws the background of the New Game menue
 *
 */
void Menu::NewGame::DrawBG(const short iType)
{
	//Grafik::DrawRectangle(Point(-5.0f, 5.0f, 0.0f, 0.5f), Point(5.0f, 5.0f, 0.0f, 0.5f), Point(5.0f, -5.0f, 0.0f, 0.5f), Point(-5.0f, -5.0f, 0.0f, 0.5f));
}


/*
 *
 * draws buttons of the New Game Menu
 * TODO: rework
 */
void Menu::NewGame::DrawButtons()
{
	const int iLang = LANG_GERMAN;
	switch(iLang)
	{
		case LANG_GERMAN:
		{
			/*Gra::g.DrawString(Point(-1.0f, 0.5f, 0.0f, 0.5f, 0.5f, 0.5f), "1 : Quickstart");
			Gra::g.DrawString(Point(-1.0f, 0.0f, 0.0f, 0.5f, 0.5f, 0.5f), "Escape : Zurück");*/
		}
		default:
			return;
	}
}

/*
 *
 * handles input in new game menu
 *
 */
void Menu::NewGame::Input()
{
	/*using namespace Game;
	if (keys['1'].iNumber)
	{
		Ingame::InitGame();
		Ingame::NewHeroes(2);
		grafikStream = &Ingame::Draw::Game;
		Game::Input = &Ingame::Input;
		return;
	}
	if (keys[VK_ESCAPE].iNumber)
	{
		grafikStream = &Menu::MainMenu::DrawMenu;
		//Game::Input = &Menu::MainMenu::Input;
		return;
	}*/
}


