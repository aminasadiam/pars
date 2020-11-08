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

    for(int count{ 1 }; count < argc; ++count)
    {
        if (count >= 2)
        {
            error("Please enter only the file with the .pars extension", -1);
        }
        filename = argv[count];
        string delimiter = ".pars";
        string token = filename.substr(0, filename.find(delimiter));
        if(token == NULL)
        {
            error("Incorrect file extension", -1);
        }
    }

    cout << filename << endl;

    return 0;
}