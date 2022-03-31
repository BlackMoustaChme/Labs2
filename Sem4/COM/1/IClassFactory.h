#ifndef INC_1_ICLASSFACTORY_H
#define INC_1_ICLASSFACTORY_H

class IClassFactory_: public IUnknown_{

    virtual HRESULT_ CreateInstance(IID_ , void **ppv)=0;

};

#endif //INC_1_ICLASSFACTORY_H
