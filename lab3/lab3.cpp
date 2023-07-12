#include <iostream>
#include "lab3.h"

using namespace std;

Matrix::Matrix(){
    arr = new double*[3];
    for (int i = 0; i < 3; i++) arr[i] = new double[3];
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            arr[i][j] = 0;
        }
    }
}

Matrix::~Matrix(){
    for (int i = 0; i < 3; i++) delete[] arr[i];
    delete[] arr;
}

void Matrix::inputMatrix(){
    cout << "Input: " << endl;
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            cin >> arr[i][j];
        }
    }   
}

void Matrix::printMatrix(){
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }   
}

Matrix Matrix::operator*(Matrix &m){
    Matrix res;
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            for (int k = 0; k < 3; k++){
                res.arr[i][j] = this->arr[i][k] * m.arr[k][j];
            }
        }
    }
    return res;
}
Matrix Matrix::operator*(const double &n){
    Matrix res;
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            res.arr[i][j] = this->arr[i][j] * n;
        }
    }
    return res;
}

Matrix Matrix::operator+(Matrix &m){
    Matrix res;
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            res.arr[i][j] = this->arr[i][j] + m.arr[i][j];
        }
    }
    return res;
}
Matrix Matrix::operator-(Matrix &m){
    Matrix res;
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            res.arr[i][j] = this->arr[i][j] - m.arr[i][j];
        }
    }
    return res;
}
bool Matrix::operator==(Matrix &m){
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            if (this->arr[i][j] != m.arr[i][j]){
                return false;
            }
        }
    }
    return true;
}
bool Matrix::operator!=(Matrix &m){
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            if (this->arr[i][j] != m.arr[i][j]){
                return true;
            }
        }
    }
    return false;
}
double Matrix::getDeterminate(){
    return arr[0][0] * arr[1][1] * arr[2][2] +
           arr[0][1] * arr[1][2] * arr[2][0] +
           arr[0][2] * arr[1][0] * arr[2][1] -
           arr[0][2] * arr[1][1] * arr[2][0] -
           arr[0][1] * arr[1][0] * arr[2][2] -
           arr[0][0] * arr[1][2] * arr[2][1];
}
bool Matrix::operator>(Matrix &m){
    return this->getDeterminate() > m.getDeterminate();
}
bool Matrix::operator<(Matrix &m){
    return this->getDeterminate() < m.getDeterminate();
}

Queue::Queue(){
    front = -1;
    rear = -1;
}
void Queue::operator<<(int& data){
    if ((front == 0 && rear == 99) ||(rear == (front - 1) % 99))
    {
        cout << "Queue is Full" << endl;
        return;
    }
    else if (front == -1){
        front = rear = 0;
        queue[rear] = data;
    }
    else if (rear == 99 && front != 0)
    {
        rear = 0;
        queue[rear] = data;
    }
    else
    {
        rear++;
        queue[rear] = data;
    }
}
void Queue::operator>>(int& data){
    if (front == -1)
    {
        cout << "Queue is Empty" << endl;
        return;
    }
    data = queue[front];
    queue[front] = 0;
    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else if (front == 99)
        front = 0;
    else
        front++;
}