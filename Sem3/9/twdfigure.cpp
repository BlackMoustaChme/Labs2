#define _USE_MATH_DEFINES
#include "twdfigure.h"
#include <iostream>
#include <cmath>
#include "except.h"
using namespace std;
Triangle::Triangle(double a1, double b1, double c1)
{
    if (a1 > 0 && b1 > 0 && c1 > 0 && (a1 + b1) > c1 && (a1 + c1) > b1 && (b1 + c1) > a1)
    {
        a=a1;
        b=b1;
        c=c1;
    }
    else throw Except(1, "Error creating triangle");
}
double Triangle::GetA()
{
    return a;
}
double Triangle::GetB()
{
    return b;
}
double Triangle::GetC()
{
    return c;
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
    if (r1 > 0)
    {
        r = r1;
    }
    else throw Except(1, "Error creating circle");

}
double Circle::GetR()
{
    return r;
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

/*Pentagramm::Pentagramm(double r1, double a1)
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

}*/

void DrawableTriangle::getCoor(int &x1, int &y1, int &x2, int &y2, int &x3, int &y3)
{

}

void DrawableTriangle::setCoor(int x1, int y1, int x2, int y2, int x3, int y3)
{

}

DrawableTriangle::DrawableTriangle(int x1, int y1, int x2, int y2, int x3, int y3)
{

}

void DrawableCircle::getr(int &r)
{

}

void DrawableCircle::setr(int r)
{

}

DrawableCircle::DrawableCircle(int r)
{

}
