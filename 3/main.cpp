#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Cars{
    int Price, ReleaseDate, HP, Seats;
    string color,brand,ToWD;
    void out();
    bool IsEqual(Cars);
};

struct MyStack
{
    struct Node
    {
        Cars data;
        Node *prev;
    };
    Node *Top = NULL;
    int Count;
    bool Push(Cars);
    bool Pop(Cars&);
    void Info();
    void deletion(Cars&);
};

void Cars::out(){
    cout<<" Brand: "<<brand<<endl<<" Type of Wheel Drive: "<<ToWD<<endl<<" Horse Power: "<<HP<<endl<<" Seats capacity: "<<Seats<<endl<<" Color: "<<
        color<<endl<<" Price: "<<Price<<endl<<" Release date: "<<ReleaseDate<<endl;
}

bool Cars::IsEqual(Cars a){
    if(a.brand==brand&&a.ToWD==ToWD&&a.HP==HP&&a.Seats==Seats&&a.color==color&&a.Price==Price&&a.ReleaseDate==ReleaseDate) return true;
    return false;
}

bool MyStack::Push(Cars data)
{
    if(!Top)
    {
        Top = new Node;
        Top -> prev = NULL;
        Count = 1;
    }
    else
    {
        Node *temp;
        temp = new Node;
        temp -> prev = Top;
        Top = temp;
        Count++;
    }
    Top -> data = data;
    return true;
}
bool MyStack::Pop(Cars &data)
{
    if(!Top) return false;
    Node *temp = Top -> prev;
    data = Top -> data;
    delete Top;
    Top = temp;
    Count--;
    return true;
}
void MyStack::Info()
{
    if(!Top) cout << "Garage (Stack) is empty" << endl;
    else
    {
        cout << endl << "\tGarage (Stack) info: " << endl;
        cout << "\tGarage (Stack) size = " << Count << endl;
        Top->data.out();
    }
}

void MyStack::deletion(Cars& k){
    while (Count !=0) Pop(k);
}

void read(MyStack&,string);
void FindCr(MyStack&,Cars);
void Add(MyStack&, Cars);
void Search(MyStack&, Cars);
void Menu();

int main()
{
    Menu();
    //S.deletion(k);
    return 0;

}

void Menu()
{
    Cars k;
    Cars find;
    MyStack S;
    //char* color;
    //int price;
    read(S,"Cars.txt");
    int key;

    do {
        cout<<endl;
        cout<<"-------Menu-------"<<endl;
        cout<<"1 - Show info about Garage(Stack:)) and top Car "<<endl;
        cout<<"2 - Add new Car"<<endl;
        cout<<"3 - Find Car and Take it (delete)"<<endl;
        cout<<"4 - Delete all"<<endl;
        cout<<"0 - Exit"<<endl;

        cout << "Choose what to do and enter the key " << endl;
        cin >> key;

        switch (key) {
            case 1:
                S.Info();
                break;
            case 2:
                Add(S,k);
                break;
            case 3:
                Search(S,find);
                break;
            case 4:
                S.deletion(k);
                break;
            case 0:
                S.deletion(k);
                cout << "Bye:)" << endl;
                return;
            default:
                cout << "--->Error, try again... " << endl;
        }
    } while (key);
}

void Add(MyStack& S, Cars k)
{
    cout<<"Enter Brand: ";cin>>k.brand;
    cout<<"Enter Type of Wheel Drive:: ";cin>>k.ToWD;
    cout<<"Enter Horse Power: ";cin>>k.HP;
    cout<<"Enter Seats capacity: ";cin>>k.Seats;
    cout<<"Enter Color: ";cin>>k.color;
    cout<<"Enter Price: ";cin>>k.Price;
    cout<<"Enter Release date (Year): ";cin>>k.ReleaseDate;
    S.Push(k);
}
void Search(MyStack& S, Cars find)
{
    cout<<"Find:"<<endl;
    cout<<"Which Brand: ";cin>>find.brand;
    cout<<"Which Type of Wheel Drive:: ";cin>>find.ToWD;
    cout<<"Which Horse Power: ";cin>>find.HP;
    cout<<"Which Seats capacity: ";cin>>find.Seats;
    cout<<"Which Color: ";cin>>find.color;
    cout<<"Which Price: ";cin>>find.Price;
    cout<<"Which Release date (Year): ";cin>>find.ReleaseDate;
    FindCr(S,find);
}

void read(MyStack& S,string FileName){
    ifstream F(FileName);
    if (!F){ cout<<"Error";
        return;
    }
    Cars cr;
    while(F>>cr.brand>>cr.ToWD>>cr.HP>>cr.Seats>>cr.color>>cr.Price>>cr.ReleaseDate) S.Push(cr);
    F.close();
}

void FindCr(MyStack& S,Cars find){
    Cars cr;
    MyStack second;
    while(S.Count != 0&&!(S.Top->data.IsEqual(find))){
        S.Pop(cr);
        second.Push(cr);
    }
    if(S.Count!=0){
        cout<<"Car is found"<<endl;
        S.Pop(cr);
    }
    else cout<<"Car is not found"<<endl;
    while(second.Pop(cr)) S.Push(cr);
}

/*
struct consignment {
    double Price;
    int Amount;
    void out();
};

void consignment::out() {
    cout << "Price: " << Price << " " << "Amount: " << Amount<<endl;
}

struct MyQueue
{
    struct Node
    {
        consignment data;
        Node* next;
    };
    Node* First = NULL;
    int Count = 0;
    int payment = 0;
    int full = 0;
    bool Push(consignment);
    bool Pop(consignment&);
    void Info();
};
bool MyQueue::Push(consignment data)
{
    if (!First)
    {
        First = new Node;
        First->next = NULL;
        First->data = data;
        Count = 1;
    }
    else
    {
        Node* temp;
        temp = First;
        while (temp->next != NULL) temp = temp->next;
        temp->next = new Node;
        temp->next->data = data;
        temp->next->next = NULL;
        Count++;
    }
    return true;
}
bool MyQueue::Pop(consignment& data)
{
    if (!First) return false;
    Node* temp = First->next;
    data = First->data;
    delete First;
    First = temp;
    Count--;
    return true;
}
void MyQueue::Info()
{
    if (!First) cout << "Queue is empty" << endl;
    else
    {
        cout << endl << "Queue info: " << endl;
        cout << "\tQueue size = " << Count << endl;
        First->data.out();
    }
}

void menu(MyQueue q);

int main()
{
    int n = 10;
    double db=0;
    MyQueue Q;
    menu(Q);
    return 0;

}

void menu(MyQueue q) {
    consignment Ctop;
    consignment a;
    double pr;
    int k,am;
    do {
        cout << "1.Add new product" << endl;
        cout << "2.Sell product" << endl;
        cout << "3.Report" << endl;
        cout << "0.Exit" << endl;
        cin >> k;
        switch (k) {
            case 1:
                cout << "Enter Price: "; cin >> pr;
                cout << "Enter amount: "; cin >> am;
                a.Price = pr;
                a.Amount = am;
                q.Push(a);
                q.full+=am;
                break;
            case 2:
                cout<<"Enter price: ";cin>>pr;
                cout<<"Enter amount: ";cin>>am;
                while(am!=0){
                    if(am<q.First->data.Amount&&q.First->data.Price<=pr){
                        q.First->data.Amount-=am;
                        q.payment += am * (pr - q.First->data.Price);
                        q.full -= am;
                        am=0;
                    }
                    else{
                        am-=q.First->data.Amount;
                        q.payment += q.First->data.Amount * (pr - q.First->data.Price);
                        q.full -= q.First->data.Amount;
                        q.First->data.Amount=0;
                    }
                    if (q.First->data.Amount==0){
                        q.Pop(a);
                    }
                }
                break;
            case 3:
                q.Info();
                cout << "Payment: " << q.payment << endl;
                cout << "Full: " << q.full << endl;;
                break;
            case 4:
                break;
        }
    } while (k != 0);
}*/
