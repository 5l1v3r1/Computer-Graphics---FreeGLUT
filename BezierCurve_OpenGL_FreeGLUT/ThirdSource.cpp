/*#include <iostream>
#include <math.h>
#include <Windows.h>
#include <stdlib.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

int connection = 1;

GLfloat controlPoints[6][3] = {
	{-4.0, -4.0, 0.0},
	{-2.0,  4.0, 0.0},
	{-3.0, -3.0, 0.0},
	{ 4.0,  4.0, 0.0},
	{ 2.0, -4.0, 0.0},
	{ 3.0,  2.0, 0.0}
	//{-4.0, -4.0, 0.0},
	//{-4.0, -4.0, 0.0},
	//{-4.0, -4.0, 0.0},
	//{-4.0, -4.0, 0.0},
	//{-4.0, -4.0, 0.0},

};

void init() {
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glMap1f(GL_MAP1_VERTEX_3, 0.0, 1.0, 3, 4, &controlPoints[0][0]);
	glEnable(GL_MAP1_VERTEX_3);
}

void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_LINE_STRIP);

	for (int i = 0; i <= connection; i++) {
		glEvalCoord1f((GLfloat)i / (GLfloat)connection);
	}
	glEnd();

	glPointSize(10.0);
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_POINTS);
	for (int i = 0; i < 6; i++) {
		glVertex3fv(&controlPoints[i][0]);
	}
	glEnd();

	////Body
	//glColor3f(0.0, 0.0, 1.0);
	//glPushMatrix();
	//glTranslatef(0.0f, 2.0f, 0.0f);
	//glCallList(body);
	//glPopMatrix();

	////Head
	//glColor3f(0.0, 1.0, 0.0);
	//glPushMatrix();
	//glTranslatef(0.0f, 5.75f, 0.0f);
	//glCallList(head);
	//glPopMatrix();

	glutSwapBuffers();
}

//void idle() {
//	static bool isLeftHandMove = true, isRightHandMove = false, isLeftFootMove = false, isRightFootMove = true;
//
//	//Rotating body
//	spin = spin + 0.5;
//	if (spin > 360.0) { spin = 0.5; }
//
//	//Rotating Left Hand///////////////////////////////
//	if (isLeftHandMove) { LefthandRotate = LeftHandRotate + 0.05; }else { LefthandRotate = LefthandRotate - 0.05; }
//
//	if (LeftHandRotate >= 15.0) { isLeftHandMove = false; }else(LeftHandRotate <= -15.0){ isLeftHandMove = true; }
//
//	//Rotating Right Hand///////////////////////////////
//	if (isRightHandMove) { RightHandRotate += 0.05 }
//	else { RightHandRotate -= 0.05 }
//
//	if (RightHandRotate >= 15.0) { isRightHandMove = false; }
//	else(RightHandRotate <= -15.0) { isRightHandMove = true; }
//
//
//	//Rotating Left Foot///////////////////////////////
//	if (isLeftFootMove) { LeftFootRotate += 0.05 }
//	else { LeftFootRotate -= 0.05 }
//
//	if (LeftFootRotate >= 15.0) { isLeftFootMove = false; }
//	else(LeftFootRotate <= -15.0) { isLeftFootMove = true; }
//
//	//Rotating Right Foot////////////////////////////
//	if (isRightFootMove) { rightFootRotate += 0.05 }
//	else { rightFootRotate -= 0.05 }
//
//	if (rightFootRotate >= 15.0) { isRightFootMove = false; }
//	else(rightFootRotate <= -15.0) { isRightFootMove = true; }
//	glutPostRedisplay();
//}

void reshape(int w, int h) {
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-10.0, 10.0, -10.0, 10.0, -20.0, 20.0);
	if(w <= h){glOrtho(-5.0, 5.0, -5.0*(GLfloat)h / (GLfloat)w, 5.0*(GLfloat)h / (GLfloat)w,-5.0,5.0);}
	else{glOrtho(-5.0*(GLfloat)w/(GLfloat)h, 5.0*(GLfloat)w / (GLfloat)h, -5.0,5.0,-5.0,5.0);}
	glMatrixMode(GL_MODELVIEW);
	//glLoadIdentity();
}

void keyboard(unsigned char key, int x, int y) {

	switch (key) {
	case 27: // Esc btn press
		exit(0);
		break;
	case '+':
		connection++;
		//glutDisplayFunc(display);
		break;
	case '-':
		connection--;
		//glutDisplayFunc(display);
		break;
	default:
		break;
	}
	if (connection < 0) {
		connection = 0;
	}
	glutPostRedisplay();

	//if (key == 'q') { vx -= 0.5; }
	//if (key == 'a') { vx += 0.5; }
	//if (key == 'w') { vy -= 0.5; }
	//if (key == 's') { vy += 0.5; }
	//if (key == 'e') { vz -= 0.5; }
	//if (key == 'd') { vz += 0.5; }
}

int main(int argc, char** argv) {

	//std::cout << "Press 'q' and 'a' to change the viewport in X direction" << std::endl;
	//std::cout << "Press 'w' and 's' to change the viewport in Y direction" << std::endl;
	//std::cout << "Press 'e' and 'd' to change the viewport in Z direction" << std::endl;
	//std::cout << std::endl << std::endl;
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(50, 50);
	glutCreateWindow("Bezier Static Curve - 13.Sept.2019 >> Sugiyanto G ~ c14170075");

	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	glutMainLoop();

	return 0;
}
*/