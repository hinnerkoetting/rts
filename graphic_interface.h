/////////////////////////////////////////////////////////////////
//
//					
//					graphic_interface.h
//					interface to graphic functions
//					
//
/////////////////////////////////////////////////////////////////

#ifndef GRAPHIC_INTERFACE_H_DEF
#define GRAPHIC_INTERFACE_H_DEF

class GraphicInterface {
	public:
		static void drawMenu(int dlIndex, float x1, float x2, float lenX, float lenY); // draw an object in menu
		static void drawGame(int dlIndex, float x1, float x2, float lenX, float lenY); // draw an object on the gamefield
		static void initGame();
		static void initGraphics(int argc, char **argv);

};
#endif