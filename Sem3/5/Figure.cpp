#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include "Figure.h"
Triangle::Triangle(double a1, double b1, double c1)
{
    a=a1;
    b=b1;
    c=c1;
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