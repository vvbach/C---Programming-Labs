#pragma once
#include "interface.h"

class Parallelogram : public IFigure
{
private:
    double m;
    CVector2D p1, p2, p3;
    const char* name = "Parallelogram"; 
public:
    Parallelogram();
    virtual ~Parallelogram();
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