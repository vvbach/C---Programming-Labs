#include <iostream>
#include "lab1.h"

using namespace std;

void swap2num(int *a, int *b){
    int t = *a;
    *a = *b;
    *b = t;
}

void swap2num(int &a, int &b){
    int t = a;
    a = b;
    b = t;
}

void roundRealNum(double *a){
    double temp = (int)(*a);
    if(abs(*a - temp) < 0.5) *a = temp;
    else {
        if (*a >= 0) *a = temp + 1;
        else *a = temp - 1;
    }
}

void roundRealNum(double &a){
    double temp = (int)a;
    if(abs(a - temp) < 0.5) a = temp;
    else {
        if (a >= 0) a = temp + 1;
        else a = temp - 1;
    }
}

void multiply(Complex *c, double a){
    c->im *= a;
    c->re *= a;
}

void multiply(Complex &c, double a){
    c.im *= a;
    c.re *= a;
}

void transpose(Matrix *m){
    for (int i = 0; i < 3; i++){
        for (int j = i + 1; j < 3; j++){
            double t = m->arr[i][j];
            m->arr[i][j] = m->arr[j][i];
            m->arr[j][i] = t;
        }
    }
}

void transpose(Matrix &m){
    for (int i = 0; i < 3; i++){
        for (int j = i + 1; j < 3; j++){
            double t = m.arr[i][j];
            m.arr[i][j] = m.arr[j][i];
            m.arr[j][i] = t;
        }
    }
}