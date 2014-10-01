#include "BubbleTarget.h"
#include <random>
#include <iostream>
#include <time.h>

using namespace std;


BubbleTarget::BubbleTarget()
{
	srand ( time(NULL) );
	m_Size = 0;
	m_Animation = false;
}

bool BubbleTarget::loadBubbleImage()
{
	bool success = true;
	
	//Load image
	bubbleImg = IMG_Load("C:/Users/lab422/Documents/Lab Work/Real World Modelling/B_blue.png");
	if(bubbleImg)
		vPhotos.push_back(bubbleImg);
	
	bubbleImg1 = IMG_Load("C:/Users/Lab422/Documents/Lab Work/Real World Modelling/B_pink.png");
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
			m_Animation = true;
		}
			

		for (int i=0;i<m_Size;i++)
		{
			SDL_BlitSurface( PhotosData[i], NULL, screenSurface, &LocationData[i] );
		}
	}
}



float BubbleTarget::getRandomPosX()
{	
	float val = rand() % 480 + 54;

	return val;
}
float BubbleTarget::getRandomPosY()
{	
	float val = rand() % 405 - 1;

	return val;
}