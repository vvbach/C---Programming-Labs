#pragma once
#include <vector>
#include "Cube.h"
#include <fstream>

class SolveCube {
private:
	std::vector<char> process;
	std::vector<char> solveProcess;
	std::string stateFile = "save.txt";
public:

	std::vector<char>& getProcess();

	std::vector<char>& getSolveProcess();

	void updateProcess();

	void mix(Cube& cube);

	void solve(Cube& cube);

	void saveState();

	void loadState(Cube& cube);

	
};