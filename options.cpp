/////////////////////////////////////////////////////////////////
//
//					options.cpp
//					settings
//					TODO: options selectable in menu
//					
//
/////////////////////////////////////////////////////////////////
#include <windows.h>
#include <tchar.h>
#include "options.h"

#include "file.h"


#include "errors.h"
#include <fstream>
#include <map>
#include <stdio.h>
#include <sstream>
#include "Util.h"
#include "exception.h"
#include <string>
#include "WinProperties.h"

using namespace std;
namespace Options
{
	const char* filename = "config.cfg";


	bool bFPS = true;			// FPS display?
	int CUR_LANG = LANG_GERMAN;
	bool bCoords = true;		// Display of coordinates?
	const int iNumberEdgesX = 100;	//World size TO-DO: add to config
	const int iNumberEdgesY = 100;	//..
	int ResolutionX = GetSystemMetrics(SM_CXSCREEN);
	int ResolutionY = GetSystemMetrics(SM_CYSCREEN);
	int BitsPerPixel = 16;
	int iRenderOnlyEveryFrame =  1;
	bool  bBorders = 1;
	int iRefreshRate = getRefreshRate();
	char* chIP = "localhost";
	int iPort = 8765;
	bool debug; // TODO: include into config
}


/*
 *
 * gets system refreshrate
 *
 */
short Options::getRefreshRate()
{
	DEVMODE lpDevMode;
	memset(&lpDevMode,0,sizeof(lpDevMode)); 
	lpDevMode.dmSize = sizeof(lpDevMode);
	EnumDisplaySettings(NULL, ENUM_REGISTRY_SETTINGS, &lpDevMode);
	return short(lpDevMode.dmDisplayFrequency);
}

/*
 *
 * reads the config and assigns values
 *
 */
bool Options::ReadCfg()
{
	try{
	WinProperties prop("SOFTWARE\\oetting\\");
	ResolutionX	=StringToInteger ( 	prop.loadProperty("grafik","ResolutionX"));
	ResolutionY	=StringToInteger ( 	prop.loadProperty("grafik","ResolutionY"));
	BitsPerPixel=StringToInteger ( 	prop.loadProperty("grafik","BitsPerPixel"));
	iRefreshRate =StringToInteger ( 	prop.loadProperty("grafik","iRefreshRate"));	
	CUR_LANG = StringToInteger ( 	prop.loadProperty("grafik","CUR_LANG"));	
	bFPS = StringToInteger ( 	prop.loadProperty("grafik","bFPS"));	
	bCoords =StringToInteger ( 	prop.loadProperty("grafik","bCoords"));
	iRenderOnlyEveryFrame = StringToInteger ( 	prop.loadProperty("grafik","iRenderOnlyEveryFrame"));
	bBorders = StringToInteger ( 	prop.loadProperty("grafik","bBorders"));
	//chIP IP wird nicht benötigt erstmal (gerade keine Lust auf char*, wenn möglich, bitte string verwenden
	iPort = StringToInteger ( 	prop.loadProperty("grafik","Port"));
	std::string s("Config gelesen");
	log::log(s);
	return true;
	}
	catch (GeneralGameException e){		
		string error_msg="Please check the registry : "+e.Text();
		
		
		MessageBox(NULL,error_msg.c_str(),"Error reading configuration. ", MB_ICONERROR);
		exit (1);
	}
}

/*
 *
 * writes values into config
 *
 */
bool Options::WriteCfg()
{
	OutFile outFile(const_cast<char*>(filename));
	if (!outFile.isOpen())      
        return false;
	char buffer[5] = "   ";
	outFile << "//DO_NOT_CHANGE_ORDER_OF_LINES_OR_THE_GAME_COULD_CRASH\n";
	outFile << "//DELETE_THIS_FILE_FOR_DEFAULT_CONFIG\n";

	_itoa_s(ResolutionX, buffer, 10);
    outFile  << "ResolutionX= " << buffer << '\n';

	_itoa_s(ResolutionY, buffer, 10);
	outFile  << "ResolutionY= " << buffer << '\n';


	_itoa_s(BitsPerPixel, buffer, 10);
	outFile << "BitsPerPixel= " << buffer << '\n';

	_itoa_s(iRefreshRate, buffer, 10);
	outFile << "RefreshRate= " << buffer << '\n';

	_itoa_s(CUR_LANG, buffer, 10);
	outFile << "Language= " << buffer << '\n';

	_itoa_s(bFPS, buffer, 10);
	outFile << "FPS= " << buffer << '\n';
	
	_itoa_s(bCoords, buffer, 10);
	outFile << "Coords= " << buffer << '\n';
	
	_itoa_s(iRenderOnlyEveryFrame, buffer, 10);
	outFile << "RenderOnlyEveryFrame= " << buffer << '\n';

	_itoa_s(bBorders, buffer, 10);
	outFile << "Borders= " << buffer << '\n';

	outFile << "IP= " << chIP << '\n';

	outFile << "Port= " << iPort << '\n';

    return true;
}