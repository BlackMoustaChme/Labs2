#ifndef INC_5_3DFIGURE_H
#define INC_5_3DFIGURE_H
#include "2DFigure.h"
class ThDFigure
{
public:
    virtual double CalcVolume()=0;
};

class Cylinder:public ThDFigure
{
private:
    double h;
    TwDFigure* F;
protected:
    Cylinder(double);
    virtual TwDFigure* CloneTwDFigure(TwDFigure*)=0;
    void InitFigure (TwDFigure*);
public:
    Cylinder();
    ~Cylinder();
    //Cylinder(double, TwDFigure *);
    virtual double CalcVolume();
};

class CircleCylinder:public Cylinder
{
protected:
    CircleCylinder(double);
    virtual TwDFigure* CloneTwDFigure(TwDFigure*);
public:
    CircleCylinder();
    ~CircleCylinder();
    static CircleCylinder* CreateInstance (Circle*, double);
    double GetR();
};

class TriangleCylinder:public Cylinder
{
protected:
    TriangleCylinder(double);
    virtual TwDFigure* CloneTwDFigure(TwDFigure*);
public:
    TriangleCylinder();
    ~TriangleCylinder();
    static TriangleCylinder* CreateInstance (Triangle*, double);
    double GetA();
    double GetB();
    double GetC();
};
#endif //INC_5_3DFIGURE_H
