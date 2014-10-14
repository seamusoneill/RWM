#include "LTexture.h"

LTexture::LTexture()
{
	//Initialize
	m_texture = NULL;
	m_width = 0;
	m_height = 0;
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
			m_width = loadedSurface->w;
			m_height = loadedSurface->h;
		}

		//Get rid of old loaded surface
		SDL_FreeSurface( loadedSurface );
	}

	//Return success
	m_texture = newTexture;
	return m_texture != NULL;
}

bool LTexture::loadFromRenderedText (std::string textureText, SDL_Color textColor, SDL_Renderer* renderer)
{
	//Get rid of preexisting texture
	free();

	//REmder text surface
	SDL_Surface* textSurface = TTF_RenderText_Solid(g_font, textureText.c_str(), textColor);
	if (textSurface == NULL)
	{
		printf("Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError() );
    }
    else
	{
		//Create texture from surface pixels
		m_texture = SDL_CreateTextureFromSurface(renderer,textSurface);
		if (m_texture == NULL)
		{
			printf("");
		}
		else
		{
			//Get image dimensions
			m_width = textSurface->w;
			m_height = textSurface->h;
		}

		//Getrid of old surface
		SDL_FreeSurface (textSurface);
	}

	//Return success
	return m_texture != NULL;
}

void LTexture::free()
{
	//Free texture if it exists
	if( m_texture != NULL )
	{
		SDL_DestroyTexture( m_texture );
		m_texture = NULL;
		m_width = 0;
		m_height = 0;
	}
}


void LTexture::setBlendMode( SDL_BlendMode blending )
{
	//Set blending function
	SDL_SetTextureBlendMode( m_texture, blending );
}
		

void LTexture::render( int x, int y, SDL_Rect* clip, SDL_Renderer* renderer )
{
	//Set rendering space and render to screen
	SDL_Rect renderQuad = { x, y, m_width, m_height };

	//Set clip rendering dimensions
	if( clip != NULL )
	{
		renderQuad.w = clip->w;
		renderQuad.h = clip->h;
	}
	
	//Render to screen
	SDL_RenderCopy( renderer, m_texture, clip, &renderQuad );
}

bool LTexture::loadMedia(SDL_Renderer* renderer)
{
	bool success = true;
/*
	//Open the font
    g_font = TTF_OpenFont( "", 28 );
    if( g_font == NULL )
    {
        printf( "Failed to load lazy font! SDL_ttf Error: %s\n", TTF_GetError() );
        success = false;
    }
    else
    {
        //Render text
        SDL_Color textColor = { 0, 0, 0 };
    }

	*/
	return success;
}
