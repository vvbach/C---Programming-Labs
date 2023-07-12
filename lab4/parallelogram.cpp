#include "parallelogram.h"
#include "interface.h"
#include <iostream>
#include <math.h>

using namespace std;

Parallelogram::Parallelogram(){
    m = 0;
    p1 = p2 = p3 = {0, 0};
};
Parallelogram::~Parallelogram(){
    
}
double Parallelogram::square(){
    return abs((p2.x - p1.x)*(p3.y - p1.y) - (p3.x - p1.x)*(p2.y - p1.y));  
}
double Parallelogram::perimeter(){
    CVector2D v1, v2;
    v1 = {p2.x - p1.x, p2.y - p1.y};
    v2 = {p3.x - p1.x, p3.y - p1.y};
    return 2 * (sqrt(pow(v1.x, 2) + pow(v1.y, 2)) + sqrt(pow(v2.x, 2) + pow(v2.y, 2)));
}
double Parallelogram::mass() const{
    return m;
}
CVector2D Parallelogram::position(){
    CVector2D center = {(p2.x + p3.x) / 2, (p2.y + p3.y) / 2};
    return center;
}
bool Parallelogram::operator==(const IPhysObject &ob) const {
    return this->m == ob.mass();
}
bool Parallelogram::operator<(const IPhysObject &ob) const{
    return this->m < ob.mass();
}
void Parallelogram::draw(){
    cout << "-------" << name << "-------" << endl;
    cout << "Coordinates: " << endl;
    cout << "P1: " << p1.x << " | " << p1.y << endl;
    cout << "P2: " << p2.x << " | " << p2.y << endl;
    cout << "P3: " << p3.x << " | " << p3.y << endl;
    cout << "P4: " << (2 * position().x - p1.x) << " | " << (2 * position().y - p1.y) << endl;
    cout << "Center: " << position().x << " | " << position().y << endl;
    cout << "Square: " << square() << endl;
    cout << "Perimeter: " << perimeter() << endl;
}
void Parallelogram::initFromDialog(){
    cout << "Mass = "; cin >> m;
    cout << "P1.x = "; cin >> p1.x;
    cout << "P1.y = "; cin >> p1.y;
    cout << "P2.x = "; cin >> p2.x;
    cout << "P2.y = "; cin >> p2.y;
    cout << "P3.x = "; cin >> p3.x;
    cout << "P3.y = "; cin >> p3.y;
}
const char* Parallelogram::classname(){
    return name;
}
unsigned int Parallelogram::size(){
    return sizeof(*this);
}
