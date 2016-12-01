#pragma once

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <vector>
#include <iostream>

#include "Vector.h"

class Terrain
{
	enum
	{
		TERRAIN_GRASS,
		TERRAIN_DESERT,
		TERRAIN_SNOW,
		TERRAIN_JUNGLE
	};

public:
	Terrain();
	~Terrain();
	Vec3 terPos;
	unsigned int texture[3];
	void LoadHeightmap(const char* name);
	void RenderHeightmap(float size, float h);
	void DeleteHeightmap();
	float GetPos();

private:
	float width;
	float length;

	std::vector<std::vector<float>> height;
};