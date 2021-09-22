#include <iostream>
#include <fstream>
#include <string>
#include <dos.h>
using namespace std;
enum
{
    s1,
    min1,
    h1,
    d1,
    m1,
    yr1
};
class Date
{
private:
    int second;
    int minute;
    int hour;
    int day;
    int month;
    int year;

public:
    /*int second;
    int minute;
    int hour;
    int day;
    int month;
    int year;*/
    void out();
    void Set (int, int);
    int Get (int);
};
void Date::Set(int val, int en)
{
    switch (en)
    {
        case 0:
            second = val;
            break;
        case 1:
            minute = val;
            break;
        case 2:
            hour = val;
            break;
        case 3:
            day = val;
            break;
        case 4:
            month = val;
            break;
        case 5:
            year = val;
            break;
        default:
            cout<<"Error. Please try again";
    }
}
int Date::Get(int en)
{
    switch(en)
    {
        case 0:
            return second;
            break;
        case 1:
            return minute;
            break;
        case 2:
            return hour;
            break;
        case 3:
            return day;
            break;
        case 4:
            return month;
            break;
        case 5:
            return year;
            break;
        default:
            return 0;
    }
}

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
    cout<<" <Previous date>        <Current date>         <Next date>"<<endl;
    if (month == 1 && day == 1)
    {
        cout<<" <";
        cout<<hour<<":";
        cout<<minute<<":";
        cout<<second<<"  ";
        cout<<"31"<<"/";
        cout<<"12"<<"/";
        cout<<year-1<<"> ";
    }
    if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
    {
        if (((day <= 31 && day > 1) && (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)) || ((day <= 30 && day > 1) && (month == 4 || month == 6 || month == 9 || month == 11)) || ((day <= 29 && day > 1) && month == 2) )
        {
            cout<<" <";
            cout<<hour<<":";
            cout<<minute<<":";
            cout<<second<<"  ";
            cout<<day-1<<"/";
            cout<<month<<"/";
            cout<<year<<"> ";
        }
        if (day == 1 && (month == 2 || month == 4 || month == 6 || month == 8 || month == 9 || month == 11) )
        {
            cout<<" <";
            cout<<hour<<":";
            cout<<minute<<":";
            cout<<second<<"  ";
            cout<<"31"<<"/";
            cout<<month-1<<"/";
            cout<<year<<"> ";
        }
        if (day == 1 && (month == 5 || month == 7 || month == 10 || month == 12  ) )
        {
            cout<<" <";
            cout<<hour<<":";
            cout<<minute<<":";
            cout<<second<<"  ";
            cout<<"30"<<"/";
            cout<<month-1<<"/";
            cout<<year<<"> ";
        }
        if (day == 1 && month == 3  )
        {
            cout<<" <";
            cout<<hour<<":";
            cout<<minute<<":";
            cout<<second<<"  ";
            cout<<"29"<<"/";
            cout<<month-1<<"/";
            cout<<year<<"> ";
        }
    }
    else
    {
        if (((day <= 31 && day > 1) && (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)) || ((day <= 30 && day > 1) && (month == 4 || month == 6 || month == 9 || month == 11)) || ((day <= 28 && day > 1) && month == 2) )
        {
            cout<<" <";
            cout<<hour<<":";
            cout<<minute<<":";
            cout<<second<<"  ";
            cout<<day-1<<"/";
            cout<<month<<"/";
            cout<<year<<"> ";
        }
        if (day == 1 && (month == 2 || month == 4 || month == 6 || month == 8 || month == 9 || month == 11) )
        {
            cout<<" <";
            cout<<hour<<":";
            cout<<minute<<":";
            cout<<second<<"  ";
            cout<<"31"<<"/";
            cout<<month-1<<"/";
            cout<<year<<"> ";
        }
        if (day == 1 && (month == 5 || month == 7 || month == 10 || month == 12  ) )
        {
            cout<<" <";
            cout<<hour<<":";
            cout<<minute<<":";
            cout<<second<<"  ";
            cout<<"30"<<"/";
            cout<<month-1<<"/";
            cout<<year<<"> ";
        }
        if (day == 1 && month == 3  )
        {
            cout<<" <";
            cout<<hour<<":";
            cout<<minute<<":";
            cout<<second<<"  ";
            cout<<"28"<<"/";
            cout<<month-1<<"/";
            cout<<year<<"> ";
        }
    }

    cout<<" <";
    cout<<hour<<":";
    cout<<minute<<":";
    cout<<second<<"  ";
    cout<<day<<"/";
    cout<<month<<"/";
    cout<<year<<"> ";

    if (month == 12 && day == 31)
    {
        cout<<" <";
        cout<<hour<<":";
        cout<<minute<<":";
        cout<<second<<"  ";
        cout<<"1"<<"/";
        cout<<"1"<<"/";
        cout<<year+1<<"> ";
    }
    if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
    {
        if ((day < 31 && (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)) || (day < 30 && (month == 4 || month == 6 || month == 9 || month == 11 )) || (day < 29 && month == 2) )
        {
            cout<<" <";
            cout<<hour<<":";
            cout<<minute<<":";
            cout<<second<<"  ";
            cout<<day+1<<"/";
            cout<<month<<"/";
            cout<<year<<"> ";
        }
        if ((day == 31 && (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10)) || (day == 30 && (month == 4 || month == 6 || month == 9 || month == 11 )) || (day == 29 && month == 2) )
        {
            cout<<" <";
            cout<<hour<<":";
            cout<<minute<<":";
            cout<<second<<"  ";
            cout<<"1"<<"/";
            cout<<month+1<<"/";
            cout<<year<<"> ";
        }
    }
    else
    {
        if ((day < 31 && (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12 )) || (day < 30 && (month == 4 || month == 6 || month == 9 || month == 11 )) || (day < 28 && month == 2) )
        {
            cout<<" <";
            cout<<hour<<":";
            cout<<minute<<":";
            cout<<second<<"  ";
            cout<<day+1<<"/";
            cout<<month<<"/";
            cout<<year<<"> ";
        }
        if ((day == 31 && (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10)) || (day == 30 && (month == 4 || month == 6 || month == 9 || month == 11)) || (day == 28 && month == 2) )
        {
            cout<<" <";
            cout<<hour<<":";
            cout<<minute<<":";
            cout<<second<<"  ";
            cout<<"1"<<"/";
            cout<<month+1<<"/";
            cout<<year<<"> ";
        }
    }
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
        cout << "Current node data = "<<endl ; C->data.out();
    }
    else if (MoveFirst())
    {
        cout << "Current node data = "<<endl ; C->data.out();
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
void Task_Var14(Datetime& , Date& );

int main()
{
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
void Task_Var14 (Datetime& MyList, Date& k)
{
    Date t;
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
void Read(Datetime& MyList,string FileName)
{
    ifstream F(FileName.c_str());
    if (!F){ cout<<"Error";
        return;
    }
    int h, min, s, d, m, yr;
    Date k;
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