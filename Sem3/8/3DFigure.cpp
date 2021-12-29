/*#define _USE_MATH_DEFINES
#include <iostream>
#include <math.h>
#include "2DFigure.h"
#include "3DFigure.h"
using namespace std;
Cylinder::Cylinder(double h)
{
    this->h=h;
    //this->F=f->Clone();
}
void Cylinder::InitFigure(TwDFigure* f)
{
    //cout<<"Cylinder::Init"<<endl;
    this->F = CloneTwDFigure(f);
}
double Cylinder::CalcVolume ()
{
    return h*(F->CalcSquare());

}
Cylinder::~Cylinder()
{
    delete F;
}

CircleCylinder* CircleCylinder::CreateInstance(Circle* f,double h)
{
    CircleCylinder* circleCylinder = new CircleCylinder(h);
    circleCylinder->InitFigure(f);
    return circleCylinder;
}

CircleCylinder::CircleCylinder(double h):Cylinder(h)
{
    cout<<"CircleCylinder::CircleCylinder"<<endl;
}

CircleCylinder::~CircleCylinder()
{
    cout<<"CircleCylinder::~CircleCylinder"<<endl;
}

TwDFigure* CircleCylinder::CloneTwDFigure(TwDFigure* f)
{
    cout<<"CircleCylinder::CreateFigure"<<endl;
    Circle* c = static_cast<Circle*>(f);
    return new Circle(c->GetR());
}

TriangleCylinder* TriangleCylinder::CreateInstance(Triangle* f,double h)
{
    TriangleCylinder* triangleCylinder = new TriangleCylinder(h);
    triangleCylinder->InitFigure(f);
    return triangleCylinder;
}

TriangleCylinder::TriangleCylinder(double h):Cylinder(h)
{
    cout<<"TriangleCylinder::TriangleCylinder"<<endl;
}

TriangleCylinder::~TriangleCylinder()
{
    cout<<"TriangleCylinder::~TriangleCylinder"<<endl;
}

TwDFigure* TriangleCylinder::CloneTwDFigure(TwDFigure* f)
{
    cout<<"TriangleCylinder::CreateFigure"<<endl;
    Triangle* c = static_cast<Triangle*>(f);
    return new Triangle(c->GetA(), c->GetB(), c->GetC());
}*/



