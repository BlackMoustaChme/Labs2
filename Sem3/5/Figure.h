#ifndef INC_5_FIGURE_H
#define INC_5_FIGURE_H

class Figure
{
public:
    virtual double CalcPerimeter()=0;
    virtual double CalcSquare()=0;

};

class Triangle:public Figure
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
};

class Circle:public Figure
{
private:
    double r;

public:
    Circle(double);
    virtual double CalcPerimeter();
    virtual double CalcSquare();

};

#endif //INC_5_FIGURE_H
