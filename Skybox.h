#pragma once

#ifndef SKYBOX_KEPLAR
#define SKYBOX_KEPLAR

class Skybox
{
	enum
	{
		SKY_LEFT,
		SKY_BACK,
		SKY_RIGHT,
		SKY_FRONT,
		SKY_TOP,
		SKY_BOTTOM
	};

public:	
	unsigned int skybox[6];
	void DrawSkybox(float size);
	void InitSkybox();	
	void KillSkybox();	

};
#endif