#include <iostream>
#include "../headers/VectorPotenoteTask_.h"
#include <cmath>
using std::cout;//,
using std::endl;
using std::cin;
VectorPotenoteTask::VectorPotenoteTask() {

}
VectorPotenoteTask::~VectorPotenoteTask() {

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
void VectorPotenoteTask::PotenoteSolvation() {

    cout<<"Coming Soon"<<endl;
}

void Vector_::Print() {
    cout<<"Result = "<<result;
}

HRESULT_ VectorPotenoteTask::QueryInterface_(IID_ iid, void **ppv) {
    switch (iid) {
        case 0: {
            *ppv = (void *) (IUnknown *)((IPotenoteTask*)this);
            AddRef();
            return 0;
        }
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
        case 3: {
            *ppv = (void *) (IPotenoteTask *) this;
            AddRef();
            return 0;
        }
        default:
            *ppv = nullptr;
            return 1;

    }
}

U_LONG_ VectorPotenoteTask::AddRef() {
    CountRef++;
    cout<<"AddReference"<<CountRef<<endl;
    return CountRef;
}
U_LONG_ VectorPotenoteTask::Release() {
    CountRef--;
    cout<<"DeleteReference"<<CountRef<<endl;
    if(CountRef == 0)
    {
        cout<<"DeleteVectorReference"<<endl;
        delete this;
    }
    return CountRef;
}
