#include <Box2D/Box2D.h>
#include <stdio.h>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_opengl.h>
#include <string>
#include "CONSTANTS.h"
#include "Level.h"
#include "Arrow.h"
#include "LTexture.h"
#include "BubbleBullet.h"
#include "BubbleTarget.h"

bool init(); //Starts up SDL and creates media
bool loadMedia(); //Loads media
void close(); //Frees Media  and shuts down SDL
void gameLoop();
void detectWallColliison();

int score; //Player Score
int lives; //Player Lives

Level level;
BubbleBullet bubbleBullet;
BubbleTarget bubbleTarget;
LTexture m_animation; //bubble bursting animation
int frame = 0; //bubble bursting animation frame
Arrow arrow;
bool quit =false ;
SDL_Event e;
SDL_Window* gWindow = NULL; //The window we'll be rendering to

SDL_Surface* gScreenSurface = NULL;//The surface contained by the window

//The window renderer
SDL_Renderer* gRenderer = NULL;

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
		gameLoop();
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
			//Create vsynced renderer for window
			gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );
			if( gRenderer == NULL )
			{
				printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
				success = false;
			}
			else
			{
				//Initialize renderer color
				SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
			}

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
	bubbleBullet = BubbleBullet();
	bubbleTarget = BubbleTarget();
	bubbleTarget.loadBubbleImage();
	bubbleBullet.loadBubbleImage();
	return success;
}

bool loadMedia(){
	return true;
}

void gameLoop(){
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
		bubbleBullet.handleEvent(e);
		//User requests quit
		if( e.type == SDL_QUIT )
		{
			quit = true;

		}
	}
	detectWallColliison();
	bubbleBullet.move();
	level.draw();
	//Apply the image
	SDL_BlitSurface( arrow.image, NULL, gScreenSurface, &arrow.arrowBounds);
	
	//Fill the surface
	SDL_Delay(50);
	bubbleTarget.drawBubble(gScreenSurface);
	bubbleBullet.drawBubble(gScreenSurface);
		
	//Update the surface
	SDL_UpdateWindowSurface( gWindow );
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

void detectWallColliison(){
	if  (bubbleBullet.location.x + bubbleBullet.DOT_WIDTH >= CONSTANTS::PLAY_AREA_X + CONSTANTS::PLAY_AREA_WIDTH)
	{
		bubbleBullet.setVelocity(-1, 1);
	}
	else if(bubbleBullet.location.x <= CONSTANTS::PLAY_AREA_X )
	{
		bubbleBullet.setVelocity(-1, 1);
	}
	else{
	
	}
}

bool detectBubbleCollision(){
	
	if (true)
	{
		if ((bubbleBullet.Pink && bubbleTarget.Pink)
			|| (bubbleBullet.Blue && bubbleTarget.Blue))
		{
			//Update the surface
			if (bubbleTarget.m_Animation)
			{
				SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
				SDL_RenderClear( gRenderer );
				SDL_Rect* currentClip = &m_animation.gSpriteClips[ frame / 7 ];
				m_animation.render( ( CONSTANTS::PLAY_AREA_WIDTH - currentClip->w ) / 2, ( CONSTANTS::PLAY_AREA_HEIGHT - currentClip->h ) / 2, currentClip ,gRenderer);
				SDL_RenderPresent( gRenderer );
				++frame;
				if( frame / 7 >= 7 )
				{
					frame = 0;
					bubbleTarget.m_Animation = false;
				}
			}
			score++;
		}
		else if ((bubbleBullet.Pink && bubbleTarget.Blue)
			|| (bubbleBullet.Blue && bubbleTarget.Pink))
		{
			lives--;
		}
	}
	return false;
}