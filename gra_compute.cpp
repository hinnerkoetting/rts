/////////////////////////////////////////////////////////////////
//
//					Graphic_comp.cpp
//					computes (pixel/gl)-positions
//					
//					
//
/////////////////////////////////////////////////////////////////

#include "gl/glut.h"

#include "graphic.h"
#include "gra_ingame.h"
#include "options.h"
#include "errors.h"
#include <stdlib.h>
#include <string.h>

/*
 *
 * returns resolution in gl format (ResX + 'x' + ResY + ':' + Bpp)
 *
 */
void Graphic::resolution(char c[16]) {
	char c2[8];
	_itoa_s(Options::ResolutionX, c,16, 10);
	_itoa_s(Options::ResolutionY, c2,8, 10);
	strncat_s(c, 16, "x",1);
	strncat_s(c, 16, c2,4);
	strncat_s(c, 16, ":",1);
	strncat_s(c, 16, "32",2);
}
/*
 *
 * get coordinate position to given pixel and z coordinate
 *  bX == true => x coordinate else y
 */
float Graphic::pixelToGl(int pos, float z, bool bX) {
	if (bX) {
		return ((float)pos/Options::ResolutionX -0.5f /*-GraIngame::getMenuWidth()*/) * (GraIngame::getZ() - z) * 1.105 + GraIngame::getX();
	}
	return -((float)pos/Options::ResolutionY -0.5) * (GraIngame::getZ() - z) * 0.83 + GraIngame::getY();
}

/*
 *
 * get pixel position to given point in gl
 * bX == true => x coordinate else y
 */
int Graphic::glToPixel(Point P0, bool bX) {
	if (bX) 
		return ((P0.x - GraIngame::getX()) / ((GraIngame::getZ() - P0.z) * 1.105) + 0.5f /*+GraIngame::getMenuWidth()*/) * Options::ResolutionX;
	return ((-P0.y + GraIngame::getY()) / ((GraIngame::getZ() - P0.z) * 0.83) + 0.5) * Options::ResolutionY;
}

/*
 *
 * calcs mouse position on raster of gamefield in GL coordinates
 * bX == true  -> x position
 */

float Graphic::rasterPos(bool bX) {
	if (bX) {
		float x = Graphic::pixelToGl(GraIngame::getMX(), 0.0f, true);	// calc mouse position to GL coordinates
		float fX = x/GraIngame::getLength();				// calc position on raster
		if (fX - (int)fX >= 0.5)							// if mouse is nearer to right border
			fX = (int)fX + 1;
		else fX = (int)fX;
		return fX * GraIngame::getLength();					// return to old format
	}
	else {
		float y = Graphic::pixelToGl(GraIngame::getMY(), 0.0f, false);			// same for y
		float fY = y/GraIngame::getHeigth();
		if (fY - (int)fY >= 0.5)							
			fY = (int)fY + 1;
		else fY = (int)fY;
		return fY * GraIngame::getHeigth();				
	}
}

/*
 *
 * computes point at a different heigth so that it is seen on screen on same position
 * 
 */
Point Graphic::changeHeigth(Point P, float z) {
	Point Q;
	if (P.z - z != 0) {
		Q.x = (P.x/* - GraIngame::getX()*/)* (GraIngame::getZ() - z) / (GraIngame::getZ() - P.z);// + GraIngame::getX();
		Q.y = (P.y/* - GraIngame::getY()*/) * (GraIngame::getZ() - z)/ (GraIngame::getZ() - P.z);// + GraIngame::getY();
	}
	else { 
		Q.x = P.x;
		Q.y = P.y;
	}
	Q.z = z;
	Q.r = P.r;
	Q.g = P.g;
	Q.b = P.b;
	return Q;
	return P;
}

/*
 *
 * returns true if point is visible
 *
 */
bool Graphic::visible(Point P) {
	if (glToPixel(P, true) > Options::ResolutionX || glToPixel(P, false) > Options::ResolutionY || glToPixel(P, true) < 0 || glToPixel(P, false) < 0)
		return false;
	return true;
}
