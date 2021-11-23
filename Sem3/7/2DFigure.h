#ifndef INC_7_2DFIGURE_H
#define INC_7_2DFIGURE_H

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

class Hexagramm:public TwDFigure //without Hexagon in it
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

};

#endif //INC_7_2DFIGURE_H
