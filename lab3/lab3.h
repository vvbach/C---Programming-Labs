#ifndef HEADER
#define HEADER

#include <fstream>
#include <iostream>

using namespace std;

class Matrix {
private:
    double **arr;
public:
    Matrix();
    ~Matrix();
    void inputMatrix();
    void printMatrix();
    Matrix operator*(Matrix &m);
    Matrix operator*(const double &n);
    Matrix operator+(Matrix &m);
    Matrix operator-(Matrix &m);
    bool operator==(Matrix &m);
    bool operator!=(Matrix &m);
    double getDeterminate();
    bool operator>(Matrix &m);
    bool operator<(Matrix &m);
};

class Queue {
private:
    int queue[100];
    int front, rear;
public:
    Queue();
    void operator<<(int &data);
    void operator>>(int &data);
};

#endif