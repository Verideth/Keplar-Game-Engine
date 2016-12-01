#pragma once

#include <GL/glew.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <SDL/SDL.h>

class TextureLoader
{	
public:
	unsigned int LoadTexture(const char* filename)
	{
		SDL_Surface* img = SDL_LoadBMP(filename);
		unsigned int id;
		glGenTextures(1, &id);
		glBindTexture(GL_TEXTURE_2D, id);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img->w, img->h, 0, GL_RGB, GL_UNSIGNED_BYTE, img->pixels);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		SDL_FreeSurface(img);
		return id;
	}
};
