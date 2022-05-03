#ifndef INC_1_IVECTOR_H
#define INC_1_IVECTOR_H
#include "IUnknown.h"
class IOperations: public IUnknown_
{
public:
    virtual void Input() = 0;
    virtual void PotenoteSolvation() = 0;
    virtual void DistanceBetweenPointsR2() = 0;
    virtual void DistanceBetweenPointsR3() = 0;
};

class IPrint: public IUnknown_{
public:
    virtual void Print() = 0;
};



#endif //INC_1_IVECTOR_H
