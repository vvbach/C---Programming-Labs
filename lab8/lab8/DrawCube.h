#pragma once
#include "Cube.h"
#include <vector>
using namespace std;

class DrawCube {
private:
	float color[6][3] = {
		{1.0f, 1.0f, 1.0f}, // white - 0
		{1.0f, 0.0f, 0.0f}, // red - 1
		{0.0f, 0.0f, 1.0f}, // blue - 2
		{1.0f, 0.5f, 0.0f}, // orange - 3
		{0.0f, 1.0f, 0.0f}, // green - 4
		{1.0f, 1.0f, 0.0f}, // yellow - 5
	};
public:
	void DrawFaceFRONT(vector<vector<int>> face);
	void DrawFaceBACK(vector<vector<int>> face);
	void DrawFaceUP(vector<vector<int>> face);
	void DrawFaceDOWN(vector<vector<int>> face);
	void DrawFaceRIGHT(vector<vector<int>> face);
	void DrawFaceLEFT(vector<vector<int>> face);

	void DrawRubik(Cube& cube);
};