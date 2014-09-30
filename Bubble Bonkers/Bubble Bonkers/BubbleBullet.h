#ifndef _BUBBLEBULLET_H_
#define _BUBBLEBULLET_H_

#include <SDL.h>
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

		
	static const int SCREEN_WIDTH = 800;
	static const int SCREEN_HEIGHT = 600;

	//The dimensions of the dot
	static const int DOT_WIDTH = 20;
	static const int DOT_HEIGHT = 20;
	
	//Maximum axis velocity of the dot
	static const int DOT_VEL = 10;

	//Initializes the variables
        
	//Takes key presses and adjusts the dot's velocity
	void handleEvent( SDL_Event& e );

	//Moves the dot
	void move();

	//Shows the dot on the screen
	void render();
	
	int mPosX, mPosY;

private:
	//The X and Y offsets of the dot
       

	//The velocity of the dot
	int mVelX, mVelY;
};
#endif