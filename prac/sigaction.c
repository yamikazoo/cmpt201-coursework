#define _POSIX_C_SOURCE 200809

#include <signal.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

static char *message = "CTRL-C pressed\n";
void handle_sigint(int signal) {
  write(STDOUT_FILENO, message, strlen(message));
}

int main() {
  // create da struct
  struct sigaction sa;
  sa.sa_handler = handle_sigint;
  sa.sa_flags = 0;
  sigemptyset(&sa.sa_mask);

  // register signal handler
  int ret = sigaction(SIGINT, &sa, NULL);
  if (ret == -1) {
    perror("Sigaction() failed");
    exit(EXIT_FAILURE);
  }

  while (true) {
    sleep(1);
  }
}
