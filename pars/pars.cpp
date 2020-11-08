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
    for(int count{ 1 }; count < argc; ++count)
    {
        if (count >= 2)
        {
            error("Please enter only the file with the .pars extension", -1);
        }
        filename = argv[count];
    }

    cout << filename << endl;

    return 0;
}