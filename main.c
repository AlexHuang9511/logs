#include <stdio.h>
#include "log.h"

int main(int argc, char *argv[]) {

  l_init();

  l_log(INFO, "whats up");
  l_log(ERR, "error");
  l_log(INFO, "yo");

  l_flog(INFO, "hi %i", 1);
  l_flog(INFO, "hi %i", 2);
  l_flog(INFO, "hi %i", 3);
  l_flog(INFO, "hi %i", 4);

  char *hi = "yo";
  l_flog(INFO, "hi %s", "yo hi");
  l_flog(ERR, "nah %s bruh", hi);
  l_flog(INFO, "yuh %s cuh", hi);

  printf("");

  l_close();
  return 0;

}

