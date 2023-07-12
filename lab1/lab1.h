#ifndef HEADER
#define HEADER
struct Complex {
    double re;
    double im;
};

struct Matrix {
    double arr[3][3];
};

void swap2num(int *a, int *b);

void swap2num(int &a, int &b);

void roundRealNum(double *a);

void roundRealNum(double &a);

void multiply(Complex *c, double a);

void multiply(Complex &c, double a);

void transpose(Matrix *m);

void transpose(Matrix &m);

#endif