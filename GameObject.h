#pragma once

#include <GL/glew.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <SDL/SDL.h>
#include <GLFW/glfw3.h>

#include "Vector.h"

class GameObject
{
public:
	bool hasDepth;
	Vec3 size;
	Vec3 gOPos;
	Vec3 axis;
	bool HasDepth();
	void SetColor(float r, float g, float b);
	Vec3 GetPos();
	Vec3 GetSize();
};