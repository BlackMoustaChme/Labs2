#include <iostream>
#include <fstream>
#include <string>
#include <dos.h>
using namespace std;

struct Date
{
    int second;
    int minute;
    int hour;
    int day;
    int month;
    int year;
    void out();
};

struct Datetime
{
    struct Node
    {
        Date data;
        Node *next;
        Node *prev;
    };
    Node *F = NULL;
    Node *L = NULL;
    Node *C = NULL;
    int Count;
    void Out();
    void Info();
    void Clear();

    bool MoveNext();
    bool MovePrev();
    bool MoveFirst();
    bool MoveLast();

    bool Init(Date);
    bool AddNext(Date);
    bool AddPrev(Date);
    bool AddFirst(Date);
    bool AddLast(Date);

    bool Del(Date&);
    bool DelNext(Date&);
    bool DelPrev(Date&);
    bool DelFirst(Date&);
    bool DelLast(Date&);

};
void Date::out(){
    cout<<" < ";
    cout<<hour<<":";
    cout<<minute<<":";
    cout<<second<<"  ";
    cout<<day<<"/";
    cout<<month<<"/";
    cout<<year<<" > ";
}

bool Datetime::MoveNext()
{
    if(!F)       return false;
    if(!C)       {C=F; return true;}
    if(!C->next) return false;
    C=C->next;
    return true;
}

bool Datetime::MovePrev()
{
    if(!F)       return false;
    if(!C)       {C=F; return true;}
    if(!C->prev) return false;
    C=C->prev;
    return true;
}
bool Datetime::MoveFirst()
{
    if(!F) return false;
    C=F;
    return true;
}

bool Datetime::MoveLast()
{
    if(!L) return false;
    C=L;
    return true;
}

bool Datetime::Init(Date data)
{
    if(!F)
    {
        F=new Node;
        L=F;
        C=F;
        F->prev=NULL;
        F->next=NULL;
        F->data = data;
        Count=1;
        return true;
    }
    else
        return false;
}

bool Datetime::AddNext(Date data)
{
    if(!F) return Init(data);

    Node* temp=C->next;
    C->next=new Node;
    C->next->next=temp;
    C->next->prev=C;

    if(!temp)
        L=C->next;
    else
        temp->prev=C->next;

    C=C->next;
    C->data=data;
    Count++;
    return true;

}

bool Datetime::AddPrev(Date data)
{
    if(!F) return Init(data);

    Node* temp=C->prev;
    C->prev=new Node;
    C->prev->next=C;
    C->prev->prev=temp;

    if(!temp)
        F=C->prev;
    else
        temp->next=C->prev;

    C=C->prev;
    C->data=data;
    Count++;
    return true;
}

bool Datetime::AddFirst(Date data)
{
    if (MoveFirst())return AddPrev(data);
    else return false;
}

bool Datetime::AddLast(Date data)
{
    if (MoveLast())return AddNext(data);
    else return false;
}

void Datetime::Out()
{
    if(!F)  {
        cout<<"List is empty"<<endl;
        return;
    }

    Node* temp=F;
    cout<<"List: "<<endl;
    do
    {
        temp->data.out();
        cout<<endl<<" ------------------------- "<<endl;
        temp=temp->next;
    }
    while(temp);
    cout<<endl;
}

void Datetime::Info()
{

    if(Count) cout << "List node count: " <<Count<< endl;
    else
        cout << "List is empty" << endl;
    if(C)
    {
        cout << "Current node data = " ; C->data.out();
    }
    else if (MoveFirst())
    {
        cout << "Current node data = " ; C->data.out();
    }

}

bool Datetime::DelFirst(Date& data)
{
    if(!F)      return false;
    if(C!=F)    MoveFirst();

    Node* temp = C->next;
    data = C->data;

    if(temp) temp->prev=NULL;
    delete C;

    C=temp;
    F=temp;
    Count--;
    if(!temp) {L=NULL; return false;}
    return true;
}

bool Datetime::DelLast(Date& data)
{
    if(!F)      return false;
    if(C!=L)    MoveLast();

    Node* temp = C->prev;
    data = C->data;

    if(temp) temp->next=NULL;
    delete C;

    C=temp;
    L=temp;
    Count--;

    if(!temp) {F=NULL; return false;}
    return true;
}

bool Datetime::Del(Date& data)
{
    if(!F) return false;
    if(!C) return false;

    if(C==F) return DelFirst(data);
    if(C==L) return DelLast(data);

    Node* temp = C->next;
    data=C->data;

    C->prev->next=C->next;
    C->next->prev=C->prev;

    delete C;
    C=temp;
    Count--;
    return true;
}

bool Datetime::DelNext(Date& data)
{
    if(!F) return false;
    if(!C) return false;
    if (MoveNext()) return Del(data);
    return false;
}
bool Datetime::DelPrev(Date& data)
{
    if(!F) return false;
    if(!C) return false;
    if (MovePrev()) return Del(data);
    return false;
}

void Datetime::Clear()
{
    if(!MoveFirst())
    {
        cout<<"List is empty"<<endl;
        return;
    }
    Date k;
    while(Del(k));
}

void Menu();
void Read(Datetime& ,string );
void Sort(Datetime& , Date& );
void Sort2(Datetime& , Date& );
void Bubble (Datetime& , Date& , int );
bool Compare(Datetime& , Date& , int );
//void Record(DLList& ,string );
int main()
{
    //cout<<"Liakhim: Yrros, ris, tub siht ebyam eb ton 001% lanigiro"<<endl;
    Menu();
    return 0;

}
void Menu()
{
    Datetime MyList;
    Date k;
    Read(MyList,"Dates.txt");
    int key;

    do {
        cout<<endl;
        cout<<endl<<" ------------------------- "<<endl;
        cout<<"1 - Add element "<<endl;
        cout<<"2 - Delete element"<<endl;
        cout<<"3 - Sort"<<endl;
        cout<<"4 - Clear List"<<endl;
        cout<<"5 - Sort2"<<endl;
        cout<<"6 - Info"<<endl;
        cout<<"0 - Exit"<<endl;
        cout<<endl<<" ------------------------- "<<endl;
        cout << "Choose what to do and enter the key " << endl;
        cin >> key;

        switch (key) {
            case 1:
                //Add(MyList,k);
                break;
            case 2:
                //Delt(MyList,k);
                break;
            case 3:
                Sort(MyList,k);
                break;
            case 4:
                MyList.Clear();
                break;
            case 5:
                Sort2(MyList,k);
                break;
            case 6:
                MyList.Info();
                cout<<endl;
                MyList.Out();
                break;
            case 0:
                cout << "Bye:)" << endl;
                return;
            default:
                cout << "--->Error, try again... " << endl;
        }
    } while (key);
}

void Sort(Datetime& MyList, Date& k)
{
    int key;

    do {
        cout<<endl;
        cout<<"By What you want to sort?"<<endl;
        cout<<endl<<" ------------------------- "<<endl;
        cout<<"1 - By Hour"<<endl;
        cout<<"2 - By Minute"<<endl;
        cout<<"3 - By Second"<<endl;
        cout<<"4 - By Day"<<endl;
        cout<<"5 - By Month"<<endl;
        cout<<"6 - By Year"<<endl;
        cout<<"0 - Exit"<<endl;
        cout<<endl<<" ------------------------- "<<endl;
        cout << "Choose what to do and enter the key " << endl;
        cin >> key;

        switch (key) {
            case 1:
                Bubble(MyList,k,key);
                break;
            case 2:
                Bubble(MyList,k,key);
                break;
            case 3:
                Bubble(MyList,k,key);
                break;
            case 4:
                Bubble(MyList,k,key);
                break;
            case 5:
                Bubble(MyList,k,key);
                break;
            case 6:
                Bubble(MyList,k,key);
                break;
            case 0:
                cout << "Bye:)" << endl;
                return;
            default:
                cout << "--->Error, try again... " << endl;
        }
    } while (key);
}
bool Compare(Datetime& MyList, Date& k,int key)
{
    switch (key) {
        case 1:
            if (MyList.C->data.hour > MyList.C->prev->data.hour) return true;
            break;
        case 2:
            if (MyList.C->data.minute > MyList.C->prev->data.minute) return true;
            break;
        case 3:
            if (MyList.C->data.second > MyList.C->prev->data.second) return true;
            break;
        case 4:
            if (MyList.C->data.day > MyList.C->prev->data.day) return true;
            break;
        case 5:
            if (MyList.C->data.month > MyList.C->prev->data.month) return true;
            break;
        case 6:
            if (MyList.C->data.year > MyList.C->prev->data.year) return true;
            break;
    }
    return false;
}
void Bubble (Datetime& MyList, Date& k, int key)
{
    Date t;
    for (int i=0;i<MyList.Count-1;i++)
    {
        MyList.MoveLast();
        for (int j = MyList.Count - 2; j >= i; j--)
        {
            if (Compare(MyList,k,key)) {
                t = MyList.C->data;
                MyList.C->data = MyList.C->prev->data;
                MyList.C->prev->data = t;
            }
            MyList.MovePrev();
        }
    }
}
void Sort2 (Datetime& MyList, Date& k)
{
    Date t;
    bool b=true;
    MyList.MoveFirst();
    for (int i=0;i<MyList.Count;i++)
    {
        while (b)
        {
            if (MyList.C->data.month == 12)
            {
                if (MyList.C->data.day == 31)
                {
                    break;
                }
            }
            else if (MyList.C->data.month == 1)
            {
                if (MyList.C->data.day == 1)
                {
                    break;
                }
            }
            MyList.C->data.out();
            break;
        }
        MyList.MoveNext();
    }
}

void Read(Datetime& MyList,string FileName)
{
    ifstream F(FileName.c_str());
    if (!F){ cout<<"Error";
        return;
    }
    Date k;
    while(F>>k.hour>>k.minute>>k.second>>k.day>>k.month>>k.year)
    {
        if (k.hour>-1 && k.hour<=24 && k.minute>-1 && k.minute<60 && k.second>-1 && k.second<60 && k.day>0 && k.day<32 && k.month>0 && k.month<13)//checking dates
            if (((k.year % 4 == 0) && (k.year % 100 != 0)) || (k.year % 400 == 0))
        {
            MyList.AddNext(k);
        }
    }
    F.close();
}
