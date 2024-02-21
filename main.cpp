#include <iostream>
#include <cstring>

using namespace std;

bool all_hex(char*);

int main(int argc, char* argv[]) {
  // Check if no values are provided
  if(argc < 2) {
    cout << "ERR_MISSING: One or more RGB values should be provided as arguments, separated by spaces" << endl;
    return 0; // Exit the program after displaying the message
  }

  int valid_colors = 0;

  for(int i=1; i < argc; i++) {
    int length = strlen(argv[i]);
    if( !(length == 3 || length == 6) ) {
      // Print error message for invalid length
      cout << argv[i] << " ERR_LENGTH: RGB values must be either 3 or 6 characters long" << endl;
      continue; // Move to the next argument
    }
    if(!all_hex(argv[i])) {
      // Print error message for invalid hexadecimal value
      cout << argv[i] << " ERR_VALUE: RGB values must be in 0-F range" << endl;
      continue; // Move to the next argument
    }

    // If the value passes both checks, print it
    cout << "#" << argv[i] << endl;
  }

  return 0;
}

bool all_hex(char* word) {
  for(int i=0; i<strlen(word); i++) {
    if((word[i] >= '0' && word[i] <= '9') || (word[i] >= 'a' && word[i] <= 'f')
      || (word[i] >= 'A' && word[i] <='F')) {
      continue;
    }
    else {
      return false;
    }
  }

  // No non-hex characters found
  return true;
}
