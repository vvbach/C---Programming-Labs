#include "ellipse.h"
#include "interface.h"
#include <iostream>
#include <math.h>

using namespace std;

Ellipse::Ellipse(){
    m = a = b = 0;
    center = {0, 0};
};
Ellipse::~Ellipse(){
    
}
double Ellipse::square(){
    return 3.14 * a * b;
}
double Ellipse::perimeter(){
    return 6.28 * sqrt((pow(a, 2) + pow(b, 2) / 2));
}
double Ellipse::mass() const{
    return m;
}
CVector2D Ellipse::position(){
    return center;
}
bool Ellipse::operator==(const IPhysObject &ob) const{
    return this->m == ob.mass();
}
bool Ellipse::operator<(const IPhysObject &ob) const{
    return this->m < ob.mass();
}
void Ellipse::draw(){
    cout << "-------" << name << "-------" << endl;
    cout << "Center: " << position().x << " | " << position().y << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "Square: " << square() << endl;
    cout << "Perimeter: " << perimeter() << endl;
}
void Ellipse::initFromDialog(){
    cout << "Mass = "; cin >> m;
    cout << "center.x = "; cin >> center.x;
    cout << "center.y = "; cin >> center.y;
    cout << "a = "; cin >> a;
    cout << "b = "; cin >> b;
}
const char* Ellipse::classname(){
    return name;
}
unsigned int Ellipse::size(){
    return sizeof(*this);
}

bool operator!=(BaseCObject &ob1, BaseCObject &ob2){
    return ob1.size() != ob2.size();
}