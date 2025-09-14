#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char *buff = NULL;
  size_t size = 0;
  char *saveptr;

  // get line from user
  printf("Please enter some text: ");
  ssize_t num_char = getline(&buff, &size, stdin);

  // getline failure check
  if (num_char == -1) {
    perror("getline failed");
    free(buff);

    // me personally I would return 1 for failure
    exit(EXIT_FAILURE);
  }

  // tokenize using spaces as delimiters
  char *ret = strtok_r(buff, " ", &saveptr);
  while (ret != NULL) {
    printf("%s \n", ret);

    // pass NULL to tokenize same string
    ret = strtok_r(NULL, " ", &saveptr);
  }

  // clear mem and return success
  free(buff);
  return 0;
}
