#ifndef INC_1_IUNKNOWN_H
#define INC_1_IUNKNOWN_H
typedef int HRESULT_;
typedef int CLSID_;
typedef int IID_;
typedef int U_LONG_;
class IUnknown_
{
public:
    virtual HRESULT_ QueryInterface_(IID_ , void **ppv)=0;
    virtual U_LONG_ AddRef()=0;
    virtual U_LONG_ Release()=0;
};
HRESULT_ CreateInstance(CLSID_ , IID_ , void **ppv);
HRESULT_ GetClassObject(CLSID_ , IID_ , void **ppv);

#endif //INC_1_IUNKNOWN_H
