#include "BubbleBullet.h"
#include <iostream>

BubbleBullet::BubbleBullet()
{

    //Initialize the offsets
    mPosX = 0;
    mPosY = 0;

    //Initialize the velocity
    mVelX = 0;
    mVelY = 0;

	location.x = 308;
	location.y = 420;

}


bool BubbleBullet::loadBubbleImage()
{
	bool success = true;

	//Load image
	bubbleImg = SDL_LoadBMP("C:/Users/lab422/Documents/Lab Work/Real World Modelling/B_blue.bmp");

	if(bubbleImg == NULL)
	{
		printf("Unable to load image");
		success = false;
	}
	return success;
}

void BubbleBullet::drawBubble(SDL_Surface* screenSurface)
{
	SDL_BlitSurface(bubbleImg, NULL, screenSurface, &location);
}


void BubbleBullet::handleEvent( SDL_Event& e )
{
    //If a key was pressed
	if( e.type == SDL_KEYDOWN && e.key.repeat == 0 )
    {
        //Adjust the velocity
        switch( e.key.keysym.sym )
        {
		case SDLK_SPACE:
			mVelX = CONSTANTS::DOT_VEL;
			mVelY = -CONSTANTS::DOT_VEL;
			break;
        }
    }
}


void BubbleBullet::move()
{
    //Move the dot left or right
    location.x += mVelX;

    //If the dot went too far to the left or right
    if( (  location.x < 0 ) || (  location.x > CONSTANTS::SCREEN_WIDTH ) )
    {
        //Move back
         location.x -= mVelX;
    }

    //Move the dot up or down
    location.y += mVelY;

    //If the dot went too far up or down
    if( ( location.y < 0 ) || ( location.y +  DOT_HEIGHT > CONSTANTS::SCREEN_HEIGHT ) )
    {
        //Move back
         location.y -= mVelY;
    }
}

BubbleBullet::~BubbleBullet(void)
{
}

void BubbleBullet::setVelocity(int x,int y)
{
	mVelX *= x;
	mVelY *= y;
}
