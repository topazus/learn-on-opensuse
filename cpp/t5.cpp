#include <iostream>
#include <zypp/ZYppFactory.h>
void t2() {
  auto z = zypp::getZYpp();
  z->initializeTarget("/");
  z->target()->load();
  auto count = z->pool().size();
  std::cout << "count: " << count << std::endl;
}
int main() { t2(); }
