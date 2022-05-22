#ifndef INC_1_VECTORPOTENOTETASKFACTORY__H
#define INC_1_VECTORPOTENOTETASKFACTORY__H
#include "IUnknown.h"
#include "IClassFactory.h"

class VectorPotenoteTaskFactory: public IClassFactory_ {
private:
    int CountRef = 0;
public:
    VectorPotenoteTaskFactory();
    ~VectorPotenoteTaskFactory();
    virtual HRESULT_ CreateInstance(IID_, void **ppv);
    virtual HRESULT_ QueryInterface_(IID_, void **ppv);
    virtual U_LONG_ AddRef();
    virtual U_LONG_ Release();

};
#endif //INC_1_VECTORPOTENOTETASKFACTORY__H
