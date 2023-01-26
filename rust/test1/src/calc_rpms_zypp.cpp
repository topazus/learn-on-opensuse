#include <zypp/RepoManager.h>
#include <zypp/ZYppFactory.h>

auto get_rpm_packages_by_libzypp() {
  auto zypp = zypp::getZYpp();
  // auto zypp = zypp::ZYppFactory::instance().getZYpp();
  zypp->initializeTarget("/");
  zypp->target()->load();
  auto count = zypp->pool().size();
  return int(count);
}
