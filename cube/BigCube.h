#pragma once
#include "SmallCube.h"

class BigCube
{
private:
	SmallCube a[3][3][3];
	double size;
	unsigned int color[6];
public:
	void draw();
	BigCube();
	BigCube(double size, unsigned int *color);
	void clear(double size, unsigned int *color);
	void rightc();
	void leftcc();
	void upc();
	void downcc();
	void frontc();
	void backcc();
};

