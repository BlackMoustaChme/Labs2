#include <iostream>
#include <math.h>
#include "2DFigure.h"
#include "3DFigure.h"
using namespace std;

int main()
{
    int key=0;
    Triangle t();
    Circle c1();
    Hexagramm h();
    Cylinder c2();
    TwDFigure *A=new Triangle(3,4,5);
    TwDFigure *B=new Circle(1);
    TwDFigure *E=new Hexagramm(2,6);

    cout<<A->CalcSquare()<<endl;
    cout<<A->CalcPerimeter()<<endl;
    cout<<B->CalcSquare()<<endl;
    cout<<B->CalcPerimeter()<<endl;
    cout<<E->CalcSquare()<<endl;
    cout<<E->CalcPerimeter()<<endl;

    cout<<"Enter value"<<endl;
    cin>>key;
    if(key==1)
    {
        ThDFigure *C=new Cylinder (4, A);
        cout<<C->CalcVolume()<<endl;
    }
    else
    {
        ThDFigure *D=new Cylinder (4, B);
        cout<<D->CalcVolume()<<endl;

        ThDFigure *F=new Cylinder (4, E);
        cout<<F->CalcVolume()<<endl;
    }

    return 0;
}
