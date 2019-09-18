/*
#include <Windows.h>
#include <GL\glew.h>
#include <GL\freeglut.h>
#include <iostream>

using namespace std;

void changeViewPort(int w, int h)
{
	glViewport(0, 0, w, h);
}

void render()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glutSwapBuffers();
}



int main(int argc, char* argv[]) {

	// Initialize GLUT
	glutInit(&argc, argv);
	// Set up some memory buffers for our display
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	// Set the window size
	glutInitWindowSize(800, 600);
	// Create the window with the title "Hello,GL"
	glutCreateWindow("Hello, GL");
	// Bind the two functions (above) to respond when necessary
	glutReshapeFunc(changeViewPort);
	glutDisplayFunc(render);

	// Very important!  This initializes the entry points in the OpenGL driver so we can 
	// call all the functions in the API.
	GLenum err = glewInit();
	if (GLEW_OK != err) {
		fprintf(stderr, "GLEW error");
		return 1;
	}


	glutMainLoop();
	return 0;
}
*/

/////////////////////////////////
/////////////////////////////////

/*
#include <Windows.h>
#include <GL/gl.h>
//#include <GL/freeglut.h>
//#include <GL/glew.h>
//#include <GL/glu.h>
#include <stdlib.h>
#include <GL/glut.h>

GLfloat ctrlpoints[4][3] = {
		{ -4.0, -4.0, 0.0}, { -2.0, 4.0, 0.0},
		{2.0, -4.0, 0.0}, {4.0, 4.0, 0.0} };

void init(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_FLAT);
	glMap1f(GL_MAP1_VERTEX_3, 0.0, 1.0, 3, 4, &ctrlpoints[0][0]);
	glEnable(GL_MAP1_VERTEX_3);
}

void display(void)
{
	int i;

	glClear(GL_COLOR_BUFFER_BIT);
	//Points
	glPointSize(10.0);
	glColor3f(1.0, 1.0, 0.0);
	glBegin(GL_POINTS);
	for (i = 0; i < 4; i++) { glVertex3fv(&ctrlpoints[i][0]);}
	glEnd();
	//system("pause");
	
	//Lines
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_LINE_STRIP);
	for (i = 0; i <= 30; i++) {glEvalCoord1f((GLfloat)i / 30.0);}
	glEnd();

	//The following code displays the control points as dots.
	//glPointSize(10.0);
	//glColor3f(1.0, 1.0, 0.0);
	//glBegin(GL_POINTS);
	//for (i = 0; i < 4; i++) { glVertex3fv(&ctrlpoints[i][0]); }
	//glEnd();
	glutSwapBuffers();
	glFlush();
}

void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if (w <= h){
		glOrtho(-5.0, 5.0, -5.0*(GLfloat)h / (GLfloat)w,
			5.0*(GLfloat)h / (GLfloat)w, -5.0, 5.0);
	}
	else {
		glOrtho(-5.0*(GLfloat)w / (GLfloat)h,
			5.0*(GLfloat)w / (GLfloat)h, -5.0, 5.0, -5.0, 5.0);
	}
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow(argv[0]);
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutMainLoop();
	return 0;
}
*/

//////////////////////////////////////////////////
//////////////////////////////////////////////////

/*
#include <iostream>
#include <math.h>
#include <Windows.h>
#include <stdlib.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

using namespace std;


//Point class for taking the points
class Point {
public:
	float x, y;
	void setxy(float x2, float y2)
	{
		x = x2; y = y2;
	}
	//operator overloading for '=' sign
	const Point & operator=(const Point &rPoint)
	{
		x = rPoint.x;
		y = rPoint.y;
		return *this;
	}

};

int factorial(int n)
{
	if (n <= 1)
		return(1);
	else
		n = n * factorial(n - 1);
	return n;
}

float binomial_coff(float n, float k)
{
	float ans;
	ans = factorial(n) / (factorial(k)*factorial(n - k));
	return ans;
}

Point abc[20];
int SCREEN_HEIGHT = 500;
int points = 0;
int clicks = 4;

void myInit() {
	glClearColor(0.5, 0.5, 0.5, 1.0);
	glShadeModel(GL_FLAT);
	//glColor3f(1.0, 1.0, 1.0);
	//glPointSize(5.0);
	//glMatrixMode(GL_PROJECTION);
	//glLoadIdentity();
	//gluOrtho2D(0.0, 64.0, 0.0, 50.0);
	//glMatrixMode(GL_MODELVIEW);
	//glLoadIdentity();
	//glutSwapBuffers();
}

void myDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);
	glutSwapBuffers();
	//glFlush();
}

void drawDot(int x, int y) {
	glClear(GL_COLOR_BUFFER_BIT);
	glViewport(0, 0, (GLsizei)x, (GLsizei)y);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	
	glPointSize(10.0);
	glBegin(GL_POINTS);
	glColor3f(1.0, 0.0, 0.0);
	glVertex2i(x, y);
	glEnd();

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	//glBegin(GL_POINTS);
	//glColor3f(1.0, 0.0, 0.0);
	//glVertex2i(x, y);
	//glEnd();
	glutSwapBuffers();
	//glFlush();
}

void drawLine(Point p1, Point p2) {
	
	glClear(GL_COLOR_BUFFER_BIT);
	//glViewport(0, 0, (GLsizei)x, (GLsizei)y);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glPointSize(10.0);
	glBegin(GL_LINES);
	//glColor3f(0.0, 1.0, 0.0);
	glVertex2f(p1.x, p1.y);
	glVertex2f(p2.x, p2.y);
	glEnd();

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glutSwapBuffers();
	//glFlush();
}

//Calculate the bezier point
Point drawBezier(Point PT[], double t) {
	Point P;
	P.x = pow((1 - t), 3) * PT[0].x + 3 * t * pow((1 - t), 2) * PT[1].x + 3 * (1 - t) * pow(t, 2)* PT[2].x + pow(t, 3)* PT[3].x;
	P.y = pow((1 - t), 3) * PT[0].y + 3 * t * pow((1 - t), 2) * PT[1].y + 3 * (1 - t) * pow(t, 2)* PT[2].y + pow(t, 3)* PT[3].y;

	return P;
}

//Calculate the bezier point [generalized]
Point drawBezierGeneralized(Point PT[], double t) {
	Point P;
	P.x = 0; P.y = 0;
	for (int i = 0; i < clicks; i++)
	{
		P.x = P.x + binomial_coff((float)(clicks - 1), (float)i) * pow(t, (double)i) * pow((1 - t), (clicks - 1 - i)) * PT[i].x;
		P.y = P.y + binomial_coff((float)(clicks - 1), (float)i) * pow(t, (double)i) * pow((1 - t), (clicks - 1 - i)) * PT[i].y;
	}
	std::cout << "P.X = " << P.x << std::endl << "P.Y = " << P.y;
	std::cout << std::endl << std::endl;
	std::cout << "==============================\n==============================" << std::endl;
	return P;
}


void myMouse(int button, int state, int x, int y) {
	// If left button was clicked
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		// Store where mouse was clicked, Y is backwards.
		abc[points].setxy((float)x, (float)(SCREEN_HEIGHT - y));
		points++;

		// Draw the red  dot.
		drawDot(x, SCREEN_HEIGHT - y);

		// If (click-amout) points are drawn do the curve.
		if (points == clicks)
		{
			glColor3f(0.0, 1.0, 0.0);
			// Drawing the control lines
			for (int k = 0; k < clicks - 1; k++)
				drawLine(abc[k], abc[k + 1]);

			Point p1 = abc[0];
			// Draw each segment of the curve.Make t increment in smaller amounts for a more detaile curve.
			for (double t = 0.0; t <= 1.0; t += 0.02)
			{
				Point p2 = drawBezierGeneralized(abc, t);
				cout << "p1.X = " << p1.x << "  ,p1.Y = " << p1.y << endl;
				cout << "p2.X = " << p2.x << "  ,p2.Y = " << p2.y << endl;
				cout << endl;
				drawLine(p1, p2);
				p1 = p2;
			}
			glColor3f(1.0, 1.0, 0.0);

			points = 0;
		}
	}
}


int main(int argc, char *argv[]) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(640, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Bezier Curve");
	myInit();
	glutDisplayFunc(myDisplay);
	glutReshapeFunc(reshape);
	glutMouseFunc(myMouse);
	glutMainLoop();

	return 0;
}
*/

///////////////////////////////////////////////////////
///////////////////////////////////////////////////////

/*
#include <iostream>
#include <math.h>
#include <Windows.h>
#include <stdlib.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);

	//draw white polygon (rectangle) with corners at (0.25, 0.25, 0.0) and (0.75, 0.75, 0.0)
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_POLYGON);
	glVertex3f(0.25, 0.25, 0.0);
	glVertex3f(0.75, 0.25, 0.0);
	glVertex3f(0.75, 0.75, 0.0);
	glVertex3f(0.25, 0.75, 0.0);
	glEnd();

	
	glFlush();
}

void init(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}


  //Declare initial window size, position, and display mode
  //(single buffer and RGBA).  Open window with "hello"
  //in its title bar.  Call initialization routines.
  //Register callback function to display graphics.
  //Enter main loop and process events.

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(250, 250);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("hello");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;   //ISO C requires main to return int.
}
*/

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

/*
#include <Windows.h>
//#include "Header.h"
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

 //  Request double buffer display mode.
 //  Register mouse input callback functions

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
}*/