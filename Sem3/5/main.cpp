#include <iostream>
#include <math.h>
#include "2DFigure.h"
#include "3DFigure.h"
using namespace std;

int main()
{
    cout<<"Start"<<endl;

    TwDFigure *A=new Triangle(3,4,5);
    TwDFigure *B = new Circle(3);
    //TwDFigure *E=new Hexagramm(2,6);

    CircleCylinder* circleCylinder = CircleCylinder::CreateInstance(static_cast<Circle*>(B),2);

    cout<< "Volume: " << circleCylinder->CalcVolume() << endl;

    TriangleCylinder* triangleCylinder = TriangleCylinder::CreateInstance(static_cast<Triangle*>(A),2);

    cout<< "Volume: " << triangleCylinder->CalcVolume() << endl;


    delete B;
    delete circleCylinder;
    delete A;
    delete triangleCylinder;

    cout<<"Finish"<<endl;
    return 0;

    //Clone ver

    /*int key=0;
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

    return 0;*/

}
