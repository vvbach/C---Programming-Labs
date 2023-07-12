#pragma once
#include "Cube.h"

Cube::Cube() {
	down.assign(3, { 0, 0 ,0 });
	up.assign(3, { 5, 5 ,5 });
	front.assign(3, { 1, 1 ,1 });
	back.assign(3, { 3, 3 ,3 });
	left.assign(3, { 2, 2 ,2 });
	right.assign(3, { 4, 4 ,4 });
}

vector<vector<int>> Cube::getFront() {
	return front;
}
vector<vector<int>> Cube::getBack() {
	return back;
}
vector<vector<int>> Cube::getLeft() {
	return left;
}
vector<vector<int>> Cube::getRight() {
	return right;
}
vector<vector<int>> Cube::getUp() {
	return up;
}
vector<vector<int>> Cube::getDown() {
	return down;
}

void Cube::rotateUpClock() {
	swap(up[0][0], up[0][2]); swap(up[0][0], up[2][2]); swap(up[0][0], up[2][0]);
	swap(up[0][1], up[1][2]); swap(up[0][1], up[2][1]); swap(up[0][1], up[1][0]);

	swap(left[0][0], back[0][0]); swap(left[0][1], back[0][1]); swap(left[0][2], back[0][2]);
	swap(left[0][0], right[0][0]); swap(left[0][1], right[0][1]); swap(left[0][2], right[0][2]);
	swap(left[0][0], front[0][0]); swap(left[0][1], front[0][1]); swap(left[0][2], front[0][2]);
}

void Cube::rotateDownClock() {
	swap(down[0][0], down[0][2]); swap(down[0][0], down[2][2]); swap(down[0][0], down[2][0]);
	swap(down[0][1], down[1][2]); swap(down[0][1], down[2][1]); swap(down[0][1], down[1][0]);

	swap(left[2][0], front[2][0]); swap(left[2][1], front[2][1]); swap(left[2][2], front[2][2]);
	swap(left[2][0], right[2][0]); swap(left[2][1], right[2][1]); swap(left[2][2], right[2][2]);
	swap(left[2][0], back[2][0]); swap(left[2][1], back[2][1]); swap(left[2][2], back[2][2]);
}

void Cube::rotateFrontClock() {
	swap(front[0][0], front[0][2]); swap(front[0][0], front[2][2]); swap(front[0][0], front[2][0]);
	swap(front[0][1], front[1][2]); swap(front[0][1], front[2][1]); swap(front[0][1], front[1][0]);

	swap(up[2][0], right[0][0]); swap(up[2][1], right[1][0]); swap(up[2][2], right[2][0]);
	swap(up[2][0], down[0][2]); swap(up[2][1], down[0][1]); swap(up[2][2], down[0][0]);
	swap(up[2][0], left[2][2]); swap(up[2][1], left[1][2]); swap(up[2][2], left[0][2]);
}

void Cube::rotateBackClock() {
	swap(back[0][0], back[0][2]); swap(back[0][0], back[2][2]); swap(back[0][0], back[2][0]);
	swap(back[0][1], back[1][2]); swap(back[0][1], back[2][1]); swap(back[0][1], back[1][0]);

	swap(up[0][0], left[2][0]); swap(up[0][1], left[1][0]); swap(up[0][2], left[0][0]);
	swap(up[0][0], down[2][2]); swap(up[0][1], down[2][1]); swap(up[0][2], down[2][0]);
	swap(up[0][0], right[0][2]); swap(up[0][1], right[1][2]); swap(up[0][2], right[2][2]);
}

void Cube::rotateRightClock() {
	swap(right[0][0], right[0][2]); swap(right[0][0], right[2][2]); swap(right[0][0], right[2][0]);
	swap(right[0][1], right[1][2]); swap(right[0][1], right[2][1]); swap(right[0][1], right[1][0]);

	swap(up[0][2], back[2][0]); swap(up[1][2], back[1][0]); swap(up[2][2], back[0][0]);
	swap(up[0][2], down[0][2]); swap(up[1][2], down[1][2]); swap(up[2][2], down[2][2]);
	swap(up[0][2], front[0][2]); swap(up[1][2], front[1][2]); swap(up[2][2], front[2][2]);
}

void Cube::rotateLeftClock() {
	swap(left[0][0], left[0][2]); swap(left[0][0], left[2][2]); swap(left[0][0], left[2][0]);
	swap(left[0][1], left[1][2]); swap(left[0][1], left[2][1]); swap(left[0][1], left[1][0]);

	swap(up[0][0], front[0][0]); swap(up[1][0], front[1][0]); swap(up[2][0], front[2][0]);
	swap(up[0][0], down[0][0]); swap(up[1][0], down[1][0]); swap(up[2][0], down[2][0]);
	swap(up[0][0], back[2][2]); swap(up[1][0], back[1][2]); swap(up[2][0], back[0][2]);
}

void Cube::rotateUpAntiClock() {
	swap(up[0][0], up[2][0]); swap(up[0][0], up[2][2]); swap(up[0][0], up[0][2]);
	swap(up[0][1], up[1][0]); swap(up[0][1], up[2][1]); swap(up[0][1], up[1][2]);

	swap(left[0][0], front[0][0]); swap(left[0][1], front[0][1]); swap(left[0][2], front[0][2]);
	swap(left[0][0], right[0][0]); swap(left[0][1], right[0][1]); swap(left[0][2], right[0][2]);
	swap(left[0][0], back[0][0]); swap(left[0][1], back[0][1]); swap(left[0][2], back[0][2]);
}

void Cube::rotateDownAntiClock() {
	swap(down[0][0], down[2][0]); swap(down[0][0], down[2][2]); swap(down[0][0], down[0][2]);
	swap(down[0][1], down[1][0]); swap(down[0][1], down[2][1]); swap(down[0][1], down[1][2]);

	swap(left[2][0], back[2][0]); swap(left[2][1], back[2][1]); swap(left[2][2], back[2][2]);
	swap(left[2][0], right[2][0]); swap(left[2][1], right[2][1]); swap(left[2][2], right[2][2]);
	swap(left[2][0], front[2][0]); swap(left[2][1], front[2][1]); swap(left[2][2], front[2][2]);
}

void Cube::rotateFrontAntiClock() {
	swap(front[0][0], front[2][0]); swap(front[0][0], front[2][2]); swap(front[0][0], front[0][2]);
	swap(front[0][1], front[1][0]); swap(front[0][1], front[2][1]); swap(front[0][1], front[1][2]);

	swap(up[2][0], left[2][2]); swap(up[2][1], left[1][2]); swap(up[2][2], left[0][2]);
	swap(up[2][0], down[0][2]); swap(up[2][1], down[0][1]); swap(up[2][2], down[0][0]);
	swap(up[2][0], right[0][0]); swap(up[2][1], right[1][0]); swap(up[2][2], right[2][0]);
}

void Cube::rotateBackAntiClock() {
	swap(back[0][0], back[2][0]); swap(back[0][0], back[2][2]); swap(back[0][0], back[0][2]);
	swap(back[0][1], back[1][0]); swap(back[0][1], back[2][1]); swap(back[0][1], back[1][2]);

	swap(up[0][0], right[0][2]); swap(up[0][1], right[1][2]); swap(up[0][2], right[2][2]);
	swap(up[0][0], down[2][2]); swap(up[0][1], down[2][1]); swap(up[0][2], down[2][0]);
	swap(up[0][0], left[2][0]); swap(up[0][1], left[1][0]); swap(up[0][2], left[0][0]);
}

void Cube::rotateRightAntiClock() {
	swap(right[0][0], right[2][0]); swap(right[0][0], right[2][2]); swap(right[0][0], right[0][2]);
	swap(right[0][1], right[1][0]); swap(right[0][1], right[2][1]); swap(right[0][1], right[1][2]);

	swap(up[0][2], front[0][2]); swap(up[1][2], front[1][2]); swap(up[2][2], front[2][2]);
	swap(up[0][2], down[0][2]); swap(up[1][2], down[1][2]); swap(up[2][2], down[2][2]);
	swap(up[0][2], back[2][0]); swap(up[1][2], back[1][0]); swap(up[2][2], back[0][0]);
}

void Cube::rotateLeftAntiClock() {
	swap(left[0][0], left[2][0]); swap(left[0][0], left[2][2]); swap(left[0][0], left[0][2]);
	swap(left[0][1], left[1][0]); swap(left[0][1], left[2][1]); swap(left[0][1], left[1][2]);

	swap(up[0][0], back[2][2]); swap(up[1][0], back[1][2]); swap(up[2][0], back[0][2]);
	swap(up[0][0], down[0][0]); swap(up[1][0], down[1][0]); swap(up[2][0], down[2][0]);
	swap(up[0][0], front[0][0]); swap(up[1][0], front[1][0]); swap(up[2][0], front[2][0]);
}

