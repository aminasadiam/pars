#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <cstring>
#include <fstream>


#include "global_helpers.cpp"

using namespace std;


int main(int argc, char *argv[])
{
    string filename = "";
    // todo: debug argv size of
    if (sizeof(argv[1]) >= 2)
    {
        filename = argv[1];
        char Cfilename[filename.size() + 1];
        strcpy(Cfilename, filename.c_str());

        char *token = strtok(Cfilename, ".pars");
        if (token == NULL)
        {       
            error("Incorrect file extension", 1);
        }
        
        cout << Cfilename << endl;
    }
    else
    {
        error("Please provide simc file path", -1);
    }

    return 0;
}