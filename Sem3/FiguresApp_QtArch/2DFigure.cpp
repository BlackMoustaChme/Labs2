#define _USE_MATH_DEFINES
#include "2DFigure.h"
#include <cmath>
#include "Except.h"

double Circle::CalcSquare()
{
	return M_PI * r * r;
}

double Circle::CalcPerimeter()
{
	return 2 * M_PI * r;
}

int Circle::getR()
{
	return r;
}

void Circle::setR(int r)
{
    this->r = r;
}

Circle::Circle(int r)
{
	if (r > 0) this->r = r;
    else throw Except(1, "Error creating circle");
}

Circle::~Circle()
{

}


double Triangle::CalcSquare()
{
    double p = CalcPerimeter() / 2;
	return sqrt(p * (p - a) * (p - b) * (p - c));
}

double Triangle::CalcPerimeter()
{
	return a + b + c;
}

double Triangle::getSide(int number)
{
	switch (number)
	{
	case 1:
	{
		return a;
	}
	case 2:
	{
		return b;
	}
	case 3:
	{
		return c;
	}
	default:
		break;
	}
    throw Except(0, "Error select side");
}

Triangle::Triangle(int x1, int y1, int x2, int y2, int x3, int y3)
{
    double a = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
    double b = sqrt(pow(x2 - x3, 2) + pow(y2 - y3, 2));
    double c = sqrt(pow(x1 - x3, 2) + pow(y1 - y3, 2));
	if (a > 0 && b > 0 && c > 0 && (a + b) > c && (a + c) > b && (b + c) > a)
	{
        this->a = a;
        this->b = b;
        this->c = c;
        this->x1 = x1;
        this->y1 = y1;
        this->x2 = x2;
        this->y2 = y2;
        this->x3 = x3;
        this->y3 = y3;
	}
    else throw Except(1, "Error creating triangle");
}

void Triangle::setCoor(int x1, int y1, int x2, int y2, int x3, int y3)
{
    double a = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
    double b = sqrt(pow(x2 - x3, 2) + pow(y2 - y3, 2));
    double c = sqrt(pow(x1 - x3, 2) + pow(y1 - y3, 2));
    if (a > 0 && b > 0 && c > 0 && (a + b) > c && (a + c) > b && (b + c) > a)
    {
        this->a = a;
        this->b = b;
        this->c = c;
        this->x1 = x1;
        this->y1 = y1;
        this->x2 = x2;
        this->y2 = y2;
        this->x3 = x3;
        this->y3 = y3;
    }
}

void Triangle::getCoor(int& x1, int& y1, int& x2, int& y2, int& x3, int& y3)
{
    x1 = this->x1;
    y1 = this->y1;
    x2 = this->x2;
    y2 = this->y2;
    x3 = this->x3;
    y3 = this->y3;
}

Triangle::~Triangle()
{

}

double Ring::CalcSquare()
{
	return M_PI * R * R - M_PI * r * r;
}

double Ring::CalcPerimeter()
{
	return 2 * M_PI * r + 2 * M_PI * R;
}

int Ring::getr()
{
	return r;
}
int Ring::getR()
{
	return R;
}

Ring::~Ring()
{

}

Ring::Ring(int r, int R)
{
	if (r > 0 && R > 0 && r != R)
	{
		if (r > R)
		{
			this->r = R;
			this->R = r;
		}
		else
		{
			this->r = r;
			this->R = R;
		}
	}
    else throw Except(1, "Error creating ring");
}

void Ring::setr(int r)
{
    if(R > r)
    {
        this->r = r;
    }
}

void Ring::setR(int R)
{
    if(R > r)
    {
        this->R = R;
    }
}
double Hexagramm::CalcPerimeter()
{
    return
            6*a;
}
double Hexagramm::CalcSquare()
{
    return
            a*a*sqrt(3)/2-3*sqrt(3)*(a/3)*(a/3);
}


void Hexagramm::setCoor(int x1, int y1, int y4, int x2, int y2, int y5, int x3, int y3, int y6)
{
    double a = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
    double b = sqrt(pow(x2 - x3, 2) + pow(y2 - y3, 2));
    double c = sqrt(pow(x1 - x3, 2) + pow(y1 - y3, 2));
    double a2 = sqrt(pow(x1 - x2, 2) + pow(y4 - y5, 2));
    double b2 = sqrt(pow(x2 - x3, 2) + pow(y5 - y6, 2));
    double c2 = sqrt(pow(x1 - x3, 2) + pow(y6 - y4, 2));
    if (a==b==c==a2==b2==c2)
    {
        this->a = a;
        this->x1 = x1;
        this->y1 = y1;
        this->x2 = x2;
        this->y2 = y2;
        this->x3 = x3;
        this->y3 = y3;
    }
}

Hexagramm::Hexagramm(int x1, int y1, int y4, int x2, int y2, int y5, int x3, int y3, int y6)
{
    double a = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
    double b = sqrt(pow(x2 - x3, 2) + pow(y2 - y3, 2));
    double c = sqrt(pow(x1 - x3, 2) + pow(y1 - y3, 2));
    double a2 = sqrt(pow(x1 - x2, 2) + pow(y4 - y5, 2));
    double b2 = sqrt(pow(x2 - x3, 2) + pow(y5 - y6, 2));
    double c2 = sqrt(pow(x1 - x3, 2) + pow(y6 - y4, 2));
    if (a==b==c==a2==b2==c2)
    {
        this->a = a;
        this->x1 = x1;
        this->y1 = y1;
        this->x2 = x2;
        this->y2 = y2;
        this->x3 = x3;
        this->y3 = y3;
    }
    else throw Except(1, "Error creating Hexagramm");
}

void Hexagramm::getCoor(int &x1, int &y1, int &y4, int &x2, int &y2, int &y5, int &x3, int &y3, int &y6)
{
    x1 = this->x1;
    y1 = this->y1;
    y4 = this->y4;
    x2 = this->x2;
    y2 = this->y2;
    y5 = this->y5;
    x3 = this->x3;
    y3 = this->y3;
    y6 = this->y6;
}

Hexagramm::~Hexagramm()
{

}
