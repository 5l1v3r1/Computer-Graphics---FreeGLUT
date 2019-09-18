#include <iostream>
#include <math.h>
#include "GL\glut.h"
#include "hierarcy.h"
#include <conio.h>
#include <Windows.h>
using namespace std;

/*
*	Created By Sugiyanto G - c14170075
*	Surabaya, 18 September 2019
*	OpenGL FreeGLUT
*	Computer Graphics Subject
*	5th Semester
*/

Hierarchy rumah[21];
Quadric balok, prisma, asap, door, window, kanan1, kanan2, kanan3, kanan4, test, udara;
Transformation T;
//SMOOTH TRIANGLE
const int dim = 500;
int isdepth;

void DoInit() {
	glEnable(GL_DEPTH_TEST);
	isdepth = 1;
	glOrtho(-dim, dim, -dim, dim, -dim, dim);
	glClearColor(0, 0, 0, 1);

	test.Bola(0);
	rumah[0].setQuadric(test);
	rumah[0].setIndex(-1);

	prisma.atap();
	rumah[1].setQuadric(prisma);
	rumah[1].setIndex(0);

	balok.badan();
	rumah[2].setQuadric(balok);
	rumah[2].setIndex(0);

	asap.cerobong();
	rumah[3].setQuadric(asap);
	rumah[3].setIndex(0);

	door.pintu();
	rumah[4].setQuadric(door);
	rumah[4].setIndex(0);

	window.jendela();
	rumah[5].setQuadric(window);
	rumah[5].setIndex(0);

	kanan1.jendela1();
	rumah[6].setQuadric(kanan1);
	rumah[6].setIndex(0);

	kanan2.jendela2();
	rumah[7].setQuadric(kanan2);
	rumah[7].setIndex(0);

	kanan3.jendela3();
	rumah[8].setQuadric(kanan3);
	rumah[8].setIndex(0);

	kanan4.jendela4();
	rumah[9].setQuadric(kanan4);
	rumah[9].setIndex(0);

	udara.ventilasi();
	rumah[10].setQuadric(udara);
	rumah[10].setIndex(0);

}

void Idle() {
	glutPostRedisplay();
}

void keyb(unsigned char key, int x, int y) {
	switch (key)
	{

	//Sclalling
	case 'o':
		rumah[0].setTransformation(T.scalling(0.99, 0.99, 0.99));
		break;
	case 'i':
		rumah[0].setTransformation(T.scalling(1.01, 1.01, 1.01));
		break;

	//Rotasi Sumbu X
	case 'z':
		rumah[0].setTransformation(T.rotationX(1));
		break;
	case 'x':
		rumah[0].setTransformation(T.rotationX(-1));
		break;

	//Rotasi Sumbu Y
	case 'e':
		rumah[0].setTransformation(T.rotationY(1));
		break;
	case 'r':
		rumah[0].setTransformation(T.rotationY(-1));
		break;

	//Rotasi Sumbu Z
	case 'y':
		rumah[0].setTransformation(T.rotationZ(1));
		break;
	case 't':
		rumah[0].setTransformation(T.rotationZ(-1));
		break;


	case 'q':
		rumah[0].setTransformation(T.rotationX(1));
		rumah[0].setTransformation(T.rotationY(1));
		rumah[0].setTransformation(T.rotationZ(-1));
		break;
	case 'p':
		rumah[0].setTransformation(T.rotationX(-1));
		rumah[0].setTransformation(T.rotationY(-1));
		rumah[0].setTransformation(T.rotationZ(1));
		break;
	//==============================================
	case '1':
		rumah[0].setTransformation(T.rotationX(1));
		rumah[0].setTransformation(T.rotationY(1));
		break;
	case '2':
		rumah[0].setTransformation(T.rotationX(-1));
		rumah[0].setTransformation(T.rotationY(-1));
		break;

	case '3':
		rumah[0].setTransformation(T.rotationX(1));
		rumah[0].setTransformation(T.rotationZ(1));
		break;
	case '4':
		rumah[0].setTransformation(T.rotationX(-1));
		rumah[0].setTransformation(T.rotationZ(-1));
		break;

	case '5':
		rumah[0].setTransformation(T.rotationY(-1));
		rumah[0].setTransformation(T.rotationZ(-1));
		break;
	case '6':
		rumah[0].setTransformation(T.rotationY(1));
		rumah[0].setTransformation(T.rotationZ(1));
		break;

	case '7':
		rumah[0].setTransformation(T.rotationX(-1));
		rumah[0].setTransformation(T.rotationY(-1));
		rumah[0].setTransformation(T.rotationZ(-1));
		break;
	case '8':
		rumah[0].setTransformation(T.rotationX(1));
		rumah[0].setTransformation(T.rotationY(1));
		rumah[0].setTransformation(T.rotationZ(1));
		break;

	//Perpindahan
	case 'w':
		rumah[0].setTransformation(T.translation(0, 1, 0));
		break;

	case 'd':
		rumah[0].setTransformation(T.translation(1, 0, 0));
		break;

	case 'a':
		rumah[0].setTransformation(T.translation(-1, 0, 0));
		break;
		
	case 's':
		rumah[0].setTransformation(T.translation(0, -1, 0));
		break;

	//Translasi
	case 'm':
		rumah[0].setTransformation(T.translation(0, 0, 1));
		break;

	case 'n':
		rumah[0].setTransformation(T.translation(0, 0, -1));
		break;
	}
}

void Display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//setting
	glLineWidth(3); //ketebalan garis
	glColor3f(1, 0, 0.2); //parameter 1 = red, 2 = green, 3 = blue
	glPointSize(1); //ukuran dari titik yang digunakan

	double color[3] = { 1,0,0 };
	double color1[3] = { 0,1,0 };
	double color2[3] = { 0.96, 0.60, 0.08 };
	double color3[3] = { 0.5, 0.6, 0.7 };
	double color4[3] = { 1,0.23,0.95 };
	double color5[3] = { 0.1,0.23,0.95 };
	double color6[3] = { 0.1,0.78,0.2 };

	rumah[1].draw(rumah, color1); //atap
	rumah[2].draw(rumah, color2); //badan
	rumah[3].draw(rumah, color3); //cerobong
	rumah[4].draw(rumah, color4); //pintu
	rumah[5].draw(rumah, color); //jendela dekat pintu
	rumah[10].draw(rumah, color5); //ventilasi
	rumah[6].draw(rumah, color5); //jendela4 kiri atas
	rumah[7].draw(rumah, color6); //jendela4 kiri bawah
	rumah[8].draw(rumah, color5); //jendela4 kanan bawah
	rumah[9].draw(rumah, color6); //jendela4 kanan atas
	glutSwapBuffers();
}

void main(int argc, char **argv) {
	glutInit(&argc, argv); //inisialisasi GLUT
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); //inisialisasi
	glutInitWindowSize(dim * 2, dim * 2); //ukuran windows
	glutCreateWindow("Grafik Komputer - 3D Transformation - SugiyantoG(c14170075) - 18Sept2019"); //window dibuat dengan parameter title dari program
	glutIdleFunc(Idle); //untuk fungsi idle, parameternya gunakan fungsi Idle
	glutDisplayFunc(Display); //untuk fungsi display, parameternya gunakan fungsi Display
	glutKeyboardFunc(keyb);
	DoInit(); //untuk inisialisasi, gunakan fungsinya

	glutMainLoop(); //looping utama
}

/*
*	Created By Sugiyanto G - c14170075
*	Surabaya, 18 September 2019
*	OpenGL FreeGLUT
*	Computer Graphics Subject
*	5th Semester
*/
