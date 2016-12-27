#pragma once
#include "SmallCube.h"
#include <stdio.h>
#include <string.h>


SmallCube::SmallCube()
{
	//size = 5.0;
	//color[0] = 0xFFFFFF;//вверх-белый
	//color[1] = 0xFFFF00;//низ-желтый
	//color[2] = 0x0000FF;//спереди-синий
	//color[3] = 0x00FF00;//сзади-зеленый
	//color[4] = 0xFF0000;//лево-красный
	//color[5] = 0xFF9900;//право-оранжевый

	memset(color, 0, sizeof(color));
	size = 0.0;
}


void SmallCube::setColor(int i, int color)
{
	this->color[i] = color;
}

int SmallCube::getColor(int i)
{
	return color[i];
}

unsigned char *SmallCube::dividecolor(int i)
{
	buffercolor[0] = color[i] >> 16;
	buffercolor[1] = color[i] >> 8;
	buffercolor[2] = color[i];
	return buffercolor;
}

void SmallCube::draw()
{
	glPushMatrix();
	glBegin(GL_QUADS);

	// верх
	glColor3ubv(dividecolor(0));
	glNormal3f(0, 0, 1);
	glVertex3f(size, size, size);
	glVertex3f(0, size, size);
	glVertex3f(0, 0, size);
	glVertex3f(size, 0, size);

	// низ
	glColor3ubv(dividecolor(1));
	glNormal3f(0, 0, -1);
	glVertex3f(size, 0, 0);
	glVertex3f(0, 0, 0);
	glVertex3f(0, size, 0);
	glVertex3f(size, size, 0);

	// спереди
	glColor3ubv(dividecolor(2));
	glNormal3f(0, -1, 0);
	glVertex3f(size, 0, size);
	glVertex3f(0, 0, size);
	glVertex3f(0, 0, 0);
	glVertex3f(size, 0, 0);

	// сзади
	glColor3ubv(dividecolor(3));
	glNormal3f(0, 1, 0);
	glVertex3f(size, size, 0);
	glVertex3f(0, size, 0);
	glVertex3f(0, size, size);
	glVertex3f(size, size, size);

	// слева
	glColor3ubv(dividecolor(4));
	glNormal3f(-1, 0, 0);
	glVertex3f(0, size, size);
	glVertex3f(0, size, 0);
	glVertex3f(0, 0, 0);
	glVertex3f(0, 0, size);

	// справа
	glColor3ubv(dividecolor(5));
	glNormal3f(1, 0, 0);
	glVertex3f(size, size, 0);
	glVertex3f(size, size, size);
	glVertex3f(size, 0, size);
	glVertex3f(size, 0, 0);

	glEnd();
	glPopMatrix();
}

void SmallCube::draw(double x, double y, double z)
{
	glPushMatrix();
	glTranslated(x, y, z);
	draw();
	glPopMatrix();
}







