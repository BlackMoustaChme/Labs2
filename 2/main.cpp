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
void NewMatr(double **& , int , int );
void DelMatr(double **& , int , int );
void GetMatr(double ** , int , int );
void PrintMatr(double ** , int , int , const char* );
void PrintVect(double* x, int n, const char* );
bool GetFileMatr(double ** , int , int , const char* );
void PrintFileMatr(double ** , int , int , const char* );
void GetMatrR(double ** , int , int ,int , int );
void Mult(double** , double** , double** , int , int ,int , int );
void TriangMatr (double** , double** , int );
void Solve (double ** , double *, int );
void clone(double**& , int , int , double** );
//double det(double** , int , int );

bool minor(double**& , int , int , double &);
void reshuffle(double**& , int , int, int , double &);
bool SolveAP(double **&, double *, int , int , double &);
double det(double** , int , int );
bool reverbAP(double** , int , int , double &, double**& );

void Menu();
void MaR();
void MaF();
void MaE();
void MaNorS();
void MaH();
void SoSLAE(double **,int , int ,double);
void FIM(double **,int , int,double);
void check1(double** , int , int , double *);
void check2(double**, double**, int, int, int , int);
int main()
{
    cout<<"Liakhim: Yrros, ris, tub siht si ton 001% lanigiro"<<endl;
    //cout<<"BA WEEP GRANAH WEEP NINI BONG!"<<endl;
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
    m=n+1;
    double **A;
    double Det=1;
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
                SoSLAE(A,n,m,Det);
                break;
            case 2:
                FIM(A,n,m,Det);
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
    m=n+1;
    double **A;
    double Det=1;
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
                SoSLAE(A,n,m,Det);
                break;
            case 2:
                FIM(A,n,m,Det);
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
    m=n+1;
    double **A;
    double Det=1;
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
                SoSLAE(A,n,m,Det);
                break;
            case 2:
                FIM(A,n,m,Det);
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
    m=n+1;
    double **A;
    double Det=1;
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
                break;
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
                SoSLAE(A,n,m,Det);
                break;
            case 2:
                FIM(A,n,m,Det);
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
    m=n+1;
    double Det=1;
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
        cout << " Please continue " << endl;

        cout << "Choose what to do and enter the key " << endl;
        cin >> key;

        switch (key) {
            case 1:
                SoSLAE(A,n,m,Det);
                break;
            case 2:
                FIM(A,n,m,Det);
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
void SoSLAE(double **A,int n, int m, double Det)
{
    double *x = new double [n];
    double ** B;
    NewMatr(B, n, m);
    clone(A, n, m, B);
    double ** Ac;
    NewMatr(Ac, n, m);
    clone(A, n, m, Ac);
    //double Det=1;
    PrintMatr(Ac,n,m,"A");
    if (SolveAP(Ac, x, n, m, Det))
    {
        check1(B, n, m, x);
    }
    else cout << "no single solution" << endl;
    cout <<endl<< "det = " << Det * det(Ac, n, m) << endl;
    DelMatr(B, n, m);
    DelMatr(Ac, n, m);
    delete [] x;
    x = NULL;
    /*double** buff;
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
    delete[]x;x=NULL;*/

}
void FIM(double **A,int n, int m, double Det)
{
    PrintMatr(A,n,m,"A");
    double **rev;
    //double Det=1;
    NewMatr(rev, n, n);

    if (reverbAP(A, n, m, Det, rev))
    {
        PrintMatr(rev, n, n, "rev");
        check2(A, rev, n, m - 1, n, n);
    }
    else cout << "no reverb" << endl;
    DelMatr(rev, n, n);
}
void clone(double**& M, int n, int m, double** M1)
{
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
        {
            M1[i][j] = M[i][j];
        }
}
/*double det(double** M, int n, int m)
{
    double det = 1;
    for(int i = 0; i < n; i++)
    {
        if (M[i][i] == 0) return 0;
        det *= M[i][i];
    }
    return det;
}*/
void check1(double** M1, int n, int m, double *x)
{
    double epsilon = 0;
    double s;
    PrintVect(x,n,"x");
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
    cout<<"epsilon = "<<epsilon;
}
void reshuffle(double**& M, int n, int m, int k, double &Det)
{
    for (int i = k + 1; i < n; i++)
    {
        if (M[i][k] != 0)
        {
            double temp;
            for (int i1 = 0; i1 < m; i1++)
            {
                temp = M[k][i1];
                M[k][i1] = M[i][i1];
                M[i][i1] = temp;
            }
            Det *= -1;
            break;
        }
    }
}
bool minor(double**& M, int n, int m, double &Det)
{
    for (int  i = 0; i < n ; i++)
    {
        if (M[i][i] == 0) reshuffle(M, n, m, i, Det);
        if (M[i][i] == 0) return false;
        for (int i1 = i + 1; i1 < n; i1++)
            for (int i2 = i + 1; i2 < m; i2++)
                M[i1][i2] = M[i][i] * M[i1][i2] - M[i][i2] * M[i1][i];
        for (int j = i + 1; j < n; j++)
        {
            M[j][i] = 0;
        }
    }
    return true;
}
bool SolveAP(double **&M, double *x, int n, int m, double &Det)
{
    double res = 0;
    if (!minor(M, n, m, Det)) return false;
    for(int i = n - 1; i >= 0; i--)
    {
        res = 0;
        for(int j = i + 1; j <= n - 1; j++)
            res = res - x[j] * M[i][j];
        res += M[i][n];
        x[i] = res / M[i][i];
    }
    return true;
}
double det(double** M, int n, int m)
{
    double det = 1;
    for(int i = 0; i < n; i++)
    {
        if (M[i][i] == 0) return 0;
        det *= M[i][i] / pow(M[i][i], n - 1 - i);
    }
    return det;
}
bool reverbAP(double** M, int n, int m, double &Det, double**& rev)
{
    double *x = new double [n];
    bool metka = true;
    for(int i = 0; i < n; i++)
    {
        double** buff;
        NewMatr(buff, n, m);
        clone(M, n, m, buff);
        for(int j = 0; j < n; j++)
        {
            if (i == j) buff[j][m - 1] = 1;
            else buff[j][m - 1] = 0;
        }
        if (!SolveAP(buff, x, n, m, Det)) metka = false;
        //PrintVect(x, n, "x");
        for(int j = 0; j < n; j++)
            rev[j][i] = x[j];
        DelMatr(buff, n, m);
    }
    delete [] x;
    x = NULL;
    return metka;
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
void PrintMatr (double ** M, int n, int m, const char* namae)
{
    cout<<endl<<" "<<namae<<":"<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cout<<setw(15)<<M[i][j];
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
/*void Mult (double** M1, double** M2, double** res, int n1, int m1,int n2, int m2)
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
}*/
void check2(double** M1, double** M2, int n1, int m1, int n2, int m2)
{
    double** buff;
    NewMatr(buff, n1, m2);
    double S;
    if(m1 != n2)
    {
        cout << "error" << endl;
        DelMatr(buff, n1, m2);
    }
    for(int i = 0; i < n1; i++)
        for(int j = 0; j < m2; j++)
        {
            S = 0;
            for(int k = 0; k < m1; k++)
                S += M1[i][k] * M2[k][j];
            buff[i][j] = S;
        }
    PrintMatr(buff, n1, m2, "proverka");
    DelMatr(buff, n1, m2);
}
