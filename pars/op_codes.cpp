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

string readParsFile(string filename)
{
    string result = "";
    ifstream infile(filename);
    if(infile.is_open())
    {
        string line;
        while (getline(infile, line, ' '))
        {
            result += line.c_str();
        }
        infile.close();
    }

    return result;
}