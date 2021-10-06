#include <iostream>
#include <fstream>
#include <string>
#include <dos.h>

#include "UI.h"
#include "Datetime.h"
#include "DLList.h"
#include "DataObtaining.h"

void Menu()
{
    DLList MyList;
    Datetime k;
    DataObtaining R;
    R.Read(MyList,"Dates.txt");
    int key;

    do {
        cout<<endl;
        cout<<endl<<" ------------------------- "<<endl;
        cout<<"1 - Info (List of Dates) "<<endl;
        cout<<"2 - Task_Var14"<<endl;
        cout<<"3 - Clear List"<<endl;
        cout<<"0 - Exit"<<endl;
        cout<<endl<<" ------------------------- "<<endl;
        cout << "Choose what to do and enter the key " << endl;
        cin >> key;

        switch (key) {
            case 1:
                MyList.Info();
                cout<<endl;
                MyList.Out();
                break;
            case 2:
                Task_Var14(MyList,k);
                break;
            case 3:
                MyList.Clear();
                break;
            case 0:
                cout << "Bye:)" << endl;
                return;
            default:
                cout << "--->Error, try again... " << endl;
        }
    } while (key);
}
void Task_Var14 (DLList& MyList, Datetime& k)
{
    Datetime t;
    bool b=true;
    MyList.MoveFirst();
    for (int i=0;i<MyList.Count;i++)
    {
        while (b)
        {
            if (MyList.C->data.Get(m1) == 12)
            {
                if (MyList.C->data.Get(d1) == 31)
                {
                    break;
                }
            }
            else if (MyList.C->data.Get(m1) == 1)
            {
                if (MyList.C->data.Get(d1) == 1)
                {
                    break;
                }
            }
            cout<<endl<<" ------------------------- "<<endl;
            MyList.C->data.out();
            cout<<endl<<" ------------------------- "<<endl;
            break;
        }
        MyList.MoveNext();

    }
}

