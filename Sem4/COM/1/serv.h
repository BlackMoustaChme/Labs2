#ifndef INC_1_SERV_H
#define INC_1_SERV_H
#include "iserv.h"
#include "IUnknown.h"
class Server: public IServer
{
private:

    int *a;
    int *b;

public:
    Server();
    //Server(int a);
    virtual void func();
    virtual HRESULT_ QueryInterface_(IID_ , void **ppv);
    ~Server();
};

#endif //INC_1_SERV_H
