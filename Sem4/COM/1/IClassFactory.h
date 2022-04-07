#ifndef INC_1_ICLASSFACTORY_H
#define INC_1_ICLASSFACTORY_H
#include "IUnknown.h"

class IClassFactory_: public IUnknown_{
private:
    int CountRef = 0;
public:
    virtual HRESULT_ CreateInstance(IID_ , void **ppv)=0;
    U_LONG_ AddRef();
    U_LONG_ Release();
};

U_LONG_ IClassFactory_::AddRef()
{
   CountRef++;
   return CountRef;
}

U_LONG_ IClassFactory_::Release()
{
    CountRef--;
    if(CountRef == 0)
    {
        delete this;
    }
    return CountRef;
}
#endif //INC_1_ICLASSFACTORY_H
