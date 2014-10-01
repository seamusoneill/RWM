#ifndef _ARROW_H_
#define _ARROW_H_

#include <Box2D/Box2D.h>
#include <stdio.h>
#include <SDL.h>
#include <SDL_image.h>
#include <string>


class Arrow 
{
public:
	Arrow::Arrow();
	SDL_Surface* image;
	SDL_Rect arrowBounds;
	float angle;
	void Update(SDL_Event);
	SDL_Surface Load(); 
};

#endif 
