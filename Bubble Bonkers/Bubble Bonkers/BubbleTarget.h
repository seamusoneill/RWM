#ifndef __BUBBLE_H_INCLUDED__
#define __BUBBLE_H_INCLUDED__
#include <SDL.h>
#include <vector>
#include <SDL_image.h>
#include "CONSTANTS.h"

using namespace std;


class BubbleTarget
{


private:

	SDL_Surface* bubbleImg;
	SDL_Surface* bubbleImg1;

	float posX;
	float posY;
	
	vector<SDL_Surface*> vPhotos;

public:
	vector<SDL_Rect> LocationData;
	vector<SDL_Surface*> PhotosData;
	int m_Size;
	bool m_Display;
	bool m_Animation;

	BubbleTarget();

	bool loadBubbleImage();
	void drawBubble(SDL_Surface*);

	float getRandomPosX();
	float getRandomPosY();
	
	static enum colorController {
		Blue,
		Pink
	};

};


#endif // __BUBBLE_H_INCLUDED__ 