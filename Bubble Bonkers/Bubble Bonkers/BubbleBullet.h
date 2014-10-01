#ifndef _BUBBLEBULLET_H_
#define _BUBBLEBULLET_H_

#include <SDL.h>
#include "CONSTANTS.h"

class BubbleBullet
{

public:
	BubbleBullet();
	~BubbleBullet(void);

	SDL_Rect location;

	bool loadBubbleImage();
	void drawBubble(SDL_Surface*);
	//Texture gDotTexture;
	SDL_Surface* bubbleImg;
	
	//The dimensions of the dot
	static const int DOT_WIDTH = 96;
	static const int DOT_HEIGHT = 95;
	


	//Takes key presses and adjusts the dot's velocity
	void handleEvent( SDL_Event& e );

	//Moves the dot
	void move();

	//Shows the dot on the screen
	void render();
	
	int mPosX, mPosY;
	
	static enum colorController {
		Blue,
		Pink
	};

	void setVelocity(int, int);

private:

	//The velocity of the dot
	float mVelX, mVelY;
};
#endif