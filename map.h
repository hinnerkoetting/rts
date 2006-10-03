/////////////////////////////////////////////////////////////////
//
//					
//					map.h
//					infos about map, initialising map...
//					
//
/////////////////////////////////////////////////////////////////

#ifndef MAP_H_DEF
#define MAP_H_DEF
struct EdgeY
{
	short iHeight;
	EdgeY* NextY;
	int iPosY;
};

struct EdgeX
{
	EdgeX* NextX;
	EdgeY* NextY;
	int iPosX;
};

namespace Map
{
	extern EdgeX* World;
}
#endif