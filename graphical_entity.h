//this class is a basic class for graphical entities like units and ressources.
// each entity has coordinates and can  be displayed

#ifndef GRAPH_ENTITY
#define GRAPH_ENTITY
#include <string>

class graph_entry{

protected:
	int xPos;
	int yPos;
	std::string name;

public:

	virtual int getXPos(){ return xPos;}
	virtual int getYPos(){ return yPos;}

	virtual void setNewPos(int newXPos, int newYPos){
		xPos=newXPos;
		yPos=newYPos;
	}

	virtual void draw()=0;


	virtual void setName(char* n) { name = n; }
	virtual std::string getName() { return name; }

};


#endif GRAPH_ENTITY