#ifndef INC_1_MODULEINFO_H
#define INC_1_MODULEINFO_H

#include "headers/VectorFactory_.h"
#include "headers/IClassFactory.h"
#include "headers/IUnknown.h"
#include "headers/IVector.h"
#include "headers/Vector_.h"
#include "headers/ClientVectorWrapper.h"
#include <windows.h>
#include <iostream>
//#pragma once

CLSID_ CLSID_Vector_ = 3;
IID_ IID_IPrint = 1, IID_IOperation = 2;
IID_ IID_IUnknown_ = 0, IID_ClassFactory = 1, IID_VectorFactory_ = 2;
HRESULT_ S_OK_ = 0;

typedef HRESULT_ (*FunctionArg) (CLSID_, IID_, void**);
typedef HRESULT_ (*FunctionNotArg) ();

#endif //INC_1_MODULEINFO_H
