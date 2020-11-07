import sys

def error(message, line_number):
    print("\033[91m[Line %d] Error: %s" % (line_number, message))
    sys.exit()

def is_digit(char):
    return char in ["0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "."]

def is_alpha(char):
    return char.isalpha() or char == "_"

def is_alnum(char):
    return (
        char.isalpha()
        or char == "_"
        or char in ["0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "."]
    )