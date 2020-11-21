#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <cstring>
#include <fstream>
#include <sstream>


#include "global_helpers.cpp"
#include "op_codes.cpp"

using namespace std;


string compile(string filename, string cppfilename)
{
    string resultCode = "";
    stringstream startcode;
    stringstream endcode;
    stringstream code;
    startcode << "#include <iostream>\n\n" << "using namespace std;\n\n" << "int main()\n" << "{\n";
    endcode << "}\n";
    string line = "";
    string result;

    ifstream inputfile(filename);

    if(inputfile.is_open())
    {
        while (getline(inputfile, line))
        {
            string value = getCode(line);
            
            resultCode = "cout << " + value + " << endl;\n";

            code << startcode.str() << resultCode << "return 0;\n" << endcode.str();

            result = code.str();
        }
    }

    return result;
}


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

            if(code == "")
            {
                error("pars file is Empty", -1);
            }
            else
            {
                string code1 = compile(filename, cppFilename);
                createCppCode(cppFilename, code1);
                success("C++ code generated at ", cppFilename);
            }
        }
        else
        {
            error("Incorrect file extension", -1);
        }
    }
    
    return 0;
}