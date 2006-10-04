/////////////////////////////////////////////////////////////////
//
//					
//					mainmenu.cpp
//					
//					
//
/////////////////////////////////////////////////////////////////

#include "gl/glut.h"
#include "mainmenu.h"
#include "options.h"
#include "exit.h"
#define LANG_GERMAN 0
/*
 *
 * draws the main menu (background & buttons)
 *
 */
void MainMenu::draw()
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
void MainMenu::DrawVersion()
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
void MainMenu::DrawBG()
{
	//Grafik::DrawImage("bla");
	//Grafik::DrawRectangle(Point(-5.0f, 5.0f, 0.0f, 0.5f), Point(5.0f, 5.0f, 0.0f, 0.5f), Point(5.0f, -5.0f, 0.0f, 0.5f), Point(-5.0f, -5.0f, 0.0f, 0.5f));
}

/*
 *
 * draws buttons
 * TODO: rework
 */
void MainMenu::DrawButtons()
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
void MainMenu::input(unsigned char key, int x, int y)
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

void MainMenu::inputSp(int key, int x, int y) {
	switch (key) {
		case GLUT_KEY_F11:
			glColor3f(0.3,0.1,0.5);
			break;
	}
}