#pragma once

#ifndef VEC3_KEPLAR
#define VEC3_KEPLAR

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <ostream>
#include <SDL/SDL.h>

class Vec3
{
public:
	float x;
	float y;
	float z;
	Vec3();
	Vec3(float xPos, float yPos);
	Vec3(float xPos, float yPos, float zPos);

	float DotProduct(const Vec3& vec2);
	Vec3 CrossProduct(const Vec3& vec2);
	float Length();
	void Normalize();
	void Change(float x, float y, float z);
	void Change(Vec3& vec2);
	void Change(Vec3 vec2);
	void ChangeX(float x);
	void ChangeY(float y);
	void ChangeZ(float z);

	Vec3 operator+(const Vec3& vec2);
	Vec3 operator-(const Vec3& vec2);
	Vec3 operator*(float num);
	Vec3 operator/(float num);

	Vec3 operator+=(const Vec3& vec2);
	Vec3 operator-=(const Vec3& vec2);
	Vec3 operator*=(float num);
	Vec3 operator/=(float num);

	bool operator==(const Vec3 vec2);
	bool operator!=(const Vec3 vec2);

	std::ostream& operator<<(std::ostream& out, const Vec3& vec);
};

#endif
