#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <cstring>

#include "global_helpers.cpp"

using namespace std;


int main(){
    run();
}

int run(char** argv)
{
    string filename = "";

    if(sizeof(argv) >= 2)
    {
        filename = argv[1];
        char Cfilename[filename.size() + 1];
        strcpy(Cfilename, filename.c_str());

        char *token = strtok(Cfilename, ".pars");
        if(token == NULL)
        {
            error("Incorrect file extension", 1);
        }
    }
    else
    {
        error("Please provide simc file path", -1);
    }
    return 0;
}