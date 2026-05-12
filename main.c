#include <stdio.h>
#include "log.h"

LOG_INIT

int main(int argc, char *argv[]) {

  l_init();

  l_log(L_INFO, "whats up");
  l_log(L_ERR, "error");
  l_log(L_INFO, "yo");

  l_logf(L_INFO, "hi %i", 1);
  l_logf(L_INFO, "hi %i", 2);
  l_logf(L_INFO, "hi %i", 3);
  l_logf(L_INFO, "hi %i", 4);

  char *hi = "yo";
  l_logf(L_INFO, "hi %s", "yo hi");
  l_logf(L_ERR, "nah %s bruh", hi);
  l_logf(L_INFO, "yo, %s what's up", hi);

  printf("%i\n", fileno(stdout));
  printf("%i\n", fileno(stderr));

  printf("\n");

  printf("%i\n", STDOUT_FILENO);
  printf("%i\n", STDERR_FILENO);

  l_flog(L_INFO, "hello");
  l_flogf(L_ERR, "hi %s", "there");

  l_olog(L_ERR, "this is a error in stdout");
  l_ologf(L_ERR, "this is a error in stdout #%d", 2);

  l_elog(L_INFO, "this is a msg in stderr");
  l_elogf(L_INFO, "this is a msg in stderr #%d", 3);

  l_close();
  return 0;

}

