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
        while (getline(infile, line))
        {
            result += line + "\n";
        }
        infile.close();
    }

    return result;
}


string getCode(const string &line)
{
    static const string VALUE = "write";
    static const char DOUBLE_QUOTE = '"';
    string result = "";
    
    size_t pos = line.find(VALUE);

    if(VALUE == "write")
    {
        if(pos != string::npos)
        {
            size_t beg = line.find_first_of(DOUBLE_QUOTE, pos);

            if(beg != string::npos)
            {
                size_t end = line.find_first_of(DOUBLE_QUOTE, beg + 1);

                if(end != string::npos)
                {
                    result = line.substr(beg + 1, end - beg - 1);
                }
            }
        }
    }

    return result;
}