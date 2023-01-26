#include <time.h>
char *current_time() {
  time_t t;
  time(&t);
  return ctime(&t);
}
