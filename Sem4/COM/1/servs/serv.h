#ifndef INC_1_SERV_H
#define INC_1_SERV_H
#include "iserv.h"
#include "../headers/IUnknown.h"
class Server: public IServer
{
private:
    int CountRef = 0;
//    int *a;
//    int *b;

public:
    Server();
    virtual void func();
    virtual HRESULT_ QueryInterface_(IID_ , void **ppv);
    virtual U_LONG_ AddRef();
    virtual U_LONG_ Release();
    ~Server();
};

#endif //INC_1_SERV_H
