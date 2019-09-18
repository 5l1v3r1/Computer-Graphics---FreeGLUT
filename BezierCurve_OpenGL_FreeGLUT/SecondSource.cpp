#include <iostream>
#include <math.h>
#include <Windows.h>
#include <stdlib.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

static GLfloat spin = 0.0;
/*
void display() {
	//glClear(GL_COLOR_BUFFER_BIT);
	//glLoadIdentity();

	//glPointSize(10.0);
	//------------draw something
	//glPushMatrix();
	//glBegin(GL_POINTS);

	//glRotatef(spin, 0.0, 0.0, 1.0);
	
	//glColor3f(1.0, 0.0, 0.0);
	//glVertex2f(5.0,5.0);
	//glVertex2f(2.5, 2.5);
	//glVertex2f(-5.0, -5.0);
	//glVertex2f(-2.5, -2.5);
	////----------------------
	//glVertex2f(-5.0, 5.0);
	//glVertex2f(5.0, -5.0);
	//glVertex2f(-2.5, 2.5);
	//glVertex2f(2.5, -2.5);

	//glColor3f(0.0, 0.0, 1.0);
	//glVertex2f(4.0, 4.0);
	//glVertex2f(2.0, 2.0);
	//glVertex2f(-4.0, -4.0);
	//glVertex2f(-2.0, -2.0);
	////----------------------
	//glVertex2f(-4.0, 4.0);
	//glVertex2f(4.0, -4.0);
	//glVertex2f(-2.0, 2.0);
	//glVertex2f(2.0, -2.0);

	//glColor3f(0.0, 1.0, 0.0);
	//glVertex2f(3.0, 3.0);
	//glVertex2f(1.5, 1.5);
	//glVertex2f(-3.0, -3.0);
	//glVertex2f(-1.5, -1.5);
	////----------------------
	//glVertex2f(-3.0, 3.0);
	//glVertex2f(3.0, -3.0);
	//glVertex2f(-1.5, 1.5);
	//glVertex2f(1.5, -1.5);

	//glColor3f(0.0, 0.0, 0.0);
	//glVertex2f(1.0, 1.0);
	//glVertex2f(3.5, 3.5);
	//glVertex2f(-1.0, -1.0);
	//glVertex2f(-3.5, -3.5);
	////----------------------
	//glVertex2f(-1.0, 1.0);
	//glVertex2f(1.0, -1.0);
	//glVertex2f(-3.5, 3.5);
	//glVertex2f(3.5, -3.5);

	//glColor3f(1.0, 1.0, 1.0);
	//glVertex2f(0.0, 0.0);
	//glVertex2f(4.5, 4.5);
	////glVertex2f(-0.0, -1.0);
	//glVertex2f(-4.5, -4.5);
	////----------------------
	////glVertex2f(-1.0, 1.0);
	////glVertex2f(1.0, -1.0);
	//glVertex2f(-4.5, 4.5);
	//glVertex2f(4.5, -4.5);

	//glEnd();
	////glPopMatrix();
	////glRotatef(spin, 0.0, 0.0, 1.0);
	////glColor3f(1.0, 0.0, 0.0);
	//glutSwapBuffers();
	////glFlush(); --> tidak bisa jalan

	glClear(GL_COLOR_BUFFER_BIT);
	glPushMatrix();
	glRotatef(spin,1.0, 1.0, 1.0); //angle, x, y, z
	glColor3f(1.0, 0.0, 0.0);
	glRectf(-8.0, -8.0, 8.0, 8.0);// x1,y1,x2,y2
	glPopMatrix();

	glPushMatrix();
	glRotatef(spin, 0.0, 1.0, 1.0);
	glColor3f(0.0, 1.0, 0.0);
	glRectf(-6.0, -6.0, 6.0, 6.0);// x1,y1,x2,y2
	glPopMatrix();

	glPushMatrix();
	glRotatef(spin, 1.0, 0.0, 1.0);
	glColor3f(0.0, 0.0, 1.0);
	glRectf(-4.0, -4.0, 4.0, 4.0);// x1,y1,x2,y2
	glPopMatrix();

	glPushMatrix();
	glRotatef(spin, 1.0, 1.0, 0.0);
	glColor3f(1.0, 1.0, 1.0);
	glRectf(-2.0, -2.0, 2.0, 2.0);// x1,y1,x2,y2
	//glRectfv((float)(0.0, 2.0, 1.0), (float)(0.0, -2.0, -1.0));
	glPopMatrix();
	//glRectfv();
	glutSwapBuffers();
}

void displayBlue() {
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();

	glPointSize(20.0);
	//------------draw something
	//glPushMatrix();
	glBegin(GL_POINTS);
	glColor3f(0.0, 0.0, 1.0);
	glVertex2f(4.0, 4.0);
	glVertex2f(2.0, 2.0);
	glVertex2f(-4.0, -4.0);
	glVertex2f(-2.0, -2.0);
	//----------------------
	glVertex2f(-4.0, 4.0);
	glVertex2f(4.0, -4.0);
	glVertex2f(-2.0, 2.0);
	glVertex2f(2.0, -2.0);
	glEnd();
	glutSwapBuffers();
}
void displayGreen(){
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();

	glPointSize(30.0);
	//------------draw something
	//glPushMatrix();
	glBegin(GL_POINTS);
	glColor3f(0.0, 1.0, 0.0);
	glVertex2f(3.0, 3.0);
	glVertex2f(1.5, 1.5);
	glVertex2f(-3.0, -3.0);
	glVertex2f(-1.5, -1.5);
	//----------------------
	glVertex2f(-3.0, 3.0);
	glVertex2f(3.0, -3.0);
	glVertex2f(-1.5, 1.5);
	glVertex2f(1.5, -1.5);
	glEnd();
	glutSwapBuffers();
}

void init() {
	glClearColor(0.5, 0.5, 0.5, 1.0);
	glShadeModel(GL_FLAT);
}

void spinDisplay(void)
{
	spin = spin + 0.1;
	if (spin > 360.0)
		spin = spin - 360.0;
	glutPostRedisplay();
}

void reshape(int w, int h)
{
	//glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	//glMatrixMode(GL_PROJECTION);
	//glLoadIdentity();
	//gluOrtho2D(-10.0, 10.0, -10.0, 10.0);
	//glMatrixMode(GL_MODELVIEW);
	//glLoadIdentity();

	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//glOrtho(-50.0, 50.0, -50.0, 50.0, -1.0, 1.0);
	gluOrtho2D(-10.0, 10.0, -10.0, 10.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void mouse(int button, int state, int x, int y)
{
	switch (button) {
	case GLUT_LEFT_BUTTON:
		if (state == GLUT_DOWN) {
			//std::cout << "Rotate" << std::endl;
			glutIdleFunc(spinDisplay);
			std::cout << "Rotate" << std::endl;
		}
		break;
	case GLUT_RIGHT_BUTTON:
		if (state == GLUT_DOWN) {
			//std::cout << "Stop Rotate" << std::endl;
			glutIdleFunc(NULL);
			std::cout << "Stop Rotate" << std::endl;
		}
		break;
	default:
		break;
	}
}

int main(int argc, char** argv) {

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	
	glutInitWindowPosition(300, 300);
	glutInitWindowSize(500, 500);

	glutCreateWindow("OpenGL - freeGlut - SugiyantoG/c14170075/13-Sept-2019");
	init();
	glutDisplayFunc(display);
	//glutDisplayFunc(displayBlue);
	//glutDisplayFunc(displayGreen);
	glutReshapeFunc(reshape);
	glutMouseFunc(mouse);

	glutMainLoop();
	//system("pause");
	return 0;
}
*/


//////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////

/*
#include <Windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>

static GLfloat spin = 0.0;

void init(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_FLAT);
}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glPushMatrix();
	glRotatef(spin, 0.0, 0.0, 1.0);
	glColor3f(1.0, 1.0, 1.0);
	glRectf(-25.0, -25.0, 25.0, 25.0);
	glPopMatrix();
	glutSwapBuffers();
}

void spinDisplay(void)
{
	spin = spin + 3.0;
	if (spin > 360.0)
		spin = spin - 360.0;
	glutPostRedisplay();
}

void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-50.0, 50.0, -50.0, 50.0, -1.0, 1.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void mouse(int button, int state, int x, int y)
{
	switch (button) {
	case GLUT_LEFT_BUTTON:
		if (state == GLUT_DOWN)
			glutIdleFunc(spinDisplay);
		break;
	case GLUT_RIGHT_BUTTON:
		if (state == GLUT_DOWN)
			glutIdleFunc(NULL);
		break;
	default:
		break;
	}
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(250, 250);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Bezier Static Curve - 13.Sept.2019 >> Sugiyanto G ~ c14170075");
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutMouseFunc(mouse);
	glutMainLoop();
	return 0;
}
*/