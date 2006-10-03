/////////////////////////////////////////////////////////////////
//	OLD: no more need
//					Graphic_fields.cpp
//					draws all the fields for map
//					
//					
//
/////////////////////////////////////////////////////////////////

#include "gra_ingame.h"
#include "graphic.h"
#include "errors.h"
#include "exit.h"
/*
 *
 * checks what type a field is,then draws it
 *
 */
/*void GraIngame::drawOneField(_EdgeX* lpEdgeX, _EdgeY* lpEdgeY, int x, int y) {
	if ( lpEdgeX->NextX != 0) { // if field exists
		_EdgeY* lpEdgeY2 = lpEdgeX->NextX->NextY;
		while (lpEdgeY2->iPosY != lpEdgeY->iPosY)
			lpEdgeY2 = lpEdgeY2->NextY;  // go to edge right to last one
		if (lpEdgeY->iHeight == lpEdgeY->NextY->iHeight && lpEdgeY2->iHeight == lpEdgeY->iHeight && lpEdgeY2->NextY->iHeight == lpEdgeY->iHeight) {//same hight 
				drawPlane(lpEdgeY->iHeight, x, y);
		}
		else {
			int i[4] ={lpEdgeY->NextY->iHeight, lpEdgeY2->NextY->iHeight, lpEdgeY2->iHeight, lpEdgeY->iHeight};
			drawGrad(i , x, y);
		}
	}
}*/


/*
 *
 * draws a plane
 *
 */
/*void GraIngame::drawPlane(const int iHeight, int x, int y) {
	if (iHeight == 0) {
		glPushMatrix();
		glTranslatef(getLength() * x, getHeigth() * y, 0);
		glCallList(1);
		glPopMatrix();
	}
	else {
		float z = 0.0f;//(float)(iHeight * 0.1);
		glPushMatrix();
		Point P = Graphic::changeHeigth(Point(x * getLength(), y * getHeigth(), 0), z);
		glTranslatef(P.x, P.y, z);
		glCallList(2);
		
		glPopMatrix();
		//Point P0 = Graphic::changeHeigth(Point(x	 * getLength()	, (y-1)  * getHeigth(), 0, r, g, b), z);
		//Point P1 = Graphic::changeHeigth(Point((x-1)* getLength()	,(y-1)	* getHeigth(), 0, r, g, b), z);
		//Point P2 = Graphic::changeHeigth(Point((x-1)* getLength()	,y		* getHeigth(), 0, r, g, b), z);
		//Point P3 = Graphic::changeHeigth(Point(x	 * getLength()	,y		* getHeigth(), 0, r, g, b), z);
	}
	
	//Graphic::drawQuad(P0, P1, P2, P3);
	/*
/*	P0.r = 0.0f;
	P0.g = 0.0f;
	P0.b = 0.0f;
	P1.r = 0.0f;
	P1.g = 0.0f;
	P1.b = 0.0f;
	P2.r = 0.0f;
	P2.g = 0.0f;
	P2.b = 0.0f;
	P3.r = 0.0f;
	P3.g = 0.0f;
	P3.b = 0.0f;
	P0 = Graphic::changeHeigth(P0, P0.z + 0.1f);
	P1 = Graphic::changeHeigth(P1, P1.z + 0.1f);
	P2 = Graphic::changeHeigth(P2, P2.z + 0.1f);
	P3 = Graphic::changeHeigth(P3, P3.z + 0.1f);
	Graphic::drawLine3D(P0, P1);
	Graphic::drawLine3D(P1, P2);
	Graphic::drawLine3D(P2, P3);
	Graphic::drawLine3D(P3, P0);*/
//}


/*
 *
 * draws a gradient
 *
 */
/*void GraIngame::drawGrad(int heigth[4], int x, int y) {
	float r = 0.3f;
	float g = 0.25f;
	float b = 0.05f;
	int iLowestHeight = 10;			// minimum height of the field
	for (int i = 0; i <4; i++)    
		if (iLowestHeight > heigth[i]) 
			iLowestHeight = heigth[i];
	float z = (float)iLowestHeight * 0.1f;	
	bool bo= false;
	if (iLowestHeight == 0) {
		bo = false;
		GraIngame::drawPlane(iLowestHeight, x, y);		//draws plane behind gradient
	}
	else bo= true;
	
	glPushMatrix();
	
	glTranslatef(x * getLength(), y * getHeigth(), 0);
	if (bo)
		glCallList(17);
	if ((heigth[0] < heigth[1]) && (heigth[2] < heigth[1]) && (heigth[3] < heigth[1]))		
		glCallList(3);
	else if (heigth[0] < heigth[1] && heigth[3] < heigth[1] && heigth[2] == heigth[1]) 
		glCallList(4);
	else if (heigth[0] < heigth[2] && heigth[1] < heigth[2] && heigth[3] < heigth[2]) {
		glCallList(5);
	}
	else if (heigth[0] < heigth[2] && heigth[1] < heigth[2] && heigth[2] == heigth[3])
		glCallList(6);
	

	else if (heigth[0] < heigth[3] && heigth[1] < heigth[3] && heigth[2] < heigth[3]) 
		glCallList(7);
	else if (heigth[1] < heigth[0] && heigth[2] < heigth[0] && heigth[3] == heigth[0]) 
		glCallList(8);
	else if (heigth[1] < heigth[0] && heigth[2] < heigth[0] && heigth[3] < heigth[0]) 
		glCallList(9);
	else if (heigth[2] < heigth[0] && heigth[3] < heigth[0] && heigth[1] == heigth[0]) 
		glCallList(10);
	else if (heigth[0] < heigth[1] && heigth[2] < heigth[1] && heigth[1] == heigth[3])
		glCallList(11);
	else if (heigth[1] < heigth[0] && heigth[3] < heigth[0] && heigth[2] == heigth[0])
		glCallList(12);
	else if (heigth[0] < heigth[1] && heigth[0] < heigth[2] && heigth[0] < heigth[3]) 
		glCallList(13);
	else if (heigth[1] < heigth[0] && heigth[1] < heigth[2] && heigth[1] < heigth[3]) 
		glCallList(14);
	else if (heigth[2] < heigth[0] && heigth[2] < heigth[1] && heigth[2] < heigth[3]) 	
		glCallList(15);
	else if (heigth[3] < heigth[0] && heigth[3] < heigth[1] && heigth[3] < heigth[2])
		glCallList(16);
	glPopMatrix();
*/
	/*Point P0 = Point((x-1)	* getLength()	,y		* getHeigth());
	Point P1 = Point(x		* getLength()	,y		* getHeigth()); //TODO when moving on minimap lines are verschoben
	Point P2 = Point(x		* getLength()	,(y - 1)* getHeigth());
	Point P3 = Point((x-1)	* getLength()	,(y - 1)* getHeigth());
	P0 = Graphic::changeHeigth(P0, P0.z + 0.1f);
	P1 = Graphic::changeHeigth(P1, P1.z + 0.1f);
	P2 = Graphic::changeHeigth(P2, P2.z + 0.1f);
	P3 = Graphic::changeHeigth(P3, P3.z + 0.1f);
	Graphic::drawLine3D(P0, P1);
	Graphic::drawLine3D(P1, P2);
	Graphic::drawLine3D(P2, P3);
	Graphic::drawLine3D(P3, P0);*/
	
//}	
	
