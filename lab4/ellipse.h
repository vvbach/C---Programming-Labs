#pragma once
#include "interface.h"

class Ellipse : public IFigure
{
private:
    double m, a, b;
    CVector2D center;
    const char* name = "Ellipse"; 
public:
    Ellipse();
    virtual ~Ellipse();
    double square() override;
    double perimeter() override;
    double mass() const override;
    CVector2D position() override;
    bool operator==(const IPhysObject &ob) const override;
    bool operator<(const IPhysObject &ob) const override;
    void draw() override;
    void initFromDialog() override;
    const char *classname() override;
    unsigned int size() override;
};
