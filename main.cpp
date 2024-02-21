#include <iostream>
#include <cstring>

<<<<<<< HEAD
using namespace std;

char all_hex(char*);
int main(int argc, char* argv[]) {
  int valid_colors = 0;
  if (argc < 2){
    cout << "ERR_MISSING: One or more RGB values should be provided as arguments, separated by spaces" << endl;
    return 0;
  }
  for(int i=1; i < argc; i++) {
    int length = strlen(argv[i]);
    char returnval = all_hex(argv[i]);
    if( (length == 3 || length == 6) && returnval =='0') {
      cout << "#" << argv[i] << endl;
    } else if (length != 3 && length != 6) {
      cout << length << " ERR_LENGTH: RGB values must be either 3 or 6 characters long" << endl;
    } else if(returnval != '0'){
      cout << returnval << " ERR_VALUE: RGB values must be in 0-F range\n";
    }
    }  
  }
  return 0;
}

char all_hex(char* word) {
  for(int i=0; i<strlen(word); i++) {
    if((word[i] >= '0' && word[i] <= '9') || (word[i] >= 'a' && word[i] <= 'f')
      || (word[i] >= 'A' && word[i] <='F')) {
      continue;
    }
    else {
      return word[i];
    }
  }

  //no non-hex characters found
  return '0';
}

