#include <iostream>
#include "Vector_.h"
using std::cout;//, std::cin;
using std::endl;
Vector_::Vector_() {

}
Vector_::~Vector_() {

}
void Vector_::Input() {

}
void Vector_::PotenoteSolvation() {

}
void Vector_::DistanceBetweenPointsR2() {

}
void Vector_::DistanceBetweenPointsR3() {

}
void Vector_::Print() {

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