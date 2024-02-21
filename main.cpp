#include <iostream>
#include <cstring>

bool all_hex(char*);

int main(int argc, char* argv[]) {

  if (argc < 2){
    cout << "ERR_MISSING: One or more RGB values should be provided as arguments, separated by spaces" << endl;
    return 0;
  }
  int valid_colors = 0;

  for(int i=1; i < argc; i++) {
    int length = strlen(argv[i]);
    if (length != 6 && length != 3) {
      cout << argv[i] << " ERR_LENGTH: RGB values must be either 3 or 6 characters long" << endl;
    }
    else if( (length == 3 || length == 6) && all_hex(argv[i]) ) {
      cout << "#" << argv[i] << endl;
    }  
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
      cout << word << " ERR_VALUE: RGB values must be in 0-F range" << endl;
      return false;
    }
  }

  //no non-hex characters found
  return true;
}