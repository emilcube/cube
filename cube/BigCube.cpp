#pragma once
#include "BigCube.h"

BigCube::BigCube()
{
}

BigCube::BigCube(double size, unsigned int *color)
{
	clear(size, color);
}

void BigCube::clear(double size, unsigned int *color)
{
	this->size = size;

	int i, j, k;
	for (i = 0; i < 6; i++)
		this->color[i] = color[i];

	// верх
	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			a[i][j][2].setColor(0, color[0]);

	// низ
	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			a[i][j][0].setColor(1, color[1]);

	// спереди
	for (k = 0; k < 3; k++)
		for (j = 0; j < 3; j++)
			a[j][0][k].setColor(2, color[2]);

	// сзади
	for (k = 0; k < 3; k++)
		for (j = 0; j < 3; j++)
			a[j][2][k].setColor(3, color[3]);

	// слева
	for (i = 0; i < 3; i++)
		for (k = 0; k < 3; k++)
			a[0][k][i].setColor(4, color[4]);

	// справа
	for (i = 0; i < 3; i++)
		for (k = 0; k < 3; k++)
			a[2][k][i].setColor(5, color[5]);

	// устанавливаем размеры мелких деталей
	// это будет треть всего размера, умноженная на коэффициент немного меньший еденицы
	// (чтобы детали не были слишком плотно)
	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			for (k = 0; k < 3; k++)
				a[i][j][k].size = (size / 3.0) * 0.98;
}


void BigCube::draw()
{
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			for (int k = 0; k < 3; k++)
					a[i][j][k].draw(size / 3 * i, size / 3 * j, size / 3 * k);
}
