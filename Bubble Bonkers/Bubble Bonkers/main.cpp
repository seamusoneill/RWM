#include <Box2D/Box2D.h>
#include <stdio.h>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_opengl.h>
#include <string>
#include "CONSTANTS.h"
#include "Level.h"
#include "Arrow.h"
#include "BubbleBullet.h"
#include "BubbleTarget.h"

bool init(); //Starts up SDL and creates media
bool loadMedia(); //Loads media
void close(); //Frees Media  and shuts down SDL



int score; //Player Score
Level level;
BubbleBullet* bubbleBullet;
BubbleTarget* bubbleTarget;
Arrow arrow;
bool quit =false ;
SDL_Event e;
SDL_Window* gWindow = NULL; //The window we'll be rendering to

SDL_Surface* gScreenSurface = NULL;//The surface contained by the window

enum KeyPressSurfaces
{
    KEY_PRESS_SURFACE_LEFT,
    KEY_PRESS_SURFACE_RIGHT,   
};

int main( int argc, char* args[] ){
	//Start up SDL and create window
	
    if( !init() )
    {
        printf( "Failed to initialize!\n" );
    }
	arrow.image =IMG_Load("C:/Users/lab422/Documents/Lab Work/Real World Modelling/arrow.png");

    while( !quit )
    {
	  //Handle events on queue
      while( SDL_PollEvent( &e ) != 0 )
	 {    
		 if(e.type == SDL_KEYDOWN)
		 {
			 switch(e.key.keysym.sym)
			 {
				case SDLK_LEFT:
					arrow.arrowBounds.x--; 
					break;
				case SDLK_RIGHT:
				arrow.arrowBounds.x++; 
					break;
				case SDLK_ESCAPE:
					quit = true;
			 }
		 } 	
		 //User requests quit
		 if( e.type == SDL_QUIT )
		 {
			 quit = true;
		 }

		 //Apply the image
		SDL_BlitSurface( arrow.image, NULL, gScreenSurface, &arrow.arrowBounds);
		//Update the surface
        SDL_UpdateWindowSurface( gWindow );	
		}
	 } 
	//Free resources and close SDL
    close();

    return 0;
 
}

bool init(){
	 //Initialization flag
    bool success = true;
		
    //Initialize SDL
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
        success = false;
    }
    else
    {
		//Create window
		gWindow = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, CONSTANTS::SCREEN_WIDTH, CONSTANTS::SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if( gWindow == NULL )
        {
            printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
            success = false;
        }
        else
        {
         //Initialize PNG loading
            int imgFlags = IMG_INIT_PNG;
            if( !( IMG_Init( imgFlags ) & imgFlags ) )
            {
                printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
                success = false;
            }
            else
            {
                //Get window surface
                gScreenSurface = SDL_GetWindowSurface( gWindow );
            }
        }
    }

	level = Level(gScreenSurface);
  	arrow = Arrow();
	return success;
}

bool loadMedia(){
	return true;
}
void close()
{
	level.unloadLevel();

    //Destroy window
    SDL_DestroyWindow( gWindow );
    gWindow = NULL;

    //Quit SDL subsystems
    SDL_Quit();
}

bool collisionDetection(){
	return false;
}