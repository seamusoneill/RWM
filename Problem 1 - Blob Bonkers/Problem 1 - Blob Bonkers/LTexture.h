#ifndef __LTEXTURE_H_INCLUDED__
#define __LTEXTURE_H_INCLUDED__
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include <string>
#include "CONSTANTS.h"

class LTexture
{
	public:
		//Initializes variables
		LTexture();

		//Deallocates memory
		~LTexture();

		//Loads image at specified path
		bool loadFromFile( std::string path, SDL_Renderer* renderer = NULL );

		//Creates image from font string
		bool loadFromRenderedText (std::string textureText, SDL_Color textColor, SDL_Renderer* renderer = NULL  );
		
		//Deallocates texture
		void free();

		//Set blending
		void setBlendMode( SDL_BlendMode blending );
		
		//Renders texture at given point
		void render( int x, int y, SDL_Rect* clip = NULL, SDL_Renderer* renderer = NULL );
		
		bool loadMedia(SDL_Renderer* renderer);


	    public:
		//The actual hardware texture
		SDL_Texture* m_texture;
		SDL_Rect g_spriteClips[7];

		//Globally used font
		TTF_Font* g_font;
		
		//Image dimensions
		int m_width;
		int m_height;
};
#endif // __LTEXTURE_H_INCLUDED__