#ifndef INC_1_SERVER2FACTORY_H
#define INC_1_SERVER2FACTORY_H
#include "IUnknown.h"
#include "IClassFactory.h"
class Server2Factory: public IClassFactory_{
private:
    int CountRef = 0;
public:
    Server2Factory();
    virtual HRESULT_ CreateInstance(IID_, void **ppv);
    virtual HRESULT_ QueryInterface_(IID_, void **ppv);
    virtual U_LONG_ AddRef();
    virtual U_LONG_ Release();
    ~Server2Factory();

};
#endif //INC_1_SERVER2FACTORY_H