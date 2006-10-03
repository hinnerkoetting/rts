/////////////////////////////////////////////////////////////////
//
//					options.h
//					settings
//					TO-DO: options selecable in menu
//					
//
/////////////////////////////////////////////////////////////////

namespace Options
{
	bool ReadCfg();
	bool WriteCfg();
	short getRefreshRate();

	extern bool bFPS;
	extern bool bCoords;
	extern int CUR_LANG;
	extern const int iNumberEdgesX;
	extern const int iNumberEdgesY;
	extern int ResolutionX;
	extern int ResolutionY;
	extern int iRenderOnlyEveryFrame;  // if computer is slow, this can be used to increase FPS
	extern bool bBorders;
	extern int BitsPerPixel;
	extern int iRefreshRate;

	extern bool debug;
}