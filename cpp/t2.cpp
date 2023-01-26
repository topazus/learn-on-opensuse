
#include <iostream>
#include <rpm/header.h>
#include <rpm/rpmdb.h>
#include <rpm/rpmlib.h>
#include <rpm/rpmlog.h>
#include <rpm/rpmtd.h>
#include <rpm/rpmts.h>

// #include <zypp/ZYppFactory.h>
// #include <zypp/base/Counter.h>
void t1() {
  Header h;
  rpmdb db;
  char time_buffer[512];
  rpmts ts;
  rpmtd td, tn;
  ts = rpmtsCreate();
  td = rpmtdNew();
  tn = rpmtdNew();
  int rc1, rc2;
  rpmReadConfigFiles(nullptr, nullptr);

  // check open rpm database
  //    if (rpmdbOpenAll(db) != 0) {
  //        std::cerr << "Failed to open rpm database" << std::endl;
  //        return 1;
  //    }

  rpmdbMatchIterator mi = rpmdbInitIterator(db, RPMDBI_PACKAGES, nullptr, 0);
  int count = 0;
  while ((h = rpmdbNextIterator(mi)) != nullptr) {
    h = headerLink(h);
    rc1 = headerGet(h, RPMTAG_NAME, td, HEADERGET_EXT);
    rc2 = headerGet(h, RPMTAG_VERSION, tn, HEADERGET_EXT);
    fprintf(stdout, " %s-%s", rpmtdGetString(td), rpmtdGetString(tn));
    rpmtdReset(td);
    rpmtdReset(tn);
    count = count + 1;
  }
  printf("%d\n", count);
  rpmdbFreeIterator(mi);
  rpmtsFree(ts);
  //    auto a=rpmdbCountPackages(db, "rpm");
  //    std::cout << "count: " << a << std::endl;
}

int main() { t1(); }
