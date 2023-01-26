
#include <fmt/core.h>
#include <iostream>

#include <zypp/ByteCount.h>
#include <zypp/Date.h>
#include <zypp/RepoManager.h>
#include <zypp/Repository.h>
#include <zypp/ResTraits.h>
#include <zypp/Resolvable.h>
#include <zypp/ZYppFactory.h>
#include <zypp/base/Counter.h>

auto get_rpm_packages_by_libzypp() {
  auto zypp = zypp::getZYpp();
  // auto zypp = zypp::ZYppFactory::instance().getZYpp();
  zypp->initializeTarget("/");
  zypp->target()->load();
  auto count = zypp->pool().size();
  return int(count);
}

// load all enabled repositories
void repos() {
  //    zypp::RepoManager repo_manager;
  auto repo_manager = zypp::RepoManager();
  auto repos = repo_manager.knownRepositories();
  for (const auto &repo : repos) {
    if (repo.enabled()) {
      std::cout << "* repo: " << repo.alias() << std::endl;
    } else {
      std::cout << "  repo: " << repo.alias() << std::endl;
    }
  }
}

void t2() {
  std::cout << zypp::ByteCount(zypp::ByteCount::MiB) << std::endl;
  std::cout << zypp::ByteCount(zypp::ByteCount::MB) << std::endl;
  std::cout << (int)zypp::ByteCount(zypp::ByteCount::MB) << std::endl;
  std::cout << (int)zypp::ByteCount(zypp::ByteCount::M) << std::endl;
  std::cout << zypp::Date::now().form("%Y.%m.%d") << std::endl;
}

void t3() {
  auto zypp = zypp::getZYpp();
  zypp->initializeTarget("/");
  zypp->target()->load();
  int count = 0;
  for (const auto &p : zypp->pool()) {
    if (p->isSystem()) {
      count++;
    }
  }
  std::cout << "count: " << count << std::endl;
}

void t4() {
  auto z = zypp::getZYpp();
  z->initializeTarget("/");
  z->target()->load();
  for (const auto &item : z->pool()) {
    if (item->isKind(zypp::ResKind::package)) {
      //            if (item.status().isInstalled()) {
      //                t = "i";
      //            } else {
      //                t = "*";
      //            }
      // fmt::print("{%s} {%s} {%s} {%s} {%s} {%s}\n", t, item->kind(),
      //            item->name(), item->edition(), item->arch(),
      //            item->repoInfo().alias());
      std::cout << " " << item->kind() << " " << item->name() << " "
                << item->edition() << " " << item->arch() << " "
                << item->repoInfo().alias() << " " << item->vendor() << " "
                << std::endl;
    }
  }
}

void t5() {
  auto z = zypp::getZYpp();
  z->initializeTarget("/");
  z->target()->load();

  for (const auto &item : z->pool()) {
    auto name = item->name();
  }
}

void t6() {
  auto z = zypp::getZYpp();
  z->initializeTarget("/");
  z->target()->load();
  // iterate over all items (packages, patches, patterns, products)
  for (const auto &item : z->pool()) {
    if (item.isKind(zypp::ResKind::package)) {
      std::cout << "1. package: " << item->name() << std::endl;
    } else if (item.isKind(zypp::ResKind::pattern)) {
      std::cout << "2. pattern: " << item->name() << std::endl;
    } else if (item.isKind(zypp::ResKind::patch)) {
      std::cout << "3. patch: " << item->name() << std::endl;
    } else if (item.isKind(zypp::ResKind::product)) {
      std::cout << "4. product: " << item.name() << std::endl;
    } else {
      std::cout << "5. other: " << item.name() << std::endl;
    }
  }
}

void t7() {
  auto z = zypp::getZYpp();
  z->initializeTarget("/");
  z->target()->load();
  auto c1 = 0;
  for (const auto &item : z->pool()) {
    if (item.status().isInstalled()) {
      c1++;
    }
  }
  auto c2 = 0;
  for (const auto &item : z->pool()) {
    c2++;
  }
  std::cout << "c1: " << c1 << std::endl;
  std::cout << "c2: " << c2 << std::endl;
  std::cout << z->pool().size() << std::endl;
}
void t8() {

  auto z = zypp::getZYpp();
  z->initializeTarget("/");
  z->target()->load();
  for (const auto &item : z->pool()) {
    if (item->isKind(zypp::ResKind::package)) {
      std::cout << item->name() << std::endl;
    }
  }
}
int main() {
  // use zypp library to get the number of installed rpm packages in openSUSE
  // Tumbleweed
  t8();
}
