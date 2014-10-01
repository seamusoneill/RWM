#ifndef __LTEXTURE_H_INCLUDED__
#define __LTEXTURE_H_INCLUDED__
#include <SDL.h>
#include <string>
#include <SDL_image.h>

class LTexture
{
	public:
		//Initializes variables
		LTexture();

		//Deallocates memory
		~LTexture();

		//Loads image at specified path
		bool loadFromFile( std::string path, SDL_Renderer* renderer = NULL );

		//Deallocates texture
		void free();

		//Set blending
		void setBlendMode( SDL_BlendMode blending );
		
		//Renders texture at given point
		void render( int x, int y, SDL_Rect* clip = NULL, SDL_Renderer* renderer = NULL );

		//int getWidth();
		//int getHeight();

		bool loadMedia(SDL_Renderer* renderer);

    public:
		//The actual hardware texture
		SDL_Texture* mTexture;
		SDL_Rect gSpriteClips[7];

		//Image dimensions
		int mWidth;
		int mHeight;
};


#endif // __LTEXTURE_H_INCLUDED__