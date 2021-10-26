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
public:
    Cylinder();
    ~Cylinder();
    Cylinder(double, TwDFigure *);
    virtual double CalcVolume();

};
#endif //INC_5_3DFIGURE_H
