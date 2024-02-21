#include <iostream>
#include <cstring>

bool all_hex(char*);

int main(int argc, char* argv[]) {
  int valid_colors = 0;

  for(int i=1; i < argc; i++) {
    int length = strlen(argv[i]);
	bool correctLen = (length == 3 || length == 6);
	bool validHex = all_hex(argv[i]);
	if(!correctLen) {
		std::cout << argv[i] << " ERR_LENGTH: RGB values must be either 3 or 6 characters long\n";
	}
	if(!validHex) {
		std::cout << argv[i] << " ERR_VALUE: RGB values must be in 0-F range\n";
	}
    if(correctLen && validHex) {
		std::cout << "#" << argv[i] << std::endl;
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
      return false;
    }
  }

  //no non-hex characters found
  return true;
}
