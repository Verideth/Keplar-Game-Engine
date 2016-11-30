#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <stdio.h>
#include <iostream>
#include <vector>

#include "Terrain.h"
#include "LoadTexture.h"
#include "Vector.h"

TextureLoader loader;

Terrain::Terrain()
{

}

Terrain::~Terrain()
{

}

void Terrain::LoadHeightmap(const char* name)
{
	SDL_Surface* img = SDL_LoadBMP(name);
	if (!img)
	{
		printf("Image is not loaded\n");
		return;
	}
	std::vector<float> tmp;
	for (int i = 0; i < img->h; i++)
	{
		tmp.clear();
		for (int j = 0; j < img->w; j++)
		{
			Uint32 pixel = ((Uint32*)img->pixels)[i * img->pitch / 4 + j];
			Uint8 r;
			Uint8 g;
			Uint8 b;
			SDL_GetRGB(pixel, img->format, &r, &g, &b);
			tmp.push_back((float)r / 255.0);	//0.0,1.0
		}

		height.push_back(tmp);
	}
}

void Terrain::RenderHeightmap(float size, float h)
{	
	for (int i = 0; i < height.size() - 1; i++)
	{
		glBegin(GL_TRIANGLE_STRIP);

		for (int j = 1; j < height[0].size(); j++)
		{
			glColor3f(height[i][j], height[i][j], height[i][j]);
			glColor3f(height[i][j], height[i][j], height[i][j]);
			glVertex3f(i*size, height[i][j] * h, j*size);
			glVertex3f((i + 1)*size, height[i + 1][j] * h, j*size);
			glVertex3f(i*size, height[i][j + 1] * h, (j + 1)*size);
			glVertex3f((i + 1)*size, height[i + 1][j + 1] * h, (j + 1)*size);
		}

		glEnd();
	}
}

void Terrain::DeleteHeightmap()
{
	glDeleteTextures(1, &texture[TERRAIN_GRASS]);
}

float Terrain::GetPos()
{
	return (terPos.x && terPos.y && terPos.z);
}