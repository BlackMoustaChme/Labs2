#ifndef INC_1_SERV2_H
#define INC_1_SERV2_H
#include "IUnknown.h"
#include "iserv.h"
#include "iserv2.h"

class Server2: public IServer, public IServer2
{
private:
    int CountRef = 0;
    int *a;
    int *b;
    int *c;

public:
    Server2();
    virtual void func();
    virtual void func2();
    virtual HRESULT_ QueryInterface_(IID_ , void **ppv);
    virtual U_LONG_ AddRef();
    virtual U_LONG_ Release();
    ~Server2();
};
#endif //INC_1_SERV2_H
