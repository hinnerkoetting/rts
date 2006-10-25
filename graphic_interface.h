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
		// coordinates given are position of top left corner of that object
		static void drawObjectMenu(int dlIndex, float x1, float x2, int lenX, int lenY); // draw an object in menu
		static void drawObjectGame(int dlIndex, float x, float y, int lenX, int lenY); // draw an object on the gamefield
		static void drastring3d(float x, float y, float z, void *font, char *string);
		static void drastring2d(float x, float y, void *font, char *string);
		static void drawLineStrip(float x1, float x2, float y1, float y2, float r = 1.0f, float g = 1.0f, float b = 1.0f);
		static void initGame();
		static void initGraphics(int argc, char **argv);

};
#endif