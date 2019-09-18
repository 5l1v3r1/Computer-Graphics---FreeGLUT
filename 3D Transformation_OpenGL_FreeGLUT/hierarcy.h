#pragma once
#include <iostream>
#include <math.h>
#include <vector>
#include "GL\glut.h"
#include "quadric.h"
using namespace std;

/*
*	Created By Sugiyanto G - c14170075
*	Surabaya, 18 September 2019
*	OpenGL FreeGLUT
*	Computer Graphics Subject
*	5th Semester
*/

class Hierarchy {
private:
	Quadric quadric;
	Matrix trans;
	int index; //index parent
public:
	void setQuadric(Quadric x) {
		quadric = x;
	}
	void setIndex(int x) {
		index = x;
	}
	int getIndex() {
		return index;
	}
	void setTransformation(Matrix x) {
		trans = trans * x;
	}
	Matrix getTransform(Hierarchy *x) {
		Matrix temp;
		if (index != -1) {
			temp = x[index].getTransform(x);
		}
		temp = temp * trans;
		return temp;
	}
	void draw(Hierarchy *x, double *col) {
		Vector dummy[100][100];
		Matrix temp = getTransform(x);
		int r = quadric.getRow();
		int c = quadric.getColumn();

		for (int a = 0; a < r; a++) {
			for (int b = 0; b < c; b++) {
				dummy[a][b] = quadric.titik[a][b];
				dummy[a][b] = temp * dummy[a][b];
			}
		}


		if (quadric.polygon) {
			for (int in = 0; in < 6; in++) {
				glColor3f(col[0], col[1], col[2]);
				glBegin(GL_POLYGON);
				for (int on = 0; on < 4; on++) {
					glVertex3f(dummy[in][on].getX(), dummy[in][on].getY(), dummy[in][on].getZ());
				}
				glEnd();

			}

			for (int in = 0; in < 6; in++) {
				glColor3f(0, 0, 0);
				glBegin(GL_LINES);
				for (int on = 0; on < 4; on++) {
					glVertex3f(dummy[in][on].getX(), dummy[in][on].getY(), dummy[in][on].getZ());
					glVertex3f(dummy[in][(on + 1) % 4].getX(), dummy[in][(on + 1) % 4].getY(), dummy[in][(on + 1) % 4].getZ());
				}
				glEnd();
			}
		}
		else if (quadric.hexa) {
			for (int in = 0; in < 6; in++) {
				glColor3f(col[0], col[1], col[2]);
				glBegin(GL_POLYGON);
				for (int on = 0; on < 6; on++) {
					glVertex3f(dummy[in][on].getX(), dummy[in][on].getY(), dummy[in][on].getZ());
				}
				glEnd();
			}

			for (int in = 0; in < 6; in++) {
				glColor3f(0, 0, 0);
				glBegin(GL_LINES);
				for (int on = 0; on < 6; on++) {
					glVertex3f(dummy[in][on].getX(), dummy[in][on].getY(), dummy[in][on].getZ());
					glVertex3f(dummy[in][(on + 1) % 6].getX(), dummy[in][(on + 1) % 6].getY(), dummy[in][(on + 1) % 6].getZ());
				}
				glEnd();
			}
		}
		else {
			for (int i = 1; i < r; i++) {
				for (int j = 0; j < c; j++) {
					glColor3f(col[0], col[1], col[2]);
					glBegin(GL_LINES);
					glVertex3f(dummy[i][j].getX(), dummy[i][j].getY(), dummy[i][j].getZ());
					glVertex3f(dummy[i - 1][j].getX(), dummy[i - 1][j].getY(), dummy[i - 1][j].getZ());
					glEnd();
				}
			}

			for (int i = 0; i < r; i++) {
				for (int j = 1; j < c; j++) {
					glColor3f(col[0], col[1], col[2]);
					glBegin(GL_LINES);
					glVertex3f(dummy[i][j].getX(), dummy[i][j].getY(), dummy[i][j].getZ());
					glVertex3f(dummy[i][j - 1].getX(), dummy[i][j - 1].getY(), dummy[i][j - 1].getZ());
					glEnd();
				}
			}

		}

	}
};

/*
*	Created By Sugiyanto G - c14170075
*	Surabaya, 18 September 2019
*	OpenGL FreeGLUT
*	Computer Graphics Subject
*	5th Semester
*/
