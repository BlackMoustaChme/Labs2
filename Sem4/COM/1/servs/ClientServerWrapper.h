#ifndef INC_1_CLIENTSERVERWRAPPER_H
#define INC_1_CLIENTSERVERWRAPPER_H
#include "serv.h"
#include "serv2.h"
#include "../headers/Vector_.h"
#include "../headers/IClassFactory.h"
#include "../headers/IUnknown.h"

class ClientServerWrapper {
private:
    IServer* server;
    //IServer2* server2;
    //IPrint* print;
    //IOperations* operations;
    //IClassFactory_* factory;

public:
    ClientServerWrapper();
    ClientServerWrapper(ClientServerWrapper& csw);
    ~ClientServerWrapper();
    //void PrintVector();
    //void InputVector();
    //void VectorPotenoteSolavation();
    //void VectorDistanceBetweenPointsR2();
    //void VectorDistanceBetweenPointsR3();
    void CallFunc();
    ClientServerWrapper& operator=(ClientServerWrapper& csw);

};


#endif //INC_1_CLIENTSERVERWRAPPER_H
