#ifndef _LEVEL_H_
#define _LEVEL_H_
#include <Box2D/Box2D.h>
#include <SDL.h>
#include "CONSTANTS.h"

class Level {

private:
	
	bool init();
	SDL_Surface* mBackground; //Image
	SDL_Surface* mWindow;
	b2PolygonShape playArea;
	bool loadLevel();

public:
	Level();
	Level(SDL_Surface*);
	~Level();
	void unloadLevel();
	//Getters and Setters
	b2AABB getBoundaries();
};

#endif