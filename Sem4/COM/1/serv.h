#ifndef INC_1_SERV_H
#define INC_1_SERV_H
#include "iserv.h"
class Server: public IServer
{
private:

    int *a;
    int *b;

public:
    Server();
    //Server(int a);
    virtual void func();
    ~Server();
};

#endif //INC_1_SERV_H
