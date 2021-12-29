#ifndef TWDFIGURE_H
#define TWDFIGURE_H
#include <iostream>
#include <memory>
using namespace std;

class TwDFigure
{
public:
    virtual double CalcPerimeter()=0;
    virtual double CalcSquare()=0;
    virtual TwDFigure* Clone() = 0;

};

class Triangle:public TwDFigure
{
private:
    double a;
    double b;
    double c;

public:
    Triangle();
    Triangle(double, double, double);
    virtual double CalcPerimeter();
    virtual double CalcSquare();
    double GetA();
    double GetB();
    double GetC();
    Triangle* Clone();
};
class DrawableTriangle : public TwDFigure
{
private:
    shared_ptr<TwDFigure> t_triangle;
    int x1, y1,
    x2, y2,
    x3, y3;

public:
    DrawableTriangle(shared_ptr<TwDFigure> triangle): t_triangle(triangle){}
    void getCoor(int& x1, int& y1, int& x2, int& y2, int& x3, int& y3);
    void setCoor(int x1, int y1, int x2, int y2, int x3, int y3);
    DrawableTriangle(int x1, int y1, int x2, int y2, int x3, int y3);
};

class Circle:public TwDFigure
{
private:
    double r;

public:
    Circle(double);
    virtual double CalcPerimeter();
    virtual double CalcSquare();
    double GetR();
    Circle* Clone();

};

class DrawableCircle : public TwDFigure
{
private:
    shared_ptr<TwDFigure> c_circle;
public:
    DrawableCircle(shared_ptr<TwDFigure> circle): c_circle(circle){}
    void getr(int& r);
    void setr(int r);
    DrawableCircle(int r);
};

/*class Hexagramm:public TwDFigure //without Hexagon in it
{
private:
    double r;
    double a;

public:
    Hexagramm();
    Hexagramm(double,double);
    virtual double CalcPerimeter();
    virtual double CalcSquare();
    Hexagramm* Clone();

};*/

#endif // TWDFIGURE_H
