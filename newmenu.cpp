/////////////////////////////////////////////////////////////////
//
//					
//					newmenu.cpp
//					
//					
//
/////////////////////////////////////////////////////////////////

#include "newmenu.h"

/*
 *
 * draws New Game menu (background & buttons)
 *
 */

void NewGame::draw()
{
	DrawBG(0);
	DrawButtons();
}

/*
 *
 * draws the background of the New Game menue
 *
 */
void NewGame::DrawBG(const short iType)
{
	//Grafik::DrawRectangle(Point(-5.0f, 5.0f, 0.0f, 0.5f), Point(5.0f, 5.0f, 0.0f, 0.5f), Point(5.0f, -5.0f, 0.0f, 0.5f), Point(-5.0f, -5.0f, 0.0f, 0.5f));
}


/*
 *
 * draws buttons of the New Game Menu
 * TODO: rework
 */
void NewGame::DrawButtons()
{
	const int iLang = LANG_GERMAN;
	switch(iLang)
	{
		case LANG_GERMAN:
		{
			/*Gra::g.Drastring(Point(-1.0f, 0.5f, 0.0f, 0.5f, 0.5f, 0.5f), "1 : Quickstart");
			Gra::g.Drastring(Point(-1.0f, 0.0f, 0.0f, 0.5f, 0.5f, 0.5f), "Escape : Zur�ck");*/
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
void NewGame::Input()
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
