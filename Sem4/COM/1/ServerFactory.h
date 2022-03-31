#ifndef INC_1_SERVERFACTORY_H
#define INC_1_SERVERFACTORY_H
#include "IUnknown.h"
#include "IClassFactory.h"
class ServerFactory: public IClassFactory_{
private:
    int count = 0;
public:
    ServerFactory();
    virtual HRESULT_ CreateInstance(IID_, void **ppv);
    virtual HRESULT_ QueryInterface_(IID_, void **ppv);
    ~ServerFactory();

};


#endif //INC_1_SERVERFACTORY_H
