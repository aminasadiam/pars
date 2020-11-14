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
    stringstream code;
    string line = "";
    string result;

    ifstream inputfile(filename);

    if(inputfile.is_open())
    {
        while (getline(inputfile, line))
        {
            string value = getCode(line);
            code << "#include <iostream>\n\n" << "using namespace std;\n" << "int main()\n" << "{\n" <<
                "cout << \"" << value << "\" << endl;\n" <<  "return 0;\n" << "}\n";

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