#include <iostream>
#include "3DFigure.h"
#include "Except.h"

using namespace std;
int main()
{
    double r, h;
    bool check = true;
    Cylinder<Circle>* сylinder = NULL;
    while (check)
    {
        cout << "Enter the radius and height: " << endl;
        cout << "r = "; cin >> r;
        cout << "h = "; cin >> h;
        try
        {
            Circle* circle = new Circle(r);
            try
            {
                сylinder = new Cylinder<Circle>(circle, h);
                delete circle;
                check = false;
            }
            catch (Except& error)
            {
                delete circle;
                throw error;
                cout << "Try again..." << endl << endl;
            }
        }
        catch (Except& error)
        {
            error.Show();
            cout << "Try again..." << endl << endl;
        }
    }
    cout << сylinder->CalcVolume();
    delete сylinder;
}