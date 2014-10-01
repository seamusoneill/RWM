#include "LTexture.h"


LTexture::LTexture()
{
	//Initialize
	mTexture = NULL;
	mWidth = 0;
	mHeight = 0;
}

LTexture::~LTexture()
{
	free();
}

bool LTexture::loadFromFile( std::string path, SDL_Renderer* renderer)
{
	//free texture
	free();

	//The final texture
	SDL_Texture* newTexture = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
	if( loadedSurface == NULL )
	{
		printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
	}
	else
	{
		//Color key image
		SDL_SetColorKey( loadedSurface, SDL_TRUE, SDL_MapRGB( loadedSurface->format, 0, 0xFF, 0xFF ) );

		//Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface( renderer, loadedSurface );
		if( newTexture == NULL )
		{
			printf( "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
		}
		else
		{
			//Get image dimensions
			mWidth = loadedSurface->w;
			mHeight = loadedSurface->h;
		}

		//Get rid of old loaded surface
		SDL_FreeSurface( loadedSurface );
	}

	//Return success
	mTexture = newTexture;
	return mTexture != NULL;
}

void LTexture::free()
{
	//Free texture if it exists
	if( mTexture != NULL )
	{
		SDL_DestroyTexture( mTexture );
		mTexture = NULL;
		mWidth = 0;
		mHeight = 0;
	}
}


void LTexture::setBlendMode( SDL_BlendMode blending )
{
	//Set blending function
	SDL_SetTextureBlendMode( mTexture, blending );
}
		

void LTexture::render( int x, int y, SDL_Rect* clip, SDL_Renderer* renderer )
{
	//Set rendering space and render to screen
	SDL_Rect renderQuad = { x, y, mWidth, mHeight };

	//Set clip rendering dimensions
	if( clip != NULL )
	{
		renderQuad.w = clip->w;
		renderQuad.h = clip->h;
	}

	//Render to screen
	SDL_RenderCopy( renderer, mTexture, clip, &renderQuad );
}

//int LTexture::getWidth()
//{
//	return mWidth;
//}
//
//int LTexture::getHeight()
//{
//	return mHeight;
//}

bool LTexture::loadMedia(SDL_Renderer* renderer)
{
	bool sucess = true;

	if(!loadFromFile("bubbles.png",renderer))
	{
		printf("Failed to load animation texture!\n");
		sucess = false;
	}
	else
	{
		gSpriteClips[0].x = 0;
		gSpriteClips[0].y = 0;
		gSpriteClips[0].w = 66;
		gSpriteClips[0].h = 64;

		gSpriteClips[1].x = 66;
		gSpriteClips[1].y = 0;
		gSpriteClips[1].w = 64;
		gSpriteClips[1].h = 64;

		gSpriteClips[2].x = 130;
		gSpriteClips[2].y = 0;
		gSpriteClips[2].w = 66;
		gSpriteClips[2].h = 64;

		gSpriteClips[3].x = 196;
		gSpriteClips[3].y = 0;
		gSpriteClips[3].w = 64;
		gSpriteClips[3].h = 64;

		gSpriteClips[4].x = 260;
		gSpriteClips[4].y = 0;
		gSpriteClips[4].w = 62;
		gSpriteClips[4].h = 64;

		gSpriteClips[5].x = 322;
		gSpriteClips[5].y = 0;
		gSpriteClips[5].w = 60;
		gSpriteClips[5].h = 64;

		gSpriteClips[6].x = 382;//452
		gSpriteClips[6].y = 0;
		gSpriteClips[6].w = 70;
		gSpriteClips[6].h = 64;

	}

	return sucess;
}