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
				a[i][j][k].setSize((size / 3.0) * 0.98);
}


void BigCube::draw()
{
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			for (int k = 0; k < 3; k++)
					a[i][j][k].draw(size / 3 * i, size / 3 * j, size / 3 * k);
}

void BigCube::rightc()
{
	int p, n, m, k, z, x;
	p = a[2][0][2].getColor(0);
	a[2][0][2].setColor(0, a[2][0][0].getColor(2));
	z = a[2][0][2].getColor(5);
	a[2][0][2].setColor(5, a[2][0][0].getColor(5));

	n= a[2][2][2].getColor(3);
	a[2][2][2].setColor(3, p);
	x=a[2][2][2].getColor(5);
	a[2][2][2].setColor(5, z);

	p= a[2][2][0].getColor(1);
	a[2][2][0].setColor(1, n);
	z = a[2][2][0].getColor(5);
	a[2][2][0].setColor(5, x);

	a[2][0][0].setColor(2, p);
	a[2][0][0].setColor(5, z);

	p = a[2][0][2].getColor(2);
	a[2][0][2].setColor(2, a[2][0][0].getColor(1));

	n = a[2][2][2].getColor(0);
	a[2][2][2].setColor(0, p);

	p = a[2][2][0].getColor(3);
	a[2][2][0].setColor(3, n);

	a[2][0][0].setColor(1, p);

	p=a[2][1][2].getColor(0); n=a[2][1][2].getColor(5);
	a[2][1][2].setColor(0, a[2][0][1].getColor(2));
	a[2][1][2].setColor(5, a[2][0][1].getColor(5));

	m = a[2][2][1].getColor(3); k = a[2][2][1].getColor(5);
	a[2][2][1].setColor(3,p);
	a[2][2][1].setColor(5,n);

	p = a[2][1][0].getColor(1); n = a[2][1][0].getColor(5);
	a[2][1][0].setColor(1,m);
	a[2][1][0].setColor(5,k);

	a[2][0][1].setColor(2, p);
	a[2][0][1].setColor(5, n);
}

void BigCube::leftcc()
{
	int p, n, m, k, z, x;
	p = a[0][0][2].getColor(0);
	a[0][0][2].setColor(0, a[0][0][0].getColor(2));
	z= a[0][0][2].getColor(4);
	a[0][0][2].setColor(4, a[0][0][0].getColor(4));

	n = a[0][2][2].getColor(3);
	a[0][2][2].setColor(3, p);
	x= a[0][2][2].getColor(4);
	a[0][2][2].setColor(4, z);

	p = a[0][2][0].getColor(1);
	a[0][2][0].setColor(1, n);
	z= a[0][2][0].getColor(4);
	a[0][2][0].setColor(4, x);

	a[0][0][0].setColor(2, p);
	a[0][0][0].setColor(4, z);

	p = a[0][0][2].getColor(2);
	a[0][0][2].setColor(2, a[0][0][0].getColor(1));

	n = a[0][2][2].getColor(0);
	a[0][2][2].setColor(0, p);

	p = a[0][2][0].getColor(3);
	a[0][2][0].setColor(3, n);

	a[0][0][0].setColor(1, p);

	p = a[0][1][2].getColor(0); n = a[0][1][2].getColor(4);
	a[0][1][2].setColor(0, a[0][0][1].getColor(2));
	a[0][1][2].setColor(4, a[0][0][1].getColor(4));

	m = a[0][2][1].getColor(3); k = a[0][2][1].getColor(4);
	a[0][2][1].setColor(3, p);
	a[0][2][1].setColor(4, n);

	p = a[0][1][0].getColor(1); n = a[0][1][0].getColor(4);
	a[0][1][0].setColor(1, m);
	a[0][1][0].setColor(4, k);

	a[0][0][1].setColor(2, p);
	a[0][0][1].setColor(4, n);
}

void BigCube::upc()
{
	int p, n, m, k, z, x;
	p = a[0][2][2].getColor(3);
	a[0][2][2].setColor(3, a[0][0][2].getColor(4));
	z = a[0][2][2].getColor(0);
	a[0][2][2].setColor(0, a[0][0][2].getColor(0));

	n = a[2][2][2].getColor(5);
	a[2][2][2].setColor(5, p);
	x = a[2][2][2].getColor(0);
	a[2][2][2].setColor(0, z);

	p = a[2][0][2].getColor(2);
	a[2][0][2].setColor(2, n);
	z = a[2][0][2].getColor(0);
	a[2][0][2].setColor(0, x);

	a[0][0][2].setColor(4, p);
	a[0][0][2].setColor(0, z);

	p = a[0][2][2].getColor(4);
	a[0][2][2].setColor(4, a[0][0][2].getColor(2));

	n = a[2][2][2].getColor(3);
	a[2][2][2].setColor(3, p);

	p = a[2][0][2].getColor(5);
	a[2][0][2].setColor(5, n);

	a[0][0][2].setColor(2,p);

	p = a[1][2][2].getColor(3); n = a[1][2][2].getColor(0);
	a[1][2][2].setColor(3, a[0][1][2].getColor(4));
	a[1][2][2].setColor(0, a[0][1][2].getColor(0));

	m = a[2][1][2].getColor(5); k = a[2][1][2].getColor(0);
	a[2][1][2].setColor(5, p);
	a[2][1][2].setColor(0, n);

	p = a[1][0][2].getColor(2); n = a[1][0][2].getColor(0);
	a[1][0][2].setColor(2, m);
	a[1][0][2].setColor(0, k);

	a[0][1][2].setColor(4, p);
	a[0][1][2].setColor(0, n);
}

void BigCube::downcc()
{
	int p, n, m, k, z, x;
	p = a[0][2][0].getColor(3);
	a[0][2][0].setColor(3, a[0][0][0].getColor(4));
	z = a[0][2][0].getColor(1);
	a[0][2][0].setColor(1, a[0][0][0].getColor(1));

	n = a[2][2][0].getColor(5);
	a[2][2][0].setColor(5, p);
	x = a[2][2][0].getColor(1);
	a[2][2][0].setColor(1, z);

	p = a[2][0][0].getColor(2);
	a[2][0][0].setColor(2, n);
	z = a[2][0][0].getColor(1);
	a[2][0][0].setColor(1, x);

	a[0][0][0].setColor(4, p);
	a[0][0][0].setColor(1, z);

	p = a[0][2][0].getColor(4);
	a[0][2][0].setColor(4, a[0][0][0].getColor(2));

	n = a[2][2][0].getColor(3);
	a[2][2][0].setColor(3, p);

	p = a[2][0][0].getColor(5);
	a[2][0][0].setColor(5, n);

	a[0][0][0].setColor(2, p);

	p = a[1][2][0].getColor(3); n = a[1][2][0].getColor(1);
	a[1][2][0].setColor(3, a[0][1][0].getColor(4));
	a[1][2][0].setColor(1, a[0][1][0].getColor(1));

	m = a[2][1][0].getColor(5); k = a[2][1][0].getColor(1);
	a[2][1][0].setColor(5, p);
	a[2][1][0].setColor(1, n);

	p = a[1][0][0].getColor(2); n = a[1][0][0].getColor(1);
	a[1][0][0].setColor(2, m);
	a[1][0][0].setColor(1, k);

	a[0][1][0].setColor(4, p);
	a[0][1][0].setColor(1, n);
}

void BigCube::frontc()
{
	int p, n, m, k, z, x;
	p = a[0][0][2].getColor(0);
	a[0][0][2].setColor(0, a[0][0][0].getColor(4));
	z = a[0][0][2].getColor(2);
	a[0][0][2].setColor(2, a[0][0][0].getColor(2));

	n = a[2][0][2].getColor(5);
	a[2][0][2].setColor(5, p);
	x = a[2][0][2].getColor(2);
	a[2][0][2].setColor(2, z);

	p = a[2][0][0].getColor(1);
	a[2][0][0].setColor(1, n);
	z = a[2][0][0].getColor(2);
	a[2][0][0].setColor(2, x);

	a[0][0][0].setColor(4, p);
	a[0][0][0].setColor(2, z);

	p = a[0][0][2].getColor(4);
	a[0][0][2].setColor(4, a[0][0][0].getColor(1));

	n = a[2][0][2].getColor(0);
	a[2][0][2].setColor(0, p);

	p = a[2][0][0].getColor(5);
	a[2][0][0].setColor(5, n);

	a[0][0][0].setColor(1, p);

	p = a[1][0][2].getColor(0); n = a[1][0][2].getColor(2);
	a[1][0][2].setColor(0, a[0][0][1].getColor(4));
	a[1][0][2].setColor(2, a[0][0][1].getColor(2));

	m = a[2][0][1].getColor(5); k = a[2][0][1].getColor(2);
	a[2][0][1].setColor(5, p);
	a[2][0][1].setColor(2, n);

	p = a[1][0][0].getColor(1); n = a[1][0][0].getColor(2);
	a[1][0][0].setColor(1, m);
	a[1][0][0].setColor(2, k);

	a[0][0][1].setColor(4, p);
	a[0][0][1].setColor(2, n);
}

void BigCube::backcc()
{
	int p, n, m, k, z, x;
	p = a[0][2][2].getColor(0);
	a[0][2][2].setColor(0, a[0][2][0].getColor(4));
	z = a[0][2][2].getColor(3);
	a[0][2][2].setColor(3, a[0][2][0].getColor(3));

	n = a[2][2][2].getColor(5);
	a[2][2][2].setColor(5, p);
	x = a[2][2][2].getColor(3);
	a[2][2][2].setColor(3, z);

	p = a[2][2][0].getColor(1);
	a[2][2][0].setColor(1, n);
	z = a[2][2][0].getColor(3);
	a[2][2][0].setColor(3, x);

	a[0][2][0].setColor(4, p);
	a[0][2][0].setColor(3, z);

	p = a[0][2][2].getColor(4);
	a[0][2][2].setColor(4, a[0][2][0].getColor(1));

	n = a[2][2][2].getColor(0);
	a[2][2][2].setColor(0, p);

	p = a[2][2][0].getColor(5);
	a[2][2][0].setColor(5, n);

	a[0][2][0].setColor(1, p);

	p = a[1][2][2].getColor(0); n = a[1][2][2].getColor(3);
	a[1][2][2].setColor(0, a[0][2][1].getColor(4));
	a[1][2][2].setColor(3, a[0][2][1].getColor(3));

	m = a[2][2][1].getColor(5); k = a[2][2][1].getColor(3);
	a[2][2][1].setColor(5, p);
	a[2][2][1].setColor(3, n);

	p = a[1][2][0].getColor(1); n = a[1][2][0].getColor(3);
	a[1][2][0].setColor(1, m);
	a[1][2][0].setColor(3, k);

	a[0][2][1].setColor(4, p);
	a[0][2][1].setColor(3, n);
}