#include "Level.h"

//Contructor
Level::Level(){
	loadLevel();
}

Level::~Level(){
	//Deallocate surface
	SDL_FreeSurface( background );
    background = NULL;
}

bool Level::init()
{
	//Apply the image
	SDL_BlitSurface( background, NULL, background, NULL );
}

//Load background
bool Level::loadLevel(){

	//Loading success flag
    bool success = true;

    //Load splash image
	background = SDL_LoadBMP("C:/Users/lab422/Documents/Lab Work/Real World Modelling/Bubble Bonkers!.bmp");

	if( background == NULL )
    {
        printf( "Unable to load image %s! SDL Error: %s\n", "C:/Users/lab422/Documents/Lab Work/Real World Modelling/Bubble Bonkers!.bmp", SDL_GetError() );
        success = false;
    }

	return success;
}