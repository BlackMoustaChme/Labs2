#ifndef INC_1_CLIENTVECTORWRAPPER_H
#define INC_1_CLIENTVECTORWRAPPER_H
#include "Vector_.h"
#include "IClassFactory.h"
#include "IUnknown.h"

class ClientVectorWrapper {
private:
    IPrint* print;
    IOperations* operations;
    IClassFactory_* factory;
public:
    ClientVectorWrapper();
    ClientVectorWrapper(ClientVectorWrapper& cvw);
    ~ClientVectorWrapper();
    void PrintVector();
    void InputVector();
    void VectorPotenoteSolavation();
    void VectorDistanceBetweenPointsR2();
    void VectorDistanceBetweenPointsR3();
    ClientVectorWrapper& operator=(ClientVectorWrapper& cvw);
};


#endif //INC_1_CLIENTVECTORWRAPPER_H
