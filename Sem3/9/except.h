#ifndef EXCEPT_H
#define EXCEPT_H

using namespace std;
#include <string>
class Except
{
private:
    int code;
    string message;
public:
    Except(int code, string message);
    ~Except();
    void Show();
};

#endif // EXCEPT_H
