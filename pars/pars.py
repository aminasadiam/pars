import sys
from helpers import error
from symboltable import SymbolTable

def run():
    filename = ""

    if(len(sys.argv) >= 2):
        filename = sys.argv[1]

        if "." not in filename or filename.split(".")[-1] != "pars":
            error("Incorrect file extension!", line_number)

    else:
        error("Please provide .pars file path", -1)

    

    c_filename = "".join(filename.split(".")[:-1]) + ".c"

    table = SymbolTable()

    