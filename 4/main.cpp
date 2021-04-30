#include <iostream>
#include <fstream>
#include <string>
using namespace std;




struct  Bunny {
    string name;
    double weight;
    int age;
    bool hunger;
    void out();
};

void Bunny::out() {
    cout << "Name: " << name<<endl<< " " << "Age: " << age<<endl<<  "Weight: " <<weight <<endl<< "Hungry?: " << hunger <<endl;
}

struct MyQueue
{
    struct Node
    {
        //Bunny data;
        char* data;
        int n;
        Node* next;
    };
    Node* First = NULL;
    int Count;

    bool Push(char* data, int n);
    bool Pop(char*& data, int& n);
    void Info();
};
bool MyQueue::Push( char* data, int n)
{
    if (!First)
    {
        First = new Node;
        First->next = NULL;
        First->data = new char [n];
        First->n = n;
        for (int i=0;i<n;i++)
        {
            First->data[i] = data[i];
        }
        Count = 1;
    }
    else
    {
        Node* temp;
        temp = First;
        while (temp->next != NULL) temp = temp->next;
        temp->next = new Node;
        temp->next->data =new char [n];
        temp->next->n=n;
        for (int i=0;i<n;i++)
        {
            temp->next->data[i] = data[i];
        }
        temp->next->next = NULL;
        Count++;
    }
    return true;
}
bool MyQueue::Pop(char*& data, int& n)
{
    if (!First) return false;
    Node* temp = First->next;
    //data = First->data;
    n=First->n;
    data = new char[n];
    for(int i=0;i<n;i++)
    {
        data[i]=(First->data)[i];
    }
    delete[] (First->data);
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
        //First->data.out();
    }
}
void GetDeSeria(char* , int , Bunny& );
void GetSeria(char*& , int &, Bunny );
void PrintBinaryFile (char* , int );
bool InputBinaryFile(MyQueue &);
void Add (MyQueue& , Bunny& , char*&,int& );
void Pull(MyQueue& , Bunny&, char*&,int&  );
void Clearance(MyQueue& , Bunny&, char*&,int&  );
void Menu();
/*int main()
{
    MyQueue Q;
    /*Bunny d={"Zayats",2.8,3,false};
    Bunny d1;
    d.out();
    int n;
    char* data;
    GetSeria(data,n,d);
    PrintBinaryFile (data, n);
    Bunny d2={"Volk",5.6,9,false};
    GetSeria(data,n,d2);
    PrintBinaryFile (data, n);
    Bunny d3={"Gluttony",7.5,3,true};
    GetSeria(data,n,d3);
    PrintBinaryFile (data, n);
    Bunny d4={"Mai",4.2,6,false};
    GetSeria(data,n,d4);
    PrintBinaryFile (data, n);
    //GetDeSeria(data,n,d1);
    //d1.out();
    delete[] data;
    cout<<endl<<"   - - - - - - - - - -    "<<endl;
    InputBinaryFile();
    return 0;
}*/
int main()
{
    Menu();
    return 0;

}

void Menu()
{
    MyQueue Q;
    Bunny A;
    int n;
    char* data;
    InputBinaryFile(Q);
    int key;

    do {
        cout<<endl;
        cout << "1 - Add Bunny to the queue" << endl;
        cout << "2 - Pull out Bunny" << endl;
        cout << "3 - Clear the queue" << endl;
        cout << "4 - Info on queue" << endl;
        cout << "0 - Exit" << endl;

        cout << "Choose what to do and enter the key " << endl;
        cin >> key;

        switch (key) {
            case 1:
                Add(Q,A,data,n);
                break;
            case 2:
                Pull(Q,A,data,n);
                break;
            case 3:
                Clearance(Q,A,data,n);
                break;
            case 4:
                Q.Info();
                break;
            case 0:
                cout << "Bye:)" << endl;
                return;
            default:
                cout << "--->Error, try again... " << endl;
        }
    } while (key);
    while(Q.Count)
    {
        Q.Pop(data, n);
        delete[] data;
    }
}
void Add (MyQueue& Q, Bunny& A, char*& data,int& n)
{
    cout << "Enter information about bunny:" << endl;
    cout << "Name = "; cin >> A.name;
    cout << "Weight = "; cin >> A.weight;
    cout << "Age = "; cin >> A.age;
    cout << "Hungry? - "; cin >> A.hunger;
    GetSeria(data, n, A);
    Q.Push(data, n);
}
void Pull(MyQueue& Q, Bunny& A,char*& data,int& n)
{
    Bunny Ax;
    bool m = false;
    cout << "Enter information about bunny:" << endl;
    cout << "Name = "; cin >> Ax.name;
    cout << "Weight = "; cin >> Ax.weight;
    cout << "Age = "; cin >> Ax.age;
    cout << "Hungry? - "; cin >> Ax.hunger;
    int l = Q.Count;
    for(int i = 0; i < l; i++)
    {
        Q.Pop(data, n);
        GetDeSeria(data, n, A);
        delete[] data;
        if(A.name != Ax.name || A.weight != Ax.weight || A.age != Ax.age || A.hunger != Ax.hunger)
        {
            GetSeria(data, n, A);
            Q.Push(data, n);
        }
        else
        {
            m = true;
            break;
        }
    }
    if(!m) cout << "Product not found" << endl;
}
void Clearance(MyQueue& Q, Bunny& A, char*& data,int& n)
{
    while(Q.Count)
    {
        Q.Pop(data, n);
        GetDeSeria(data, n, A);
        delete[] data;
        cout << "Name : " << A.name<< endl;
        cout << "Weight = " << A.weight<< endl;
        cout << "Age = " << A.age<< endl;
        cout << "Hungry? - " << A.hunger<< endl << endl;
    }
}
void GetSeria(char*& data, int &n, Bunny A)
{
    size_t s1 = A.name.size();
    int n1_size = sizeof(size_t);
    int n2 = s1;
    int n3 = sizeof(double);
    int n4 = sizeof(int);
    int n5 = sizeof(bool);
    n = n1_size + n2 + n3+ n4 + n5;
    data = new char [n];
    char* d1 = reinterpret_cast<char*> (&s1);
    char* d2 = const_cast<char*> (A.name.c_str());
    char* d3 = reinterpret_cast<char*> (&A.weight);
    char* d4 = reinterpret_cast<char*> (&A.age);
    char* d5 = reinterpret_cast<char*> (&A.hunger);
    for(int i = 0; i <= n1_size; i++) data[i] = d1[i];
    for(int i = 0; i <= n2; i++) data[i + n1_size] = d2[i];
    for(int i = 0; i <= n3; i++) data[i + n1_size + n2] = d3[i];
    for(int i = 0; i <= n4; i++) data[i + n1_size + n2 + n3] = d4[i];
    for(int i = 0; i <= n5; i++) data[i + n1_size + n2 + n3 + n4] = d5[i];
}
void GetDeSeria(char* data, int n, Bunny& A)
{
    int n1_size, n2, n3, n4, n5;
    n1_size = sizeof(size_t);
    n3 = sizeof(double);
    n4 = sizeof(int);
    n5 = sizeof(bool);
    size_t p = *reinterpret_cast<size_t*> (data);
    n2 = p;
    string s1(data + n1_size, p);
    A.name= s1;
    A.weight = *reinterpret_cast<double*> (data + n1_size+n2);
    A.age = *reinterpret_cast<int*> (data + n1_size+n2+n3);
    A.hunger = *reinterpret_cast<bool*> (data + n1_size+n2+n3+n4);
}
void PrintBinaryFile (char* data, int n)
{
    fstream f_out ("out.dat", ios::app | ios::binary);
    f_out.write ((char*)&n,sizeof(int));
    f_out.write (data,n);
    f_out.close();
}
bool InputBinaryFile(MyQueue &Q)
{
    fstream f_in("out.dat", ios::in | ios::binary);
    if(!f_in)
    {
        return false;
    }
    Bunny A;
    int n;
    while(!f_in.eof())
    {
        if(f_in.read((char*) &n, sizeof(int)))
        {
            char* data = new char[n];
            f_in.read(data, n);
            GetDeSeria(data, n, A);
            cout << "Name : " << A.name<< endl;
            cout << "Weight = " << A.weight<< endl;
            cout << "Age = " << A.age<< endl;
            cout << "Hungry? - " << A.hunger<< endl << endl;
            GetSeria(data, n, A);
            Q.Push(data, n);
            delete[] data;
        }
    }
    f_in.close();
    return true;
}

