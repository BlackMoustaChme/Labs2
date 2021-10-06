#include <iostream>
#include <fstream>
#include <string>
#include <dos.h>

#include "DataObtaining.h"
#include "Datetime.h"
#include "DLList.h"

void Read(DLList& MyList,string FileName)
{
    ifstream F(FileName.c_str());
    if (!F){ cout<<"Error";
        return;
    }
    int h, min, s, d, m, yr;
    Datetime k;
    while(F>>h>>min>>s>>d>>m>>yr)
    {
        k.Set(h, h1);
        k.Set(min, min1);
        k.Set(s, s1);
        k.Set(d, d1);
        k.Set(m, m1);
        k.Set(yr, yr1);
        if (k.Get(h1)>-1 && k.Get(h1)<=24 && k.Get(min1)>-1 && k.Get(min1)<60 && k.Get(s1)>-1 && k.Get(s1)<60 && k.Get(d1)>0 && k.Get(d1)<32 && k.Get(m1)>0 && k.Get(m1)<13)//checking dates
            if (((k.Get(yr1) % 4 == 0) && (k.Get(yr1) % 100 != 0)) || (k.Get(yr1) % 400 == 0))
            {
                if ((k.Get(d1) < 32 && (k.Get(m1) == 1 || k.Get(m1) == 3 || k.Get(m1) == 5 || k.Get(m1) == 7 || k.Get(m1) == 8 || k.Get(m1) == 10 || k.Get(m1) == 12)) || (k.Get(d1) < 31 && (k.Get(m1) == 4 || k.Get(m1) == 6 || k.Get(m1) == 9 || k.Get(m1) == 11)) || (k.Get(d1) < 30 && k.Get(m1) == 2) )
                {
                    MyList.AddNext(k);
                }
            }
            else
            {
                if ((k.Get(d1) < 32 && (k.Get(m1) == 1 || k.Get(m1) == 3 || k.Get(m1) == 5 || k.Get(m1) == 7 || k.Get(m1) == 8 || k.Get(m1) == 10 || k.Get(m1) == 12)) || (k.Get(d1) < 31 && (k.Get(m1) == 4 || k.Get(m1) == 6 || k.Get(m1) == 9 || k.Get(m1) == 11)) || (k.Get(d1) < 29 && k.Get(m1) == 2) )
                {
                    MyList.AddNext(k);
                }
            }
    }
    F.close();
}