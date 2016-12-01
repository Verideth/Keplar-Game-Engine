#pragma once

#ifndef SKYBOX_KEPLAR
#define SKYBOX_KEPLAR

// I followed a article on how to make a skybox in OpenGL
// I cannot find it, as I haven't worked on this in ~4 months
// This is credits to him

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
