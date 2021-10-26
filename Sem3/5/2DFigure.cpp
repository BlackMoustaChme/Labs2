#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include "2DFigure.h"
Triangle::Triangle(double a1, double b1, double c1)
{
    a=a1;
    b=b1;
    c=c1;
}
Triangle* Triangle::Clone()
{
    return new Triangle(*this);
}
double Triangle::CalcPerimeter()
{
    return
            a+b+c;
}
double Triangle::CalcSquare()
{
    return
            sqrt((((CalcPerimeter()/2)*((CalcPerimeter()/2)-a)*(CalcPerimeter()/2)-a)*(CalcPerimeter()/2)-a));
}
Circle::Circle(double r1)
{
    r=r1;
}
Circle* Circle::Clone()
{
    return new Circle(*this);
}
double Circle::CalcPerimeter()
{
    return
            2*M_PI*r;
}
double Circle::CalcSquare()
{
    return
            M_PI*r*r;

}

Hexagramm::Hexagramm(double r1, double a1)
{
    r=r1;
    a=a1;
}
Hexagramm* Hexagramm::Clone()
{
    return new Hexagramm(*this);
}
double Hexagramm::CalcPerimeter()
{
    return
            6*a;
}
double Hexagramm::CalcSquare()
{
    return
            a*a*sqrt(3)/2-3*sqrt(3)*r*r;

}
