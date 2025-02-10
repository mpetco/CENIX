#include <cstdlib>
#include <ctime>
#include <iostream>

void drawBoard(char *spaces);
void playerMove(char *spaces, char player);
void computerMove(char *spaces, char computer);
bool checkWinner(char *spaces, char player,
                 char computer); // these 2 return boolean values
bool checkTie(char *spaces);

int main() {
  system("clear");
  char playagain;
  do {
  char spaces[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
  char player;
  char computer;
  bool running = true;

    std::cout << "Pick the character you wanna be: X or O" << std::endl;
    std::cin >> player;
    if (player == 'X' || player == 'x')
      computer = 'O';
    else
      computer = 'X';

    drawBoard(spaces);

    while (running) {
      playerMove(spaces, player);
      drawBoard(spaces);

      if (checkWinner(spaces, player, computer)) {
        running = false;
        break;
      } else if (checkTie(spaces)) {
        running = false;
        break;
      }

      computerMove(spaces, computer);
      drawBoard(spaces);

      if (checkWinner(spaces, player, computer)) {
        running = false;
        break;
      } else if (checkTie(spaces)) {
        running = false;
        break;
      }
    }

    std::cout << "thank you for playing\n";
    std::cout << "play again? (y or n)" << std::endl;
    std::cin >> playagain;
    system("clear");
  } while (playagain == 'y');

  return 0;
}

void drawBoard(char *spaces) {
  system("clear");
  std::cout << "\n";
  std::cout << "     |     |     " << std::endl;
  std::cout << "  " << spaces[0] << "  |  " << spaces[1] << "  |  " << spaces[2]
            << "  " << std::endl;
  std::cout << "_____|_____|_____" << std::endl;
  std::cout << "     |     |     " << std::endl;
  std::cout << "  " << spaces[3] << "  |  " << spaces[4] << "  |  " << spaces[5]
            << "  " << std::endl;
  std::cout << "_____|_____|_____" << std::endl;
  std::cout << "     |     |     " << std::endl;
  std::cout << "  " << spaces[6] << "  |  " << spaces[7] << "  |  " << spaces[8]
            << "  " << std::endl;
  std::cout << "     |     |     " << std::endl;
  std::cout << "\n";
}

void playerMove(char *spaces, char player) {
  int number;
  do {
    std::cout << "Enter a number between 1-9 for the spaces: " << std::endl;
    std::cin >> number;
    number--;
    if (spaces[number] == ' ') {
      spaces[number] = player;
      break;
    }
  } while (!number > 0 || !number < 8);
}

void computerMove(char *spaces, char computer) {
  int numbers;
  srand(time(0));
  while (true) {
    numbers = rand() % 9;
    if (spaces[numbers] == ' ') {
      spaces[numbers] = computer;
      break;
    }
  }
};

bool checkWinner(char *spaces, char player, char computer) {
  // should use switch here

  if ((spaces[0] != ' ') && (spaces[0] == spaces[1]) &&
      (spaces[1] == spaces[2])) {
    spaces[0] == player ? std::cout << "you win\n" : std::cout << "you lose\n";
  } else if ((spaces[3] != ' ') && (spaces[3] == spaces[4]) &&
             (spaces[4] == spaces[5])) {
    spaces[3] == player ? std::cout << "you win\n" : std::cout << "you lose\n";
  } else if ((spaces[6] != ' ') && (spaces[6] == spaces[7]) &&
             (spaces[7] == spaces[8])) {
    spaces[6] == player ? std::cout << "you win\n" : std::cout << "you lose\n";
  }

  else if ((spaces[0] != ' ') && (spaces[0] == spaces[3]) &&
           (spaces[3] == spaces[6])) {
    spaces[0] == player ? std::cout << "you win\n" : std::cout << "you lose\n";
  } else if ((spaces[1] != ' ') && (spaces[1] == spaces[4]) &&
             (spaces[4] == spaces[7])) {
    spaces[1] == player ? std::cout << "you win\n" : std::cout << "you lose\n";
  } else if ((spaces[2] != ' ') && (spaces[2] == spaces[5]) &&
             (spaces[5] == spaces[8])) {
    spaces[2] == player ? std::cout << "you win\n" : std::cout << "you lose\n";
  }

  else if ((spaces[0] != ' ') && (spaces[0] == spaces[4]) &&
           (spaces[4] == spaces[8])) {
    spaces[0] == player ? std::cout << "you win\n" : std::cout << "you lose\n";
  } else if ((spaces[2] != ' ') && (spaces[2] == spaces[4]) &&
             (spaces[4] == spaces[6])) {
    spaces[2] == player ? std::cout << "you win\n" : std::cout << "you lose\n";
  }

  else {
    return false;
  }
  return true;
}

bool checkTie(char *spaces) {
  for (int i = 0; i < 9; i++) {
    if (spaces[i] == ' ') {
      return false;
    }
  }
  std::cout << "it's a tie\n";
  return true;
}
