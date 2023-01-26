#include <fmt/core.h>
#include <iostream>
#include <time.h>

char *current_time() {
  time_t t;
  time(&t);
  return ctime(&t);
}
int main() {
  std::cout << current_time() << std::endl;
  return 0;
}
