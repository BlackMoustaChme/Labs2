#ifndef INC_1_VECTOR__H
#define INC_1_VECTOR__H
#include "IVector.h"

class Vector_: public IOperations, IPrint{
private:
    int CountRef = 0;
    long double x1 = 0;
    long double y1 = 0;
    long double x2 = 0;
    long double y2 = 0;
    long double z1 = 0;
    long double z2 = 0;
    long double result = 0;
public:
    Vector_();
    ~Vector_();
    virtual void Print();
    virtual void Input();
    virtual void PotenoteSolvation();
    virtual void DistanceBetweenPointsR2();
    virtual void DistanceBetweenPointsR3();
    virtual HRESULT_ QueryInterface_(IID_ , void **ppv);
    virtual U_LONG_ AddRef();
    virtual U_LONG_ Release();
};


#endif //INC_1_VECTOR__H
