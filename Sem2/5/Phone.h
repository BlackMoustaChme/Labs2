#ifndef INC_5_PHONE_H
#define INC_5_PHONE_H
#include <iostream>
#include <fstream>
#include <string>
#include <dos.h>
using namespace std;
class Phone
        {
private:
    int Price;
    int ReleaseDate;
    int eDRAM;
    string color;
    string brand;
    double scrdl;
        public:
            Phone();
            Phone(int,int,int,string,string,double);
            int GetP();
            int GetR();
            int Gete();
            string Getc();
            string Getb();
            double Gets();
            void out();

        };

#endif //INC_5_PHONE_H
