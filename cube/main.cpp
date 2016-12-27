#pragma once
#include "SmallCube.h"
#include "BigCube.h"
#include <time.h>
#include <stdlib.h>
#include <iostream>
#define CUBE_SIZE 13
using namespace std;

//                    (верх,      низ,   впереди,   сзади,    лево,      право)
unsigned int c[9] = { 0xFFFFFF, 0xFFFF00, 0x0000FF, 0x00FF00, 0xFF0000, 	0xCD853F };
int xRot = 30, yRot = 30, zRot = 0;
double translateZ = -45.0;
BigCube cube;

void display()
{
	glPushMatrix();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glTranslatef(0, 0, translateZ);
	glRotatef(xRot, 1, 0, 0);
	glRotatef(yRot, 0, 1, 0);
	cube.draw();
	glPopMatrix();
	glutSwapBuffers();
}

void reshape(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	GLfloat fAspect = (GLfloat)w / (GLfloat)h;
	gluPerspective(60, fAspect, 1, 1000.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void specialKeys(int key, int, int)
{
	if (key == GLUT_KEY_RIGHT)
	{
		yRot += 3;
		if (yRot >= 360)
			yRot -= 360;
		glutPostRedisplay();
	}

	if (key == GLUT_KEY_LEFT)
	{
		yRot -= 3;
		if (yRot < 0)
			yRot += 360;
		glutPostRedisplay();
	}
	if (key == GLUT_KEY_DOWN)
	{
		xRot += 3;
		if (xRot >= 360)
			xRot -= 360;
		glutPostRedisplay();
	}

	if (key == GLUT_KEY_UP)
	{
		xRot -= 3;
		if (xRot < 0)
			xRot += 360;
		glutPostRedisplay();
	}

	if (key == GLUT_KEY_F1) {cube.rightc();}
	if (key == GLUT_KEY_F2) {cube.leftcc();}
	if (key == GLUT_KEY_F3) {cube.upc();}
	if (key == GLUT_KEY_F4) {cube.downcc();}
	if (key == GLUT_KEY_F5) {cube.frontc(); }
	if (key == GLUT_KEY_F6) {cube.backcc(); }
}

int main(int argc, char **argv)
{
	cout << "Hello" << endl << "This is simulation of the Rubik's Cube" << endl;
	cout << "To rotate cube, enter arrows: left, right, up, down" << endl;
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(800, 700);
	glutInitWindowPosition(200, 0);
	glutCreateWindow("Rubics Cube");
	cube.clear(CUBE_SIZE, c);
	glEnable(GL_DEPTH_TEST);
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutSpecialFunc(specialKeys);
	glutMainLoop();
	return 0;
}


