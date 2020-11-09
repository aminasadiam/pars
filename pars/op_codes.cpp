#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>

using namespace std;

int createCppCode(string cppFilename, string code)
{
    ofstream output (cppFilename);
    output << code << endl;

    return 0;
}