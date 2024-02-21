#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

// Function to check if a character is a hexadecimal digit
bool is_hex_digit(char c) {
    return (c >= '0' && c <= '9') || (c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F');
}

// Function to check if all characters in a string are hexadecimal digits
bool all_hex(const char* word) {
    for(int i = 0; i < strlen(word); i++) {
        if(!is_hex_digit(word[i])) {
            return false;
        }
    }
    return true;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cout << "ERR_MISSING: One or more RGB values should be provided as arguments, separated by spaces" << endl;
        return 1; // Exit with an error code
    }

    for(int i = 1; i < argc; i++) {
        int length = strlen(argv[i]);
        if(length != 3 && length != 6) {
            cout << argv[i] << " ERR_LENGTH: RGB values must be either 3 or 6 characters long" << endl;
            continue; // Skip further checks and continue with the next iteration
        }
        
        if(!all_hex(argv[i])) {
            cout << argv[i] << " ERR_VALUE: RGB values must be in 0-F range" << endl;
            continue; // Skip further checks and continue with the next iteration
        }
        
        // If no errors, print the valid RGB value
        cout << "#" << argv[i] << endl;
    }
    return 0;
}
