#include <iostream>
#define _USE_MATH_DEFINES
#include <cmath>
#include <math.h>
#include <ctime>
#include <fstream>
#include <algorithm>
#include <iomanip>
using namespace std;
int GetN ();
void NewMatr (int **& , int , int );
void NewMatr(double **& , int , int );
void DelMatr(int **& , int , int );
void DelMatr(double **& , int , int );
void GetMatr(double ** , int , int );
void PrintMatr(int ** , int , int , const char* );
void PrintMatr(double ** , int , int , const char* );
void PrintVect(double* x, int n, const char* );
bool GetFileMatr(double ** , int , int , const char* );
void PrintFileMatr(double ** , int , int , const char* );
void GetMatrR(double ** , int , int ,int , int );
void Mult(double** , double** , double** , int , int ,int , int );
void Transpos (double **, double **, int , int);
void TriangMatr (double** , double** , int );
void Solve (double ** , double *, int );
void clone(double**& , int , int , double** );
double det(double** , int , int );
void Menu();
void MaR();
void MaF();
void MaE();
void MaNorS();
void MaH();
void SoSLAE(double **,int , int );
void FIM(double **,int , int );
void check1(double** , int , int , double *);
int main()
{
    Menu();
    return 0;
}

void Menu() {
    int key;

    do {
        cout << " ----- " << endl;
        cout << " 1 - Random" << endl;
        cout << " 2 - File" << endl;
        cout << " 3 - E" << endl;
        cout << " 4 - Null or singular Matrix" << endl;
        cout << " 5 - Hilbert Matrix" << endl;
        cout << " 0 - Exit" << endl;
        cout << " ----- " << endl;

        cout << "Choose the type of Matrix and enter the key " << endl;
        cin >> key;

        switch (key) {
            case 1:
                MaR();
                break;
            case 2:
                MaF();
                break;
                case 3:
                    MaE();
                    break;
                case 4:
                    MaNorS();
                    break;
                case 5:
                    MaH();
                    break;
            case 0:
                cout << "Bye:)" << endl;
                return;
            default:
                cout << "--->Error, try again... " << endl;
        }
    } while (key);
}

void MaR()
{
    int n,m,a,b;
    n=GetN();
    m=GetN();
    double **A;
    NewMatr(A, n, m);
    cout<<"Enter [a,b] for randomizer"<<endl;
    cout<<"Enter a = ";cin>>a;
    cout<<"Enter b = ";cin>>b;
    GetMatrR(A,n,m, a,b);

    int key;

    do {
        cout << " ----- " << endl;
        cout << " 1 - Solvation of SLAE " << endl;
        cout << " 2 - Finding the Inverse Matrix " << endl;
        cout << " 0 - Exit" << endl;
        cout << " ----- " << endl;

        cout << "Choose what to do and enter the key " << endl;
        cin >> key;

        switch (key) {
            case 1:
                SoSLAE(A,n,m);
                break;
            case 2:
                FIM(A,n,m);
                break;
            case 0:
                DelMatr(A,n,m);
                cout << "Bye:)" << endl;
                return;
            default:
                cout << "--->Error, try again... " << endl;
        }
    } while (key);
}
void MaF()
{
    int n,m;
    n=GetN();
    m=GetN();
    double **A;
    NewMatr(A, n, m);
    if(!GetFileMatr(A,n,m,"Array.txt"))
        /*PrintMatr(A,n,m,"A");*/cout << "--->Error..."<<endl;
    else /*cout << "--->Error..."<<endl;*/PrintMatr(A,n,m,"A");
    int key;

    do {
        cout << " ----- " << endl;
        cout << " 1 - Solvation of SLAE " << endl;
        cout << " 2 - Finding the Inverse Matrix " << endl;
        cout << " 0 - Exit" << endl;
        cout << " ----- " << endl;

        cout << "Choose what to do and enter the key " << endl;
        cin >> key;

        switch (key) {
            case 1:
                SoSLAE(A,n,m);
                break;
            case 2:
                FIM(A,n,m);
                break;
            case 0:
                DelMatr(A,n,m);
                cout << "Bye:)" << endl;
                return;
            default:
                cout << "--->Error, try again... " << endl;
        }
    } while (key);
}
void MaE()
{
    int n,m;
    n=GetN();
    m=GetN();
    double **A;
    NewMatr(A, n, m);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
          if (i == j) A[i][j] = 1;
          else A[i][j] = 0;
int key;

    do {
        cout << " ----- " << endl;
        cout << " 1 - Solvation of SLAE " << endl;
        cout << " 2 - Finding the Inverse Matrix " << endl;
        cout << " 0 - Exit" << endl;
        cout << " ----- " << endl;

        cout << "Choose what to do and enter the key " << endl;
        cin >> key;

        switch (key) {
            case 1:
                SoSLAE(A,n,m);
                break;
            case 2:
                FIM(A,n,m);
                break;
            case 0:
                DelMatr(A,n,m);
                cout << "Bye:)" << endl;
                return;
            default:
                cout << "--->Error, try again... " << endl;
        }
    } while (key);
}
void MaNorS()
{
    int n,m;
    n=GetN();
    m=GetN();
    double **A;
    NewMatr(A, n, m);
        int key2;

    do {
        cout << " ----- " << endl;
        cout << " 1 - NULL " << endl;
        cout << " 2 - Singular " << endl;
        cout << " 0 - Exit" << endl;
        cout << " ----- " << endl;

        cout << "Choose what to do and enter the key " << endl;
        cin >> key2;

        switch (key2) {
            case 1:
                if(!GetFileMatr(A,n,m,"Null.txt"))
        /*PrintMatr(A,n,m,"A");*/cout << "--->Error..."<<endl;
        else /*cout << "--->Error..."<<endl;*/PrintMatr(A,n,m,"A");
                break;
            case 2:
                if(!GetFileMatr(A,n,m,"Singular.txt"))
        /*PrintMatr(A,n,m,"A");*/cout << "--->Error..."<<endl;
        else /*cout << "--->Error..."<<endl;*/PrintMatr(A,n,m,"A");
                break;
            case 0:
                cout << " ---- " << endl;
                return;
            default:
                cout << "--->Error, try again... " << endl;
        }
    } while (key2);
int key;

    do {
        cout << " ----- " << endl;
        cout << " 1 - Solvation of SLAE " << endl;
        cout << " 2 - Finding the Inverse Matrix " << endl;
        cout << " 0 - Exit" << endl;
        cout << " ----- " << endl;

        cout << "Choose what to do and enter the key " << endl;
        cin >> key;

        switch (key) {
            case 1:
                SoSLAE(A,n,m);
                break;
            case 2:
                FIM(A,n,m);
                break;
            case 0:
                DelMatr(A,n,m);
                cout << "Bye:)" << endl;
                return;
            default:
                cout << "--->Error, try again... " << endl;
        }
    } while (key);
}
void MaH()
{
    int n,m;
    n=GetN();
    m=GetN();
    double **A;
    NewMatr(A, n, m);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
          if (j == (m - 1)) A[i][j] = 1;
          else A[i][j] = 1. / (i + j + 1);
int key;

    do {
        cout << " ----- " << endl;
        cout << " 1 - Solvation of SLAE " << endl;
        cout << " 2 - Finding the Inverse Matrix " << endl;
        cout << " 0 - Exit" << endl;
        cout << " ----- " << endl;

        cout << "Choose what to do and enter the key " << endl;
        cin >> key;

        switch (key) {
            case 1:
                SoSLAE(A,n,m);
                break;
            case 2:
                FIM(A,n,m);
                break;
            case 0:
                DelMatr(A,n,m);
                cout << "Bye:)" << endl;
                return;
            default:
                cout << "--->Error, try again... " << endl;
        }
    } while (key);
}
void SoSLAE(double **A,int n, int m)
{
    PrintMatr(A,n,m,"A");
    double** buff;
    NewMatr(buff, n, m);
    double** B;
    NewMatr(B, n, n+1);
    clone(A, n, m, buff);
    double *x = new double[n];
    PrintMatr(A,n,m,"A");
    Solve (A,x,n);
    PrintVect(x,n,"x");
    TriangMatr(buff, B, n);
    //double det=det(B,n,m);
    cout<<endl<<det(B,n,m);
    //DelMatr(B,n,n+1);
    DelMatr(buff,n,m);
    PrintMatr(B,n,m,"A");
    check1(A,n,m,x);
    DelMatr(B,n,n+1);
    //DelMatr(A,n,m);
    delete[]x;x=NULL;

}
void FIM(double **A,int n, int m)
{
    double *x = new double [n];
    PrintMatr(A,n,m,"A");
    double** B;
    NewMatr(B, n, m-1);
    clone(A, n, m-1, B);
    PrintMatr(B,n,m-1,"B");
    double** D;
    NewMatr(D, n, m-1);
    TriangMatr(A, D, n);
    //double det=det(buff,n,m);
    cout<<endl<<det(D,n,m);
    //Solve (A,x,n);
    for(int i = 0; i < n; i++)
    {
        double** buff;
        NewMatr(buff, n, m);
        clone(A, n, m, buff);
        for(int j = 0; j < n; j++)
        {
            if (i == j) buff[j][m - 1] = 1;
            else buff[j][m - 1] = 0;
        }
        Solve(buff, x, n);
        for(int j = 0; j < n; j++)
            B[j][i] = x[j];
        DelMatr(buff, n, m);
    }
    delete [] x;
    x = NULL;
    PrintMatr(B,n,m-1,"B");
    //Mult(A, B, n, m - 1, n, n);
    //check2();
    DelMatr(B,n,m);
    DelMatr(A,n,m);
}
void clone(double**& M, int n, int m, double** M1)
{
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
        {
            M1[i][j] = M[i][j];
        }
}
double det(double** M, int n, int m)
{
    double det = 1;
    for(int i = 0; i < n; i++)
    {
        if (M[i][i] == 0) return 0;
        det *= M[i][i];
    }
    return det;
}
void check1(double** M1, int n, int m, double *x)
{
    double epsilon = 0;
    double s;
    for(int i = 0; i < n; i++)
    {
        s = 0;
        for(int k = 0; k < m - 1; k++)
        {
            s += M1[i][k] * x[k];
        }
        cout<<s<<endl;
        if (fabs(M1[i][m - 1] - s) > epsilon) epsilon = fabs(M1[i][m - 1] - s);
    }
    //return epsilon;
    cout<<epsilon;
}
int GetN ()
{
    float n;
    do
    {
        cout<<"Enter Natural number: ";
        cin>>n;
        if (n<=0 || (n-(int)n))
        {
            cout << "--->Error, please follow given recommendations and try again... " << endl;
        }
    }
    while (n<=0 || (n-(int)n));
    return n;
}
void NewMatr (int **& M, int n, int m)
{
    cout<<"\t -New int Matr-"<<endl;
    M=new int* [n];
    for (int i=0;i<n;i++)
    {
        M[i]=new int [m];
    }
}
void DelMatr (int **& M, int n, int m)
{
    cout<<"\t -Delete int Matr-"<<endl;
    for (int i=0;i<n;i++)
    {
        delete []M[i];
    }
    delete []M;
}
void NewMatr (double **& M, int n, int m)
{
    cout<<"\t -New double Matr-"<<endl;
    M=new double* [n];
    for (int i=0;i<n;i++)
    {
        M[i]=new double [m];
    }
}
void DelMatr (double **& M, int n, int m)
{
    cout<<"\t -Delete double Matr-"<<endl;
    for (int i=0;i<n;i++)
    {
        delete []M[i];
    }
    delete []M;
}
void GetMatr (double ** M, int n, int m)
{
    cout<<"Enter Matrix, sized "<<n<<" x "<<m<<" : "<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>M[i][j];
        }
    }
}
void PrintMatr (int ** M, int n, int m, const char* namae)
{
    cout<<endl<<" "<<namae<<":"<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cout<<setw(5)<<M[i][j];
        }
        cout<<endl;
    }
    cout<<endl;
}
void PrintMatr (double ** M, int n, int m, const char* namae)
{
    cout<<endl<<" "<<namae<<":"<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cout<<setw(5)<<M[i][j];
        }
        cout<<endl;
    }
    cout<<endl;
}
void PrintVect(double* x, int n, const char* namae)
{
    cout << endl << " " << namae << ":" << endl;
    for(int i = 0; i < n; i++)
    {
        cout << setw(5) << x[i];
        cout << endl;
    }
    cout << endl;
}
bool GetFileMatr (double ** M, int n, int m, const char* name)
{
    ifstream f(name);
    if (!f)
    {
        cout<<"--->Error, no input file"<<endl;
        return false;
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(!(f>>M[i][j]))
            {
                cout<<"--->Error, the file data is not enough"<<endl;
                f.close();
                return false;
            }
        }
    }
    f.close();
    return true;
}
void PrintFileMatr (double ** M, int n, int m, const char* name)
{
    ofstream f(name);
    for (int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            f<<setw(5)<<M[i][j];
        }
        f<<endl;
    }
    f<<endl;
    f.close();
}
void GetMatrR (double ** M, int n, int m,int a, int b)
{
    srand(time(0));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            M[i][j]=rand()%(b-a-1)+a;
        }
    }
}
void Mult (double** M1, double** M2, double** res, int n1, int m1,int n2, int m2)
{
    int S;
    if(m1!=n2)
    {
        cout<<"--->Error, the multiplied matrices dimensions are incorrect";
        return;
    }
    for(int i=0;i<n1;i++)
    {
        for(int j=0;i<m2;j++)
        {
            S=0;
            for(int k=0;k<m1;k++)
            {
                S+=M1[i][k]*M2[k][j];
            }
            res[i][j]=S;
        }
    }
}
void Transpos (double **M1, double **M2, int n, int m)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            M1[i][j]=M2[j][i];
        }
    }
}
void TriangMatr (double** A, double** B, int n)
{
    double koef;
    for (int i=0;i<n;i++)
    {
        for(int j=0;j<n+1;j++)
        {
            B[i][j]=A[i][j];
        }
    }
    for(int k=0;k<n;k++)
    {
        for(int i=k+1;i<n;i++)
        {
            koef=-1.*B[i][k]/B[k][k];
            for(int j=k;j<n+1;j++)
            {
                B[i][j]=B[i][j]+B[k][j]*koef;
            }
        }
    }
    PrintMatr(B,n,n+1,"B");
}
void Solve (double ** A, double *x, int n)
{
    double res=0;
    double **B;
    NewMatr(B,n,n+1);
    TriangMatr(A, B, n);
    for (int i=n-1;i>=0;i--)
    {
        res=0;
        for(int j=i+1;j<=n-1;j++)
        {
            res=res-x[j]*B[i][j];
        }
        res+=B[i][n];
        x[i]=res/B[i][i];
    }
    DelMatr(B,n,n+1);
}
