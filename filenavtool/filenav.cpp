// i am ashamed of this code curse them that did this to me, curse those
// professors who took away my life, curse this nation, curse this black seed
// squandered potentional squandered achivements curse them all their blood be
// upon them
#include <cstring>
#include <filesystem>
#include <fstream>
#include <iostream>

// THIS IS UTTER SHIT
int main(int argc, char *argv[]) {
  if (argc != 1) {

    for (int i = 1; i < argc; i++) {
      if (strcmp("--help", argv[1]) == 0) {
        std::cout << "Options: \n";
        std::cout << "--list - list all files and folders \n";
        std::cout << "--create-directory <folder name> - make a folder \n";
        std::cout << "--remove-directory - delete a folder \n";
        std::cout << "--create-file - make a file \n";
        std::cout << "--remove-file - delete a file \n";
      } else if (strcmp("--list", argv[1]) == 0) {
        for (const auto &entry : std::filesystem::directory_iterator("."))
          std::cout << entry.path() << std::endl;
      } else if (strcmp("--create-directory", argv[1]) == 0) {
        std::filesystem::create_directory(argv[2]);
      } else if (strcmp("--remove-directory", argv[1]) == 0) {
        std::filesystem::remove(argv[2]);
      } else if (strcmp("--create-file", argv[1]) == 0) {
        std::ofstream f2(argv[2]);
      } else if (strcmp("--remove-file", argv[1]) == 0) {
        std::filesystem::remove(argv[2]);
      } else {
        std::cout << "missing opperand, please run --help for more information";
      }
    }
  } else {
    std::cout << "missing opperand, please run --help for more information";
  }
  return 0;
}
