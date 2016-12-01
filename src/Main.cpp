#include <GL/glew.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <SDL/SDL.h>
#include <GLFW/glfw3.h>
#include <complex>

#include "Terrain.h"
#include "Vector.h"
#include "Camera.h"
#include "Skybox.h"
#undef main
	
Terrain ter;
Camera cam;
Skybox box;

bool mousein = false;

static void ErrorCallback(int error, const char* description)
{
	fputs(description, stderr);
}

static void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{

}

void Init(float angle)
{
	glClearColor(0, 0, 0, 1);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(angle, 640.0 / 480.0, 1, 1000);
	glMatrixMode(GL_MODELVIEW);
	box.InitSkybox();
	ter.LoadHeightmap("heightmap.bmp");
}

void Display()
{
	glLoadIdentity();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	cam.Control(0.5, 0.2, mousein);
	box.DrawSkybox(60);

	cam.UpdateCamera();
	ter.RenderHeightmap(5.0, 40.0);

}

int main(int argc, char* argv[])
{
	SDL_Init(SDL_INIT_VIDEO);
	SDL_SetVideoMode(1000, 1000, 32, SDL_OPENGL);
	glewInit();
	SDL_WM_SetCaption("Keplar Engine", NULL);
	Uint32 start;
	SDL_Event event;

	Init(50);

	bool running = true;
	float angle = 50;
	bool b = false;

	uint8_t* state = SDL_GetKeyState(NULL);

	while (running)
	{
		start = SDL_GetTicks();

		while (SDL_PollEvent(&event))
		{
			switch (event.type)
			{
			case SDL_QUIT:
				running = false;
				break;
			case SDL_MOUSEBUTTONDOWN:
				mousein = true;
				SDL_ShowCursor(SDL_DISABLE);
				break;
			case SDL_KEYDOWN:
				if (event.key.keysym.sym == SDLK_p)
				{
					mousein = false;
					SDL_ShowCursor(SDL_ENABLE);
					break;
				}
				if (event.key.keysym.sym == SDLK_ESCAPE)
				{
					running = false;
					break;
				}
			}
		}

		if (state[SDLK_LSHIFT])
		{
			cam.Control(0.9, 0.2, mousein);
		}

		SDL_GL_SwapBuffers();
		Display();
	}

	SDL_Quit();
	 
	box.KillSkybox();
	ter.DeleteHeightmap();
}