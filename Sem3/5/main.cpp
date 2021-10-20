#include <iostream>
#include <math.h>
#include "Figure.h"
using namespace std;


double CalcCylinderVolume(double , Figure *);
int main()
{
    Triangle q();
    Circle w();
    Figure *A=new Triangle(3,4,5);
    Figure *B=new Circle(1);
    cout<<CalcCylinderVolume (5,A)<<endl;
    cout<<CalcCylinderVolume (5,B)<<endl;

    return 0;
}
double CalcCylinderVolume (double h, Figure *f)
{
    return h*f->CalcSquare();

}