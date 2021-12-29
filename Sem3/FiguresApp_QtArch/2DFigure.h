#pragma once
class TwDFigure
{
public:
    virtual double CalcSquare() = 0;
    virtual double CalcPerimeter() = 0;
};

class Circle:public TwDFigure
{
private:
    int r;
public:
    double CalcSquare();
    double CalcPerimeter();
    int getR();
    void setR(int r);

    Circle(int r);
    virtual ~Circle();
};

class Triangle:public TwDFigure
{
private:
	double a;
	double b;
	double c;
    int x1, y1,
    x2, y2,
    x3, y3;
public:
	enum side{
		A = 1,
		B = 2,
		C = 3,
	};
    double CalcSquare();
    double CalcPerimeter();
    double getSide(int number);
    void getCoor(int& x1, int& y1, int& x2, int& y2, int& x3, int& y3);
    void setCoor(int x1, int y1, int x2, int y2, int x3, int y3);

    Triangle(int x1, int y1, int x2, int y2, int x3, int y3);
    virtual ~Triangle();
};

class Ring:public TwDFigure
{
private:
    int r;
    int R;
public:
    double CalcSquare();
    double CalcPerimeter();
    int getr();
    int getR();
    void setr(int r);
    void setR(int R);

    Ring(int r, int R);
    virtual ~Ring();
};
class Hexagramm:public TwDFigure
{
private:
    double a;
    double x1, y1, y4,
    x2, y2, y5,
    x3, y3, y6;
public:
    Hexagramm();
    double CalcPerimeter();
    double CalcSquare();
    void getCoor(int& x1, int& y1, int& y4, int& x2, int& y2, int& y5, int& x3, int& y3, int& y6);
    void setCoor(int x1, int y1, int y4, int x2, int y2, int y5, int x3, int y3, int y6);

    Hexagramm(int x1, int y1, int y4, int x2, int y2, int y5, int x3, int y3, int y6);
    virtual ~Hexagramm();

};
