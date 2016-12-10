
#include <stdio.h>
#include <string.h>
#include <GL\glew.h>
#include <GL\freeglut.h>

class SmallCube
{
private:
	unsigned int color[6]; // (����, ���, �������, �����, ����, �����)
	unsigned char buffercolor[3];
	double size;
public:
	SmallCube();

	void setColor(int i, int color);
	unsigned char *dividecolor(int i);
	void draw();

};





