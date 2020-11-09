#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <cstring>
#include <fstream>


#include "global_helpers.cpp"
#include "op_codes.cpp"

using namespace std;


int main(int argc, char *argv[])
{
    string filename = "";
    string cppFilename = "";
    string token = "";

    for(int count{ 1 }; count < argc; ++count)
    {
        if(count >= 2)
        {
            error("Please enter only the file with the .pars extension", -1);
        }
        filename = argv[count];
        
        if(filename.substr(filename.find_last_of(".") + 1) == "pars")
        {
            token = filename.substr(0, filename.find(".pars"));
            cppFilename = token + ".cpp";
            
            string code = readParsFile(filename);
            createCppCode(cppFilename, code);
            success("C++ code generated at ", cppFilename);
        }
        else
        {
            error("Incorrect file extension", -1);
        }
    }

    return 0;
}