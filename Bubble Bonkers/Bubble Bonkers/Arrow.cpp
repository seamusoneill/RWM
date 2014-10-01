#include "Arrow.h"


SDL_Surface* image;
SDL_Rect arrowBounds;
b2Body *arrowBody;  

Arrow::Arrow( ){

	arrowBounds.x = 315.0f;
	arrowBounds.y = 410.0f;
	arrowBounds.w = 50.0f;
	arrowBounds.h = 50.0f;
	angle = 60.0f; 
	arrowBody;
}

void Update(SDL_Event e) {

	if(e.type == SDL_KEYDOWN)
	{
	 switch(e.key.keysym.sym)
		{
			case SDLK_LEFT:
				arrowBounds.x --;
				break;
			case SDLK_RIGHT:
				arrowBounds.y;
				break;
		}
	}
}