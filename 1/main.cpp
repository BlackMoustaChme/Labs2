//A.N.E.I.D.A Applying New Element In Dynamic Array
//D.E.D.A Deleting Elements Of Dynamic Array
#include <iostream>
#define _USE_MATH_DEFINES
#include <cmath>
#include <math.h>
#include <ctime>
#include <stdlib.h>
using namespace std;

double * CreateArr(int);
void FillArr(double *, int);
void PrintArr(double * , int);
void Reassign(double *&, int &,int,double);
void DelArr(double *&, int &,int );
void Task7b(double *&, int &,double );
void Task8(double *&, int &,double );
int main()
{
    int n,k,t;
    double f,q,g;
    cout<<"Enter the size of Array"<<endl;
    cin>>n;
    double *arr=CreateArr(n);
    FillArr(arr,n);
    PrintArr(arr,n);
    cout<<"Enter k = ";
    cin>>k;
    cout<<"Enter f = ";
    cin>>f;
    Reassign(arr,n,k,f);
    PrintArr(arr,n);
    cout<<"Enter q = ";
    cin>>q;
    Task7b(arr,n,q);
    cout<<"Enter g = ";
    cin>>g;
    Task8(arr,n,g);
    /*cout<<"Enter t = ";
    cin>>t;
    DelArr(arr,n,t);*/
    PrintArr(arr,n);
    delete[] arr;
    return 0;
}
double * CreateArr(int n)
{
    double *arr=new double[n];
    return arr;
}
void PrintArr(double *arr , int n)
{
    for (int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void FillArr(double *arr, int n)
{
    srand(time(0));
        for (int i=0;i<n;i++)
    {
        //arr[i]=i;
        arr[i]= rand() % 10;
    }
}
void Reassign(double *&arr, int &n,int k,double f)
{
    if (k>=0 && k<=n)
    {
        double *buff=new double[n+1];
        for (int i=0;i<k-1;i++)
        {
            buff[i]=arr[i];
        }
        buff[k-1]=f;
        for (int i=k;i<=n;i++)
        {
            buff[i]=arr[i-1];
        }
        delete[] arr;
        arr=buff;
        n++;
        PrintArr(buff,n);
    }
    else cout<<"Error";
}
void DelArr(double *&arr, int &n,int k)
{
    if (k>=0 && k<=n)
    {
        double *buff=new double[n-1];
        for (int i=0;i<k-1;i++)
        {
            buff[i]=arr[i];
        }
        n--;
        for (int i=k;i<=n;i++)
        {
            buff[i-1]=arr[i];
        }
        delete[] arr;
        arr=buff;
        PrintArr(buff,n);
    }
    else cout<<"Error";
}
void Task7b(double *&arr, int &n,double f)
{
    int k=0,r=-1,t=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]==f)
        {
            k=1;
            t++;
        }
        else
        {
            k=0;
        }
        if(k==1 && t<2)
        {
            r=i;
        }
    }
    if(r==-1)
    {
        cout<<endl<<"----There is no element with such value"<<endl<<endl;
    }
    else
    {
    Reassign(arr,n,r+1,f);
    PrintArr(arr,n);
    }
}
void Task8(double *&arr, int &n,double f)
{
    int r=-1;
    for(int i=0;i<n;i++)
    {
        if(arr[i]==f)
        {
            DelArr(arr,n,i+1);
            r++;
        }
    }
    if(r==-1)
    {
        cout<<endl<<"----There is no element with such value"<<endl<<endl;
    }
    else
    {
    PrintArr(arr,n);
    }
}

