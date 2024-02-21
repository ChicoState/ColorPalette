#include <iostream>
#include <cstring>

using namespace std;

bool all_hex(char* color);

int main(int argc, char* argv[]) {
    cout << "Valid colors provided:" << endl;
    for(int i = 1; i < argc; ++i) {
        if(all_hex(argv[i])) { // Check if the provided color is valid and start from 1 because 0 is the name of the program
            cout << "#" << argv[i] << endl;
        }
    }
    return 0;
}

// Function to check if the provided string is a valid hexadecimal color code
bool all_hex(char* color) {
    int length = strlen(color);
    // Check if the color code's length is either 3 or 6
    if(length != 3 && length != 6) {
        cout << "Invalid color code: " << color << endl;
        return false; // Return false if the length is not 3 or 6
    }
    // Check each character to confirm it's a valid hexadecimal digit
    for(int i = 0; i < length; ++i) {
        if(!((color[i] >= '0' && color[i] <= '9') || (color[i] >= 'a' && color[i] <= 'f') || (color[i] >= 'A' && color[i] <= 'F'))) {
            cout << "Invalid color code: " << color << endl;
            cout << "Color code must be a valid hexadecimal number" << endl;
            return false;  // Return false if a non-hexadecimal digit is found
        }
    }
    return true;  // Return true if all characters are valid hexadecimal digits
}
