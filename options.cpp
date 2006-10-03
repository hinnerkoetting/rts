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
namespace Options
{
	const char* filename = "config.cfg";


	bool bFPS = true;			// FPS display?
	int CUR_LANG = LANG_GERMAN;
	bool bCoords = true;		// Display of coordinates?
	const int iNumberEdgesX = 116;	//World size TO-DO: add to config
	const int iNumberEdgesY = 116;	//..
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
	InFile file(const_cast<char*>(filename));
	if (!file.isOpen())
		return false;
	char* buffer = new char[80];
	file >> buffer; //comment lines
	file >> buffer;
	file >> buffer;
	file >> buffer;
	ResolutionX =  atoi(buffer);

	file >> buffer;
	file >> buffer;
	ResolutionY =  atoi(buffer);

	file >> buffer;
	file >> buffer;
	BitsPerPixel = atoi(buffer);

	file >> buffer;
	file >> buffer;
	iRefreshRate = atoi(buffer);
	
	file >> buffer;
	file >> buffer;
	CUR_LANG = atoi(buffer);
	
	file >> buffer;
	file >> buffer;
	bFPS = (bool)atoi(buffer);
	
	file >> buffer;
	file >> buffer;
	bCoords = (bool)atoi(buffer);

	file >> buffer;
	file >> buffer;
	iRenderOnlyEveryFrame = atoi(buffer);

	file >> buffer;
	file >> buffer;
	bBorders = (bool)atoi(buffer);

	file >> buffer;
	file >> buffer;
	chIP = buffer;

	file >> buffer;
	file >> buffer;

	iPort = atoi(buffer);
	return true;
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