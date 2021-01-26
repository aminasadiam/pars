#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

void error(string message, int line_number)
{
    cout << "\x1B[31m[Line : " << line_number << "\x1B[31m]\033[0m" << "\x1B[33m Error : " << message << "\033[0m" << endl;
    exit(0);
}

void success(string message, string cppFilename)
{
    cout << "\033[92m[ SUCCESS ] \033[0m" << message << "\x1B[33m" << cppFilename << "\033[0m" << endl;
    exit(0);
}