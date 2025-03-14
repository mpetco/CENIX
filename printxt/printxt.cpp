#include <iostream>
#include <string.h>

using std::string;

void iterateInput(int argc, char *argv[], int Flags);
void iterateInputEscapeSeq(int argc, char *argv[]);

int main(int argc, char *argv[]) {
  for (int i = 1; i < argc; i++) {
    if (strcmp(argv[i], "--help") == 0) {
      std::cout << "this is a help message yada yada";
      break;
    } else if (strcmp(argv[i], "--version") == 0) {
      std::cout << "this program is version 0.1";
      break;
    } else {
      for (int j = 0; j < argc - i; j++) {
        char flag = argv[i][j];
        char flagLetter = argv[i][j + 1]; // arrays start from 0
        if (flag == (int)'-' && flagLetter != (int)'-') {
          /* it doesnt work with strcmp moral of the story use appropriate
           * compersion for appropriate data types */
          switch (flagLetter) {
          case 'n':
            iterateInput(argc, argv, 2);
            break;
          case 'e':
            iterateInputEscapeSeq(argc, argv);
            break;
          case 'E':
            iterateInput(argc, argv, 2);
            std::cout << std::endl;
            break;
          default:
            std::cout << "it doesnt work";
            break;
          }
          break;
        } else {
          iterateInput(argc, argv, 1);
          std::cout << std::endl;
          break;
        }
      }
      break;
    }
  }
  
  return 0;
}

void iterateInput(int argc, char *argv[], int Flags) {
  for (int i = Flags; i < argc; i++) {
    /* the Flags integer means that it doesnt print the command name echocpp and
     * the flags aka options used*/
    if (i == argc - 1) {
      /* here we are comparing the iterated argv entry and the last entry in
       * argv -1 because the acutal last entry is blank if they are the same the
       * condition is true the reason we are doing this is so it does not output
       * an empty " " at the end of a string with the -n option*/
      std::cout << argv[i];
    }
    else {
      std::cout << argv[i] << " ";
    }
  }
}

// only this function is not done
void iterateInputEscapeSeq(int argc, char *argv[]) {
  for (int i = 1; i < argc; i++) {
    for (int j = 0; j < argc - i; j++) {
      //std::cout << argv[i][j] << std::endl;
      //std::cout << argv[i][j] << std::endl;
      if (strcmp(argv[i], "\\") == 0) {
	std::cout << argv[i][j] << "this is the cout";
        switch (argv[i][j]) {
        case '\\':
          break;
        case 'a':
          std::cout << "a option";
          break;
        case 'b':
          std::cout << "b option";
          break;
        case 'c':
          std::cout << "c option";
          break;
        case 'e':
          std::cout << "e option";
          break;
        case 'f':
          std::cout << "f option";
          break;
        case 'n':
          std::cout << "\n";
          break;
        case 'r':
          std::cout << "r option";
          break;
        case 't':
          std::cout << "t option";
          break;
        case 'v':
          std::cout << "v option";
          break;
        case '0':
          std::cout << "0 option";
          break;
        case 'x':
          std::cout << "x option";
          // use type conversion to turn numbers into chars for /x and /0
          break;
        default:
          std::cout << "smth wong";
          break;
        }
      } else {
        iterateInput(argc, argv, 2);
	std::cout << std::endl;
	break;
        //std::cout << "not good";
      }
    }
  }
}
