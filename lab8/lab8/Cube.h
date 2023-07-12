#pragma once
#include <GL/glut.h>
#include <vector>

using namespace std;



class Cube {
private:
	vector<vector<int>> front;
	vector<vector<int>> back;
	vector<vector<int>> left;
	vector<vector<int>> right;
	vector<vector<int>> up;
	vector<vector<int>> down;

public:
	Cube();

	vector<vector<int>> getFront();
	vector<vector<int>> getBack();
	vector<vector<int>> getLeft();
	vector<vector<int>> getRight();
	vector<vector<int>> getUp();
	vector<vector<int>> getDown();

	void rotateUpClock();

	void rotateDownClock();

	void rotateFrontClock();

	void rotateBackClock();

	void rotateRightClock();

	void rotateLeftClock();

	void rotateUpAntiClock();

	void rotateDownAntiClock();

	void rotateFrontAntiClock();

	void rotateBackAntiClock();

	void rotateRightAntiClock();

	void rotateLeftAntiClock();

};