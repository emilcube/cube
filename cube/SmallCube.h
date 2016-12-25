#pragma once
#include <stdio.h>
#include <string.h>
#include <GL\glew.h>
#include <GL\freeglut.h>

class SmallCube
{
private:
	unsigned int color[6]; // (верх, низ, спереди, сзади, лево, право)
	unsigned char buffercolor[3];
public:
	double size;
	SmallCube();
	void setColor(int i, int color);
	unsigned char *dividecolor(int i);
	void draw();
	void draw(double x, double y, double z);
};





