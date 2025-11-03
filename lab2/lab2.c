#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
  char *command = NULL;
  size_t size = 0;

  printf("Enter programs to run. \n");
  if (getline(&command, &size, stdin) != -1) {
    printf("yea\n");
  }
  // tokenize to remove newline
  // get the last part of the command

  execl(command, actualcommand, (char *)NULL);
  free(command);
}
