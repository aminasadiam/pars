#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int error(string message, int line_number)
{
    cout << "\x1B[31mLine : \033[0m" << line_number << "\x1B[33m Error : \033[0m" << message << endl;
    exit(0);
    return 0;
}