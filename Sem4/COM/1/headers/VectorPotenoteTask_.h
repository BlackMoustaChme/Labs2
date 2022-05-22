#ifndef INC_1_VECTORPOTENOTETASK__H
#define INC_1_VECTORPOTENOTETASK__H
#include "IUnknown.h"
#include "IVector.h"
#include "Vector_.h"
#include "IVectorMod.h"

class VectorPotenoteTask: public IPotenoteTask{
private:
    int CountRef = 0;
    Vector_ vector_base;
    IPrint* ipr;
    IOperations* ioprs;
    long double x3 = 0;
    long double y3 = 0;
public:
    VectorPotenoteTask();
    ~VectorPotenoteTask();
    virtual void PotenoteSolvation();
    virtual HRESULT_ QueryInterface_(IID_ , void **ppv);
    virtual U_LONG_ AddRef();
    virtual U_LONG_ Release();
};

#endif //INC_1_VECTORPOTENOTETASK__H
