#ifndef INC_1_SERVERFACTORY_H
#define INC_1_SERVERFACTORY_H
#include "../headers/IUnknown.h"
#include "../headers/IClassFactory.h"
class ServerFactory: public IClassFactory_{
private:
    int CountRef = 0;
public:
    ServerFactory();
    virtual HRESULT_ CreateInstance(IID_, void **ppv);
    virtual HRESULT_ QueryInterface_(IID_, void **ppv);
    virtual U_LONG_ AddRef();
    virtual U_LONG_ Release();
    ~ServerFactory();

};


#endif //INC_1_SERVERFACTORY_H
