#include <GL/glut.h>
#include "DrawCube.h"
#include <iostream>

void DrawCube::DrawFaceFRONT(vector<vector<int>> face) {
	int sq = 0;
	int s;
	for (float y = 1; y >= -1; y--) {
		for (float x = -1; x <= 1; x++) {
			s = face[sq / 3][sq - (sq / 3) * 3];
			glColor3f(color[s][0], color[s][1], color[s][2]);
			glBegin(GL_POLYGON);
			glVertex3f(x - 0.5, y - 0.5, 1.5f);
			glVertex3f(x - 0.5, y + 0.5, 1.5f);
			glVertex3f(x + 0.5, y + 0.5, 1.5f);
			glVertex3f(x + 0.5, y - 0.5, 1.5f);
			glEnd();
			sq++;
		}
	}
	glLineWidth(5);
	glColor3f(0.0f, 0.0f, 0.0f);
	for (float x = -1.5f; x <= 1.5f; x += 1) {
		glBegin(GL_LINES);
		glVertex3f(x, -1.5f, 1.51f);
		glVertex3f(x, 1.5f, 1.51f);
		glEnd();
	}
	for (float y = -1.5f; y <= 1.5f; y += 1) {
		glBegin(GL_LINES);
		glVertex3f(-1.5f, y, 1.51f);
		glVertex3f(1.5f, y, 1.51f);
		glEnd();
	}
}
void DrawCube::DrawFaceBACK(vector<vector<int>> face) {
	int sq = 0;
	int s;
	for (float y = 1; y >= -1; y--) {
		for (float x = 1; x >= -1; x--) {
			s = face[sq / 3][sq - (sq / 3) * 3];
			glColor3f(color[s][0], color[s][1], color[s][2]);
			glBegin(GL_POLYGON);
			glVertex3f(x - 0.5, y - 0.5, -1.5f);
			glVertex3f(x - 0.5, y + 0.5, -1.5f);
			glVertex3f(x + 0.5, y + 0.5, -1.5f);
			glVertex3f(x + 0.5, y - 0.5, -1.5f);
			glEnd();
			sq++;
		}
	}
	glLineWidth(5);
	glColor3f(0.0f, 0.0f, 0.0f);
	for (float x = -1.5f; x <= 1.5f; x += 1) {
		glBegin(GL_LINES);
		glVertex3f(x, -1.5f, -1.51f);
		glVertex3f(x, 1.5f, -1.51f);
		glEnd();
	}
	for (float y = -1.5f; y <= 1.5f; y += 1) {
		glBegin(GL_LINES);
		glVertex3f(-1.5f, y, -1.51f);
		glVertex3f(1.5f, y, -1.51f);
		glEnd();
	}
}
void DrawCube::DrawFaceUP(vector<vector<int>> face) {
	int sq = 0;
	int s;
	for (float z = -1; z <= 1; z++) {
		for (float x = -1; x <= 1; x++) {
			s = face[sq / 3][sq - (sq / 3) * 3];
			glColor3f(color[s][0], color[s][1], color[s][2]);
			glBegin(GL_POLYGON);
			glVertex3f(x - 0.5, 1.5f, z - 0.5);
			glVertex3f(x - 0.5, 1.5f, z + 0.5);
			glVertex3f(x + 0.5, 1.5f, z + 0.5);
			glVertex3f(x + 0.5, 1.5f, z - 0.5);
			glEnd();
			sq++;
		}
	}
	glLineWidth(5);
	glColor3f(0.0f, 0.0f, 0.0f);
	for (float x = -1.5f; x <= 1.5f; x += 1) {
		glBegin(GL_LINES);
		glVertex3f(x, 1.51f, -1.5f);
		glVertex3f(x, 1.51f, 1.5f);
		glEnd();
	}
	for (float z = -1.5f; z <= 1.5f; z += 1) {
		glBegin(GL_LINES);
		glVertex3f(-1.5f, 1.51f, z);
		glVertex3f(1.5f, 1.51f, z);
		glEnd();
	}
}
void DrawCube::DrawFaceDOWN(vector<vector<int>> face) {
	int sq = 0;
	int s;
	for (float z = 1; z >= -1; z--) {
		for (float x = -1; x <= 1; x++) {
			s = face[sq / 3][sq - (sq / 3) * 3];
			glColor3f(color[s][0], color[s][1], color[s][2]);
			glBegin(GL_POLYGON);
			glVertex3f(x - 0.5, -1.5f, z - 0.5);
			glVertex3f(x - 0.5, -1.5f, z + 0.5);
			glVertex3f(x + 0.5, -1.5f, z + 0.5);
			glVertex3f(x + 0.5, -1.5f, z - 0.5);
			glEnd();
			sq++;
		}
	}
	glLineWidth(5);
	glColor3f(0.0f, 0.0f, 0.0f);
	for (float x = -1.5f; x <= 1.5f; x += 1) {
		glBegin(GL_LINES);
		glVertex3f(x, -1.51f, -1.5f);
		glVertex3f(x, -1.51f, 1.5f);
		glEnd();
	}
	for (float z = -1.5f; z <= 1.5f; z += 1) {
		glBegin(GL_LINES);
		glVertex3f(-1.5f, -1.51f, z);
		glVertex3f(1.5f, -1.51f, z);
		glEnd();
	}
}
void DrawCube::DrawFaceRIGHT(vector<vector<int>> face) {
	int sq = 0;
	int s;
	for (float y = 1; y >= -1; y--) {
		for (float z = 1; z >= -1; z--) {
			s = face[sq / 3][sq - (sq / 3) * 3];
			glColor3f(color[s][0], color[s][1], color[s][2]);
			glBegin(GL_POLYGON);
			glVertex3f(1.5f, y - 0.5, z - 0.5);
			glVertex3f(1.5f, y - 0.5, z + 0.5);
			glVertex3f(1.5f, y + 0.5, z + 0.5);
			glVertex3f(1.5f, y + 0.5, z - 0.5);
			glEnd();
			sq++;
		}
	}
	glLineWidth(5);
	glColor3f(0.0f, 0.0f, 0.0f);
	for (float y = -1.5f; y <= 1.5f; y += 1) {
		glBegin(GL_LINES);
		glVertex3f(1.51f, y, 1.5f);
		glVertex3f(1.51f, y, -1.5f);
		glEnd();
	}
	for (float z = -1.5f; z <= 1.5f; z += 1) {
		glBegin(GL_LINES);
		glVertex3f(1.51f, 1.5f, z);
		glVertex3f(1.51f, -1.5f, z);
		glEnd();
	}
}
void DrawCube::DrawFaceLEFT(vector<vector<int>> face) {
	int sq = 0;
	int s;
	for (float y = 1; y >= -1; y--) {
		for (float z = -1; z <= 1; z++) {
			s = face[sq / 3][sq - (sq / 3) * 3];
			glColor3f(color[s][0], color[s][1], color[s][2]);
			glBegin(GL_POLYGON);
			glVertex3f(-1.5f, y - 0.5, z - 0.5);
			glVertex3f(-1.5f, y - 0.5, z + 0.5);
			glVertex3f(-1.5f, y + 0.5, z + 0.5);
			glVertex3f(-1.5f, y + 0.5, z - 0.5);
			glEnd();
			sq++;
		}
	}
	glLineWidth(5);
	glColor3f(0.0f, 0.0f, 0.0f);
	for (float y = -1.5f; y <= 1.5f; y += 1) {
		glBegin(GL_LINES);
		glVertex3f(-1.51f, y, 1.5f);
		glVertex3f(-1.51f, y, -1.5f);
		glEnd();
	}
	for (float z = -1.5f; z <= 1.5f; z += 1) {
		glBegin(GL_LINES);
		glVertex3f(-1.51f, 1.5f, z);
		glVertex3f(-1.51f, -1.5f, z);
		glEnd();
	}
}

void DrawCube::DrawRubik(Cube& cube) {
	DrawFaceFRONT(cube.getFront());
	DrawFaceBACK(cube.getBack());
	DrawFaceLEFT(cube.getLeft());
	DrawFaceRIGHT(cube.getRight());
	DrawFaceUP(cube.getUp());
	DrawFaceDOWN(cube.getDown());
}