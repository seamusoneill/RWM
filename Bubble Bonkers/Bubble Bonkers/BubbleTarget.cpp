#include "BubbleTarget.h"
#include <random>
#include <iostream>

using namespace std;


BubbleTarget::BubbleTarget()
{
	m_Size = 0;
}

bool BubbleTarget::loadBubbleImage()
{
	bool success = true;

	//Load image
	bubbleImg = SDL_LoadBMP("B_blue.bmp");
	if(bubbleImg)
		vPhotos.push_back(bubbleImg);
	
	bubbleImg1 = SDL_LoadBMP("B_pink.bmp");
	if(bubbleImg1)
		vPhotos.push_back(bubbleImg1);

	if(bubbleImg == NULL || bubbleImg1 == NULL)
	{
		printf("Unable to load image");
		success = false;
	}
	return success;
}

void BubbleTarget::drawBubble(SDL_Surface* screenSurface)
{
	if(m_Size ==0)
		m_Display = true;
	if(m_Size == 10)
		m_Display = false;


	if (m_Display)
	{
		SDL_Rect location = {getRandomPosX(),getRandomPosY(),0,0};

		LocationData.push_back(location);

		int val = rand()% 2;
		PhotosData.push_back(vPhotos[val]);
		//Apply the image 
		m_Size = LocationData.size();

		for (int i=0;i<m_Size;i++)
		{
			SDL_BlitSurface( PhotosData[i], NULL, screenSurface, &LocationData[i] );
		}

	}
	else if(!m_Display)
	{
		m_Size--;
		if(m_Size == 0)
		{
			LocationData.clear();
			PhotosData.clear();
		}
			

		for (int i=0;i<m_Size;i++)
		{
			SDL_BlitSurface( PhotosData[i], NULL, screenSurface, &LocationData[i] );
		}
	}


	//SDL_RendererFlip(screenSurface);
}



float BubbleTarget::getRandomPosX()
{	
	float val = rand() % CONSTANTS::SCREEN_WIDTH + 1;

	return val;
}
float BubbleTarget::getRandomPosY()
{	
	float val = rand() % CONSTANTS::SCREEN_HEIGHT + 1;

	return val;
}