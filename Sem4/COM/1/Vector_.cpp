#include <iostream>
#include "Vector_.h"
#include <cmath>
using std::cout;//,
using std::endl;
using std::cin;
Vector_::Vector_() {

}
Vector_::~Vector_() {

}
void Vector_::Input() {
    cout<<"x1 = ";
    cin>>x1;
    cout<<"y1 = ";
    cin>>y1;
    cout<<"z1 = ";
    cin>>z1;
    cout<<"x2 = ";
    cin>>x2;
    cout<<"y2 = ";
    cin>>y2;
    cout<<"z2 = ";
    cin>>z2;
}
void Vector_::PotenoteSolvation() {

    cout<<"Coming Soon"<<endl;
}
void Vector_::DistanceBetweenPointsR2() {
    result = sqrt(((x2-x1)*(x2-x1)) + ((y2-y1)*(y2-y1)));
}
void Vector_::DistanceBetweenPointsR3() {
    result = sqrt(((x2-x1)*(x2-x1)) + ((y2-y1)*(y2-y1)) + ((z2-z1)*(z2-z1)));
}
void Vector_::Print() {
    cout<<"Result = "<<result;
}

HRESULT_ Vector_::QueryInterface_(IID_ iid, void **ppv) {
    switch (iid) {
        case 1: {
            *ppv = (void *) (IPrint *) this;
            AddRef();
            return 0;
        }
        case 2: {
            *ppv = (void *) (IOperations *) this;
            AddRef();
            return 0;
        }
        default:
            *ppv = nullptr;
            return 1;

    }
}

U_LONG_ Vector_::AddRef() {
    CountRef++;
    cout<<"AddReference"<<CountRef<<endl;
    return CountRef;
}
U_LONG_ Vector_::Release() {
    CountRef--;
    cout<<"DeleteReference"<<CountRef<<endl;
    if(CountRef == 0)
    {
        cout<<"DeleteVectorReference"<<endl;
        delete this;
    }
    return CountRef;
}