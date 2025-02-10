#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
  while (true) {
    char command[255];
    write(1, "SHELL> ", 7);
    /* the first argument is the file descriptor, 1 for stdout; the second
     * argument is the buffer in this case the shell prompt; the final argument
     * is the count of bytes; see man the man pages for more information */
    int count = read(0, command, 255);
    command[count - 1] = 0; // this removes the newline character after entering a command
    pid_t fork_result = fork();
    if (fork_result == 0) {
      execve(command, 0, 0);
      break;
    } else {
      siginfo_t info;
      waitid(P_ALL, 0, &info, WEXITED); 
    }
  }
  _exit(0);
}
