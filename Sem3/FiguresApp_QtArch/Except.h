#pragma once
#include <string>
class Except
{
private:
	int code;
	std::string message;
public:
    Except(int code, std::string message);
    ~Except();
	void Show();
};

