#define _USE_MATH_DEFINES
#include <iostream>
#include <math.h>
#include "2DFigure.h"
#include "3DFigure.h"
Cylinder::Cylinder(double h, TwDFigure *f)
{
    this->h=h;
    this->F=f->Clone();
}
double Cylinder::CalcVolume ()
{
    return h*(F->CalcSquare());

}
Cylinder::~Cylinder()
{
    delete F;
}
