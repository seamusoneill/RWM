#ifndef _LEVEL_H_
#define _LEVEL_H_
#include <Box2D/Box2D.h>
#include <SDL.h>
#include <stdio.h>
#include "CONSTANTS.h"

class Level {

private:
	bool loadLevel();
	bool init();
	SDL_Surface* background; //Image
	b2AABB playArea;	
	
public:
	Level();
	~Level();

	//Getters and Setters
	b2AABB getBoundaries();
};

#endif