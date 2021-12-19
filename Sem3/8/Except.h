#ifndef INC_8_EXCEPT_H
#define INC_8_EXCEPT_H
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

#endif //INC_8_EXCEPT_H
