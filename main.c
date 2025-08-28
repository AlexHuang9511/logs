#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include "log.h"

int main(int argc, char *argv[]) {

  l_init();

  l_log(FILE_FILENO, INFO, "whats up");
  l_log(STDERR_FILENO, ERR, "error");
  l_log(STDOUT_FILENO, INFO, "yo");

  l_flog(FILE_FILENO, INFO, "hi %i", 1);
  l_flog(FILE_FILENO, INFO, "hi %i", 2);
  l_flog(FILE_FILENO, INFO, "hi %i", 3);
  l_flog(FILE_FILENO, INFO, "hi %i", 4);

  char *hi = "yo";
  l_flog(FILE_FILENO, INFO, "hi %s", "yo hi");
  l_flog(STDOUT_FILENO, ERR, "nah %s bruh", hi);
  l_flog(STDERR_FILENO, INFO, "yo, %s what's up", hi);

  printf("%i\n", fileno(stdout));
  printf("%i\n", fileno(stderr));

  printf("\n");

  printf("%i\n", STDOUT_FILENO);
  printf("%i\n", STDERR_FILENO);

  l_close();
  return 0;

}

