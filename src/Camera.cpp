#include <GL/glew.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <SDL/SDL.h>
#include <GLFW/glfw3.h>

#include "Camera.h"

float camX = 0.0, camY = 0.0, camZ = 5.0;   
float camYaw = 0.0;   
float camPitch = 0.0;   

#ifndef M_PI   
#define M_PI 3.1415926535     
#endif

Camera::Camera()
{

}

void Camera::LockCamera()
{
	if (camPitch > 90)
	{	
		camPitch = 90;
	}
	
	if (camPitch < -90)
	{	
		pamPitch = -90;
	}
	
	if (camYaw < 0.0)
	{	
		camYaw += 360.0;
	}
	
	if (camYaw>360.0)
	{	
		camYaw -= 360;
	}
}

void Camera::MoveCamera(float dist, float dir)
{
	float rad = (camYaw + dir)*M_PI / 180.0; 
	camX -= sin(rad)*dist; 
	camZ -= cos(rad)*dist;   
}

void Camera::MoveCameraUp(float dist, float dir)
{
	
	float rad = (camPitch + dir) * M_PI / 180.0;
	camY += sin(rad)*dist;
}

void Camera::Control(float movevel, float mousevel, bool mi)
{
	if (mi)
	{
		int MidX = 320;
		int MidY = 240;

		SDL_ShowCursor(SDL_DISABLE);

		int tmpx;
		int tmpy;

		SDL_GetMouseState(&tmpx, &tmpy);
		camYaw += mousevel * (MidX - tmpx);
		camPitch += mousevel * (MidY - tmpy);

		LockCamera();

		SDL_WarpMouse(MidX, MidY);
		Uint8* state = SDL_GetKeyState(NULL);

		if (state[SDLK_w])
		{
			if (camPitch != 90 && camPitch != -90)
			{
				MoveCamera(movevel, 0.0);
			}

			MoveCameraUp(movevel, 0.0);
		}
		else if (state[SDLK_s])
		{
			if (camPitch != 90 && camPitch != -90)
			{
				MoveCamera(movevel, 180.0);
			}

			MoveCameraUp(movevel, 180.0);
		}

		if (state[SDLK_a])
		{
			MoveCamera(movevel, 90.0);
		}
		else if (state[SDLK_d])
		{
			MoveCamera(movevel, 270);
		}
	}

	glRotatef(-camPitch, 1.0, 0.0, 0.0);
	glRotatef(-camYaw, 0.0, 1.0, 0.0);
}

void Camera::UpdateCamera()
{
	glTranslatef(-camX, -camY, -camZ);
}

void Camera::MouseIn(bool b)
{
	mI = b;
}
