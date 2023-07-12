#include "SolveCube.h"
#include <iostream>

std::vector<char>& SolveCube::getProcess() {
	return process;
}

std::vector<char>& SolveCube::getSolveProcess() {
	return solveProcess;
}

void SolveCube::updateProcess() {
	if (process.size() < 2) return;
	if (abs(*(process.end() - 1) - *(process.end() - 2)) == 32) {
		process.pop_back();
		process.pop_back();
	}
	

	if (process.size() < 4) return;
	bool remove = true;
	char c = *(process.end() - 1);
	for (int i = 2; i <= 4; i++) {
		if (*(process.end() - i) != c) {
			remove = false;
			break;
		}
	}
	if (remove) {
		process.pop_back();
		process.pop_back();
		process.pop_back();
		process.pop_back();
	}
}

void SolveCube::mix(Cube& cube) {
	std::string step = "fFbBlLrRuUdD";
	for (int i = 0; i < 20; i++) {
		char c = step[rand() % 12];
		process.push_back(c);
		switch (process.back()) {
		case 'f':
			cube.rotateFrontClock();
			break;
		case 'b':
			cube.rotateBackClock();
			break;
		case 'l':
			cube.rotateLeftClock();
			break;
		case 'r':
			cube.rotateRightClock();
			break;
		case 'u':
			cube.rotateUpClock();
			break;
		case 'd':
			cube.rotateDownClock();
			break;
		case 'F':
			cube.rotateFrontAntiClock();
			break;
		case 'B':
			cube.rotateBackAntiClock();
			break;
		case 'L':
			cube.rotateLeftAntiClock();
			break;
		case 'R':
			cube.rotateRightAntiClock();
			break;
		case 'U':
			cube.rotateUpAntiClock();
			break;
		case 'D':
			cube.rotateDownAntiClock();
			break;
		}
	}
}

void SolveCube::solve(Cube& cube) {
	solveProcess.clear();
	while (!process.empty()) {
		switch (process.back()) {
		case 'f':
			cube.rotateFrontAntiClock();
			solveProcess.push_back('F');
			break;
		case 'b':
			cube.rotateBackAntiClock();
			solveProcess.push_back('B');
			break;
		case 'l':
			cube.rotateLeftAntiClock();
			solveProcess.push_back('L');
			break;
		case 'r':
			cube.rotateRightAntiClock();
			solveProcess.push_back('R');
			break;
		case 'u':
			cube.rotateUpAntiClock();
			solveProcess.push_back('U');
			break;
		case 'd':
			cube.rotateDownAntiClock();
			solveProcess.push_back('D');
			break;
		case 'F':
			cube.rotateFrontClock();
			solveProcess.push_back('f');
			break;
		case 'B':
			cube.rotateBackClock();
			solveProcess.push_back('b');
			break; 
		case 'L':
			cube.rotateLeftClock();
			solveProcess.push_back('l');
			break;
		case 'R':
			cube.rotateRightClock();
			solveProcess.push_back('r');
			break;
		case 'U':
			cube.rotateUpClock();
			solveProcess.push_back('u');
			break;
		case 'D':
			cube.rotateDownClock();
			solveProcess.push_back('d');
			break;
		}
		process.pop_back();
	}
}

void SolveCube::saveState() {
	ofstream out(stateFile);
	for (auto c : process) {
		out << c;
	}
	out.close();
}

void SolveCube::loadState(Cube& cube) {
	ifstream in(stateFile, std::ios::in);
	solve(cube);
	char c;
	while (in >> c) {
		process.push_back(c);
		switch (process.back()) {
		case 'f':
			cube.rotateFrontClock();
			break;
		case 'b':
			cube.rotateBackClock();
			break;
		case 'l':
			cube.rotateLeftClock();
			break;
		case 'r':
			cube.rotateRightClock();
			break;
		case 'u':
			cube.rotateUpClock();
			break;
		case 'd':
			cube.rotateDownClock();
			break;
		case 'F':
			cube.rotateFrontAntiClock();
			break;
		case 'B':
			cube.rotateBackAntiClock();
			break;
		case 'L':
			cube.rotateLeftAntiClock();
			break;
		case 'R':
			cube.rotateRightAntiClock();
			break;
		case 'U':
			cube.rotateUpAntiClock();
			break;
		case 'D':
			cube.rotateDownAntiClock();
			break;
		}
	}
	in.close();
}