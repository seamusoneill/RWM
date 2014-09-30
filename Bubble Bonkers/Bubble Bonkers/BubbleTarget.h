#ifndef __BUBBLE_H_INCLUDED__
#define __BUBBLE_H_INCLUDED__
#include <SDL.h>
#include <vector>
#include "CONSTANTS.h"
using namespace std;


class BubbleTarget
{
	static enum colorController {Blue, Pink};
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


public:
	

	BubbleTarget();

	bool loadBubbleImage();
	void drawBubble(SDL_Surface*);

	float getRandomPosX();
	float getRandomPosY();
};


#endif // __BUBBLE_H_INCLUDED__ 