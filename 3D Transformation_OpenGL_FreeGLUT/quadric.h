#pragma once

#include <iostream>
#include <math.h>
#include <vector>
#include "Header.h"
#include "GL\glut.h"
using namespace std;

/*
*	Created By Sugiyanto G - c14170075
*	Surabaya, 18 September 2019
*	OpenGL FreeGLUT
*	Computer Graphics Subject
*	5th Semester
*/

double phi = 3.14159265358979;

class Quadric {
public:
	Vector titik[100][50];
	double row, col;
	bool polygon, hexa;
	bool dua = false;

	Quadric() {
		row = 45.0;
		col = 45.0;
	}
	void setSize(double r, double c) {
		row = r;
		col = c;
	}
	double getRow() {
		return row;
	}
	double getColumn() {
		return col;
	}

	void badan() {
		polygon = true;

		//Badan Depan
		titik[0][0].setData(-100, -100, 0);
		titik[0][1].setData(100, -100, 0);
		titik[0][2].setData(100, 50, 0);
		titik[0][3].setData(-100, 50, 0);

		//Badan Kanan
		titik[1][0].setData(100, -100, 0);
		titik[1][1].setData(100, 50, 0);
		titik[1][2].setData(100, 50, 200);
		titik[1][3].setData(100, -100, 200);

		//Badan Kiri
		titik[2][0].setData(-100, -100, 0);
		titik[2][1].setData(-100, 50, 0);
		titik[2][2].setData(-100, 50, 200);
		titik[2][3].setData(-100, -100, 200);

		//Badan Belakang
		titik[3][0].setData(-100, -100, 200);
		titik[3][1].setData(100, -100, 200);
		titik[3][2].setData(100, 50, 200);
		titik[3][3].setData(-100, 50, 200);

		//Badan Bawah
		titik[4][0].setData(150, -101.5, -50);
		titik[4][1].setData(150, -101.5, 250);
		titik[4][2].setData(-150, -101.5, 250);
		titik[4][3].setData(-150, -101.5, -50);

		//Badan atas
		titik[5][0].setData(-100, 50, 0);
		titik[5][1].setData(-100, 50, 200);
		titik[5][2].setData(100, 50, 200);
		titik[5][3].setData(100, 50, 0);

	}

	void atap() {
		polygon = true;

		//Badan Depan
		titik[0][0].setData(-100, 50, 0);
		titik[0][1].setData(0, 150, 0);
		titik[0][2].setData(0, 150, 0);
		titik[0][3].setData(100, 50, 0);

		//Badan Kanan
		titik[1][0].setData(100, 50, 0);
		titik[1][1].setData(100, 50, 200);
		titik[1][2].setData(0, 150, 200);
		titik[1][3].setData(0, 150, 0);

		//Badan Kiri
		titik[2][0].setData(-100, 50, 0);
		titik[2][1].setData(-100, 50, 200);
		titik[2][2].setData(0, 150, 200);
		titik[2][3].setData(0, 150, 0);

		//Badan Belakang
		titik[3][0].setData(-100, 50, 200);
		titik[3][1].setData(0, 150, 200);
		titik[3][2].setData(0, 150, 200);
		titik[3][3].setData(100, 50, 200);

		//Badan Bawah
		titik[4][0].setData(-100, 50, 0);
		titik[4][1].setData(-100, 50, 200);
		titik[4][2].setData(100, 50, 200);
		titik[4][3].setData(100, 50, 0);

		//Badan atas
		titik[5][0].setData(0, 0, 0);
		titik[5][1].setData(0, 0, 0);
		titik[5][2].setData(0, 0, 0);
		titik[5][3].setData(0, 0, 0);

	}

	void cerobong() {
		polygon = true;

		//Badan Depan
		titik[0][0].setData(-85, 175, 0);
		titik[0][1].setData(-35, 175, 0);
		titik[0][2].setData(-35, 115, 0);
		titik[0][3].setData(-85, 65, 0);

		////Badan Kanan
		titik[1][0].setData(-35, 115, 0);
		titik[1][1].setData(-35, 115, 70);
		titik[1][2].setData(-35, 175, 70);
		titik[1][3].setData(-35, 175, 0);

		//Badan Kiri
		titik[2][0].setData(-85, 65, 0);
		titik[2][1].setData(-85, 65, 70);
		titik[2][2].setData(-85, 175, 70);
		titik[2][3].setData(-85, 175, 0);

		//Badan Belakang
		titik[3][0].setData(-85, 175, 70);
		titik[3][1].setData(-35, 175, 70);
		titik[3][2].setData(-35, 115, 70);
		titik[3][3].setData(-85, 65, 70);

		//Badan Bawah
		titik[4][0].setData(-85, 65, 0);
		titik[4][1].setData(-85, 65, 70);
		titik[4][2].setData(-35, 115, 70);
		titik[4][3].setData(-35, 115, 0);

		//Badan atas
		titik[5][0].setData(0, 0, 0);
		titik[5][1].setData(0, 0, 0);
		titik[5][2].setData(0, 0, 0);
		titik[5][3].setData(0, 0, 0);
	}

	void pintu() {
		polygon = true;
		
		//Badan Depan
		titik[0][0].setData(-75, -100, -1);
		titik[0][1].setData(-15, -100, -1);
		titik[0][2].setData(-15, 15, -1);
		titik[0][3].setData(-75, 15, -1);

		//Badan Kanan
		titik[1][0].setData(0, 0, 0);
		titik[1][1].setData(0, 0, 0);
		titik[1][2].setData(0, 0, 0);
		titik[1][3].setData(0, 0, 0);

		//Badan Kiri
		titik[2][0].setData(0, 0, 0);
		titik[2][1].setData(0, 0, 0);
		titik[2][2].setData(0, 0, 0);
		titik[2][3].setData(0, 0, 0);

		//Badan Belakang
		titik[3][0].setData(0, 0, 0);
		titik[3][1].setData(0, 0, 0);
		titik[3][2].setData(0, 0, 0);
		titik[3][3].setData(0, 0, 0);

		//Badan Bawah
		titik[4][0].setData(0, 0, 0);
		titik[4][1].setData(0, 0, 0);
		titik[4][2].setData(0, 0, 0);
		titik[4][3].setData(0, 0, 0);

		//Badan atas
		titik[5][0].setData(0, 0, 0);
		titik[5][1].setData(0, 0, 0);
		titik[5][2].setData(0, 0, 0);
		titik[5][3].setData(0, 0, 0);
	}

	void jendela() {

		polygon = true;
		//Badan Depan
		titik[0][0].setData(15, 15, -1);
		titik[0][1].setData(80, 15, -1);
		titik[0][2].setData(80, -35, -1);
		titik[0][3].setData(15, -35, -1);


		//Badan Kanan
		titik[1][0].setData(0, 0, 0);
		titik[1][1].setData(0, 0, 0);
		titik[1][2].setData(0, 0, 0);
		titik[1][3].setData(0, 0, 0);

		//Badan Kiri
		titik[2][0].setData(0, 0, 0);
		titik[2][1].setData(0, 0, 0);
		titik[2][2].setData(0, 0, 0);
		titik[2][3].setData(0, 0, 0);

		//Badan Belakang
		titik[3][0].setData(0, 0, 0);
		titik[3][1].setData(0, 0, 0);
		titik[3][2].setData(0, 0, 0);
		titik[3][3].setData(0, 0, 0);

		//Badan Bawah
		titik[4][0].setData(0, 0, 0);
		titik[4][1].setData(0, 0, 0);
		titik[4][2].setData(0, 0, 0);
		titik[4][3].setData(0, 0, 0);

		//Badan atas
		titik[5][0].setData(0, 0, 0);
		titik[5][1].setData(0, 0, 0);
		titik[5][2].setData(0, 0, 0);
		titik[5][3].setData(0, 0, 0);
	}

	void ventilasi() {
		hexa = true;
		
		//Badan Depan
		titik[0][0].setData(-35, 95, -1);
		titik[0][1].setData(40, 95, -1);
		titik[0][2].setData(50, 75, -1);
		titik[0][3].setData(40, 55, -1);
		titik[0][4].setData(-35, 55, -1);
		titik[0][5].setData(-45, 75, -1);

		//Badan Kanan
		titik[1][0].setData(0, 0, 0);
		titik[1][1].setData(0, 0, 0);
		titik[1][2].setData(0, 0, 0);
		titik[1][3].setData(0, 0, 0);
		titik[1][4].setData(0, 0, 0);
		titik[1][5].setData(0, 0, 0);

		//Badan Kiri
		titik[2][0].setData(0, 0, 0);
		titik[2][1].setData(0, 0, 0);
		titik[2][2].setData(0, 0, 0);
		titik[2][3].setData(0, 0, 0);
		titik[2][4].setData(0, 0, 0);
		titik[2][5].setData(0, 0, 0);

		//Badan Belakang
		titik[3][0].setData(0, 0, 0);
		titik[3][1].setData(0, 0, 0);
		titik[3][2].setData(0, 0, 0);
		titik[3][3].setData(0, 0, 0);
		titik[3][4].setData(0, 0, 0);
		titik[3][5].setData(0, 0, 0);

		//Badan Bawah
		titik[4][0].setData(0, 0, 0);
		titik[4][1].setData(0, 0, 0);
		titik[4][2].setData(0, 0, 0);
		titik[4][3].setData(0, 0, 0);
		titik[4][4].setData(0, 0, 0);
		titik[4][5].setData(0, 0, 0);

		//Badan atas
		titik[5][0].setData(0, 0, 0);
		titik[5][1].setData(0, 0, 0);
		titik[5][2].setData(0, 0, 0);
		titik[5][3].setData(0, 0, 0);
		titik[5][4].setData(0, 0, 0);
		titik[5][5].setData(0, 0, 0);
	}
	
	void jendela1() {
		polygon = true;
		//Badan Depan
		titik[0][0].setData(101, -35, 50);
		titik[0][1].setData(101, -35, 100);
		titik[0][2].setData(101, -10, 100);
		titik[0][3].setData(101, -10, 50);


		//Badan Kanan
		titik[1][0].setData(0, 0, 0);
		titik[1][1].setData(0, 0, 0);
		titik[1][2].setData(0, 0, 0);
		titik[1][3].setData(0, 0, 0);

		//Badan Kiri
		titik[2][0].setData(0, 0, 0);
		titik[2][1].setData(0, 0, 0);
		titik[2][2].setData(0, 0, 0);
		titik[2][3].setData(0, 0, 0);

		//Badan Belakang
		titik[3][0].setData(0, 0, 0);
		titik[3][1].setData(0, 0, 0);
		titik[3][2].setData(0, 0, 0);
		titik[3][3].setData(0, 0, 0);

		//Badan Bawah
		titik[4][0].setData(0, 0, 0);
		titik[4][1].setData(0, 0, 0);
		titik[4][2].setData(0, 0, 0);
		titik[4][3].setData(0, 0, 0);

		//Badan atas
		titik[5][0].setData(0, 0, 0);
		titik[5][1].setData(0, 0, 0);
		titik[5][2].setData(0, 0, 0);
		titik[5][3].setData(0, 0, 0);
	}
	
	void jendela2() {
		polygon = true;
		//Badan Depan
		titik[0][0].setData(101, -35, 100);
		titik[0][1].setData(101, -35, 150);
		titik[0][2].setData(101, -10, 150);
		titik[0][3].setData(101, -10, 100);


		//Badan Kanan
		titik[1][0].setData(0, 0, 0);
		titik[1][1].setData(0, 0, 0);
		titik[1][2].setData(0, 0, 0);
		titik[1][3].setData(0, 0, 0);

		//Badan Kiri
		titik[2][0].setData(0, 0, 0);
		titik[2][1].setData(0, 0, 0);
		titik[2][2].setData(0, 0, 0);
		titik[2][3].setData(0, 0, 0);

		//Badan Belakang
		titik[3][0].setData(0, 0, 0);
		titik[3][1].setData(0, 0, 0);
		titik[3][2].setData(0, 0, 0);
		titik[3][3].setData(0, 0, 0);

		//Badan Bawah
		titik[4][0].setData(0, 0, 0);
		titik[4][1].setData(0, 0, 0);
		titik[4][2].setData(0, 0, 0);
		titik[4][3].setData(0, 0, 0);

		//Badan atas
		titik[5][0].setData(0, 0, 0);
		titik[5][1].setData(0, 0, 0);
		titik[5][2].setData(0, 0, 0);
		titik[5][3].setData(0, 0, 0);
	}
	
	void jendela3() {
		polygon = true;
		//Badan Depan
		titik[0][0].setData(101, -10, 150);
		titik[0][1].setData(101, 15, 150);
		titik[0][2].setData(101, 15, 100);
		titik[0][3].setData(101, -10, 100);


		//Badan Kanan
		titik[1][0].setData(0, 0, 0);
		titik[1][1].setData(0, 0, 0);
		titik[1][2].setData(0, 0, 0);
		titik[1][3].setData(0, 0, 0);

		//Badan Kiri
		titik[2][0].setData(0, 0, 0);
		titik[2][1].setData(0, 0, 0);
		titik[2][2].setData(0, 0, 0);
		titik[2][3].setData(0, 0, 0);

		//Badan Belakang
		titik[3][0].setData(0, 0, 0);
		titik[3][1].setData(0, 0, 0);
		titik[3][2].setData(0, 0, 0);
		titik[3][3].setData(0, 0, 0);

		//Badan Bawah
		titik[4][0].setData(0, 0, 0);
		titik[4][1].setData(0, 0, 0);
		titik[4][2].setData(0, 0, 0);
		titik[4][3].setData(0, 0, 0);

		//Badan atas
		titik[5][0].setData(0, 0, 0);
		titik[5][1].setData(0, 0, 0);
		titik[5][2].setData(0, 0, 0);
		titik[5][3].setData(0, 0, 0);
	}

	void jendela4() {
		polygon = true;
		//Badan Depan
		titik[0][0].setData(101, 15, 100);
		titik[0][1].setData(101, 15, 50);
		titik[0][2].setData(101, -10, 50);
		titik[0][3].setData(101, -10, 100);


		//Badan Kanan
		titik[1][0].setData(0, 0, 0);
		titik[1][1].setData(0, 0, 0);
		titik[1][2].setData(0, 0, 0);
		titik[1][3].setData(0, 0, 0);

		//Badan Kiri
		titik[2][0].setData(0, 0, 0);
		titik[2][1].setData(0, 0, 0);
		titik[2][2].setData(0, 0, 0);
		titik[2][3].setData(0, 0, 0);

		//Badan Belakang
		titik[3][0].setData(0, 0, 0);
		titik[3][1].setData(0, 0, 0);
		titik[3][2].setData(0, 0, 0);
		titik[3][3].setData(0, 0, 0);

		//Badan Bawah
		titik[4][0].setData(0, 0, 0);
		titik[4][1].setData(0, 0, 0);
		titik[4][2].setData(0, 0, 0);
		titik[4][3].setData(0, 0, 0);

		//Badan atas
		titik[5][0].setData(0, 0, 0);
		titik[5][1].setData(0, 0, 0);
		titik[5][2].setData(0, 0, 0);
		titik[5][3].setData(0, 0, 0);
	}

};

/*
*	Created By Sugiyanto G - c14170075
*	Surabaya, 18 September 2019
*	OpenGL FreeGLUT
*	Computer Graphics Subject
*	5th Semester
*/
