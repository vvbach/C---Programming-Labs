#include <GL/glut.h>
#include <iostream>
#include <math.h>
#include "Cube.h"
#include "DrawCube.h"
#include "SolveCube.h"

#define M_PI 3.14159265358979323846264338327950288


Cube cube;
DrawCube dc;
SolveCube sc;


void changeSize(int w, int h) {

	// Prevent a divide by zero, when window is too short
	// (you cant make a window of zero width).
	if (h == 0)
		h = 1;

	float ratio = w * 1.0 / h;

	// Use the Projection Matrix
	glMatrixMode(GL_PROJECTION);

	// Reset Matrix
	glLoadIdentity();

	// Set the viewport to be the entire window
	glViewport(0, 0, w, h);

	// Set the correct perspective.
	gluPerspective(45.0f, ratio, 0.1f, 100.0f);

	// Get Back to the Modelview
	glMatrixMode(GL_MODELVIEW);
}

float theta = 90;
float phi = 0;

void cameraMoving() {
	if (theta >= 180) theta = 179.9;
	if (theta <= 0) theta = 0.1;
	float cameraR = 10.0f;
	float cameraTheta = theta * M_PI / 180;
	float cameraPhi = phi * M_PI / 180;
	float z = cameraR * cos(cameraPhi) * sin(cameraTheta);
	float x = cameraR * sin(cameraPhi) * sin(cameraTheta);
	float y = cameraR * cos(cameraTheta);
	gluLookAt(x, y, z, 0, 0, 0, 0.0f, 1.0f, 0.0f);
}

void renderScene(void) {

	// Clear Color and Depth Buffers
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Reset transformations
	glLoadIdentity();
	// Set the camera
	cameraMoving();
	dc.DrawRubik(cube);

	glutSwapBuffers();
	glutPostRedisplay();
}

void processNormalKeys(unsigned char key, int x, int y) {
	switch (key) {
	case 'q':
		cube.rotateBackClock();
		sc.getProcess().push_back('b');
		break;
	case 'w':
		cube.rotateUpClock();
		sc.getProcess().push_back('u');
		break;
	case 'e':
		cube.rotateFrontClock();
		sc.getProcess().push_back('f');
		break;
	case 'a':
		cube.rotateLeftClock();
		sc.getProcess().push_back('l');
		sc.updateProcess();
		break;
	case 's':
		cube.rotateDownClock();
		sc.getProcess().push_back('d');
		sc.updateProcess();
		break;
	case 'd':
		cube.rotateRightClock();
		sc.getProcess().push_back('r');
		sc.updateProcess();
		break;
	case 'u':
		cube.rotateBackAntiClock();
		sc.getProcess().push_back('B');
		sc.updateProcess();
		break;
	case 'i':
		cube.rotateUpAntiClock();
		sc.getProcess().push_back('U');
		sc.updateProcess();
		break;
	case 'o':
		cube.rotateFrontAntiClock();
		sc.getProcess().push_back('F');
		sc.updateProcess();
		break;
	case 'j':
		cube.rotateLeftAntiClock();
		sc.getProcess().push_back('L');
		sc.updateProcess();
		break;
	case 'k':
		cube.rotateDownAntiClock();
		sc.getProcess().push_back('D');
		sc.updateProcess();
		break;
	case 'l':
		cube.rotateRightAntiClock();
		sc.getProcess().push_back('R');
		sc.updateProcess();
		break;
	case 'z':
		sc.solve(cube);
		for (auto c : sc.getSolveProcess()) cout << c << " ";
		cout << endl;
		break;
	case 'x':
		sc.saveState();
		break;
	case 'c':
		sc.loadState(cube);
		break;
	case 'v':
		sc.mix(cube);
		break;
	}
}

void processSpecialKeys(int key, int x, int y) {
	switch (key) {
	case GLUT_KEY_LEFT: // Rotate camera to the left
		phi += 5;
		break;
	case GLUT_KEY_RIGHT: // Rotate camera to the right
		phi -= 5;
		break;
	case GLUT_KEY_UP: // Rotate camera up
		theta -= 5;
		break;
	case GLUT_KEY_DOWN: // Rotate camera down
		theta += 5;
		break;
	}
}

int main(int argc, char** argv) {
	// init GLUT and create window
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(800, 600);
	glutCreateWindow("RUBIC");
	glEnable(GL_DEPTH_TEST);
	// register callbacks
	glutDisplayFunc(renderScene);
	glutReshapeFunc(changeSize);
	glutIdleFunc(renderScene);

	glutKeyboardFunc(processNormalKeys);
	glutSpecialFunc(processSpecialKeys);

	// enter GLUT event processing cycle
	glutMainLoop();
	return 1;
}