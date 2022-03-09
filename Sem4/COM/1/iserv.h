#ifndef INC_1_ISERV_H
#define INC_1_ISERV_H
#include "IUnknown.h"
class IServer: public IUnknown_{

public:
    virtual void func()=0;
};

//IServer* CreateInstance();
#endif //INC_1_ISERV_H
