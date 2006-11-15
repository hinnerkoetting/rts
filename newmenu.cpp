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
 * draws buttons of the New Game ActiveMenu
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
			Gra::g.Drastring(Point(-1.0f, 0.0f, 0.0f, 0.5f, 0.5f, 0.5f), "Escape : Zurück");*/
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
		ViewAndControl::InitGame();
		ViewAndControl::NewHeroes(2);
		grafikStream = &ViewAndControl::Draw::Game;
		Game::Input = &ViewAndControl::Input;
		return;
	}
	if (keys[VK_ESCAPE].iNumber)
	{
		grafikStream = &ActiveMenu::MainMenu::DrawMenu;
		//Game::Input = &ActiveMenu::MainMenu::Input;
		return;
	}*/
}
