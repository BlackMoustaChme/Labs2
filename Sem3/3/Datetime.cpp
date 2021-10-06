#include <iostream>
#include <fstream>
#include <string>
#include <dos.h>

#include "Datetime.h"

void Datetime::Set(int val, int en)
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
int Datetime::Get(int en)
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
bool Datetime::check0(int hour, int min, int second, int day, int month, int year )
{
   if (hour>-1 && hour<=24 && min>-1 && min<60 && second>-1 && second<60 && day>0 && day<32 && month>0 && month<13 && year>0)
       return true;
   else return false;
}
bool Datetime::checkleap(int year)
{
    if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
        return true;
    else return false;

}
bool Datetime::check1(int hour, int min, int second, int day, int month, int year )
{
    if ((day < 32 && (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)) || (day < 31 && (month == 4 || month == 6 || month == 9 || month == 11)) || (day < 30 && month == 2) )
        return true;
    else return false;

}
bool Datetime::check2(int hour, int min, int second, int day, int month, int year )
{
    if ((day < 32 && (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)) || (day < 31 && (month == 4 || month == 6 || month == 9 || month == 11)) || (day < 29 && month == 2) )
        return true;
    else return false;

}
void Datetime::out()//ui
{
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
Datetime::Datetime()
{

}
Datetime::~Datetime()
{

}