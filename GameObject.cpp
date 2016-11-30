#include <GL/glew.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <SDL/SDL.h>
#include <GLFW/glfw3.h>

#include "Vector.h"
#include "GameObject.h"

bool GameObject::HasDepth()
{
	if (axis.z == NULL)
	{
		hasDepth = false;
	}
}

void GameObject::SetColor(float r, float g, float b)
{
	glColor3f(r, g, b);
}

Vec3 GameObject::GetSize()
{
	return size;
}

Vec3 GameObject::GetPos()
{
	return gOPos;
}