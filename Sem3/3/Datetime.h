#ifndef INC_3_DATETIME_H
#define INC_3_DATETIME_H

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
class Datetime
{
private:
    int second;
    int minute;
    int hour;
    int day;
    int month;
    int year;
    bool check0(int, int, int, int, int, int);
    bool checkleap(int);
    bool check1(int, int, int, int, int, int);
    bool check2(int, int, int, int, int, int);

public:
    Datetime();
    Datetime(int, int, int, int, int, int);
    ~Datetime();
    void out();
    void Set (int, int);
    int Get (int);
};

#endif //INC_3_DATETIME_H
