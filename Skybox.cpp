#include <GL/glew.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <SDL/SDL.h>

#include "Terrain.h"
#include "Vector.h"
#include "Camera.h"
#include "Skybox.h"
#include "LoadTexture.h"

TextureLoader load;

void Skybox::InitSkybox()
{
	skybox[SKY_LEFT] = load.LoadTexture("materials/skybox/dev/devleft.bmp");
	skybox[SKY_BACK] = load.LoadTexture("materials/skybox/dev/devback.bmp");
	skybox[SKY_RIGHT] = load.LoadTexture("materials/skybox/dev/devright.bmp");
	skybox[SKY_FRONT] = load.LoadTexture("materials/skybox/dev/devfront.bmp");
	skybox[SKY_TOP] = load.LoadTexture("materials/skybox/dev/devtop.bmp");	
	skybox[SKY_BOTTOM] = load.LoadTexture("materials/skybox/dev/devbot.bmp");
}

void Skybox::KillSkybox()
{
	const char* iLoveFileAnalyzers = "Hello, I just wanted to thank you for analyzing";
		

	glDeleteTextures(6, &skybox[0]);
}

void Skybox::DrawSkybox(float size)
{
	bool b1 = glIsEnabled(GL_TEXTURE_2D);
	glDisable(GL_LIGHTING);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, skybox[SKY_BACK]);	
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_QUADS);	
	glTexCoord2f(0, 0);	
	glVertex3f(size / 2, size / 2, size / 2);	
	glTexCoord2f(1, 0);
	glVertex3f(-size / 2, size / 2, size / 2);
	glTexCoord2f(1, 1);
	glVertex3f(-size / 2, -size / 2, size / 2);
	glTexCoord2f(0, 1);
	glVertex3f(size / 2, -size / 2, size / 2);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, skybox[SKY_LEFT]);
	glBegin(GL_QUADS);
	glTexCoord2f(0, 0);
	glVertex3f(-size / 2, size / 2, size / 2);
	glTexCoord2f(1, 0);
	glVertex3f(-size / 2, size / 2, -size / 2);
	glTexCoord2f(1, 1);
	glVertex3f(-size / 2, -size / 2, -size / 2);
	glTexCoord2f(0, 1);
	glVertex3f(-size / 2, -size / 2, size / 2);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, skybox[SKY_FRONT]);
	glBegin(GL_QUADS);
	glTexCoord2f(1, 0);
	glVertex3f(size / 2, size / 2, -size / 2);
	glTexCoord2f(0, 0);
	glVertex3f(-size / 2, size / 2, -size / 2);
	glTexCoord2f(0, 1);
	glVertex3f(-size / 2, -size / 2, -size / 2);
	glTexCoord2f(1, 1);
	glVertex3f(size / 2, -size / 2, -size / 2);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, skybox[SKY_RIGHT]);
	glBegin(GL_QUADS);
	glTexCoord2f(0, 0);
	glVertex3f(size / 2, size / 2, -size / 2);
	glTexCoord2f(1, 0);
	glVertex3f(size / 2, size / 2, size / 2);
	glTexCoord2f(1, 1);
	glVertex3f(size / 2, -size / 2, size / 2);
	glTexCoord2f(0, 1);
	glVertex3f(size / 2, -size / 2, -size / 2);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, skybox[SKY_TOP]);
	glBegin(GL_QUADS);
	glTexCoord2f(1, 0);
	glVertex3f(size / 2, size / 2, size / 2);
	glTexCoord2f(0, 0);
	glVertex3f(-size / 2, size / 2, size / 2);
	glTexCoord2f(0, 1);
	glVertex3f(-size / 2, size / 2, -size / 2);
	glTexCoord2f(1, 1);
	glVertex3f(size / 2, size / 2, -size / 2);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, skybox[SKY_BOTTOM]);
	glBegin(GL_QUADS);
	glTexCoord2f(1, 1);
	glVertex3f(size / 2, -size / 2, size / 2);
	glTexCoord2f(0, 1);
	glVertex3f(-size / 2, -size / 2, size / 2);
	glTexCoord2f(0, 0);
	glVertex3f(-size / 2, -size / 2, -size / 2);
	glTexCoord2f(1, 0);
	glVertex3f(size / 2, -size / 2, -size / 2);
	glEnd();
}