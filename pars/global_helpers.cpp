#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

void error(string message, int line_number)
{
    cout << "\x1B[31m[Line : \033[0m" << line_number << "\x1B[31m]\033[0m" << "\x1B[33m Error : \033[0m" << message << endl;
    exit(0);
}

void success(string message, string cppFilename)
{
    cout << "\033[92m[ SUCCESS ] " << message << cppFilename << endl;
    exit(0);
}

char is_digit(char ch)
{
    return ch["0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "."];
}