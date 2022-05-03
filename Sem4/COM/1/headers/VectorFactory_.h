#ifndef INC_1_VECTORFACTORY__H
#define INC_1_VECTORFACTORY__H
#include "IUnknown.h"
#include "IClassFactory.h"

class VectorFactory_: public IClassFactory_ {
private:
    int CountRef = 0;
public:
    VectorFactory_();
    ~VectorFactory_();
    virtual HRESULT_ CreateInstance(IID_, void **ppv);
    virtual HRESULT_ QueryInterface_(IID_, void **ppv);
    virtual U_LONG_ AddRef();
    virtual U_LONG_ Release();

};


#endif //INC_1_VECTORFACTORY__H
