#include "Level.h"

//Contructor
Level::Level(){
}

Level::Level(SDL_Surface* window){
	mWindow = window;
	loadLevel();
	init();

}

Level::~Level(){
}

void Level::unloadLevel(){
	//Deallocate surface
	SDL_FreeSurface( mBackground );
    mBackground = NULL;
}

bool Level::init()
{
	bool success = true;
	
	b2BodyDef playAreaBodyDef;
	playAreaBodyDef.type = b2_staticBody;
	playAreaBodyDef.position.Set(54,0);
	playAreaBodyDef.fixedRotation = 0;

	b2World* mWorld;
	mWorld =  new b2World(b2Vec2_zero);
	b2Body* staticBody = mWorld->CreateBody(&playAreaBodyDef);

	playArea.SetAsBox(576,498);
	b2FixtureDef boxFixtureDef;
	boxFixtureDef.shape = &playArea;
	staticBody->CreateFixture(&boxFixtureDef);

	//Apply the image
	SDL_BlitSurface( mBackground, NULL, mWindow, NULL );
	
	return success;
}

//Load background
bool Level::loadLevel(){

	//Loading success flag
    bool success = true;

    //Load splash image
	mBackground = SDL_LoadBMP("C:/Users/lab422/Documents/Lab Work/Real World Modelling/Bubble Bonkers!.bmp");
	
	if( mBackground == NULL )
    {
        printf( "Unable to load image %s! SDL Error: %s\n", "C:/Users/lab422/Documents/Lab Work/Real World Modelling/Bubble Bonkers!.bmp", SDL_GetError() );
        success = false;
    }

	return success;
}