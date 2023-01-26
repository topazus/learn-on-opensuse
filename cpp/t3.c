#include <rpm/rpmdb.h>
#include <rpm/rpmlib.h>
#include <rpm/rpmlog.h>
#include <rpm/rpmtd.h>
#include <rpm/rpmts.h>

void t2() {
  // use rpm c library to query rpm database
  rpmdb db;
  rpmts ts;
  rpmReadConfigFiles(NULL, NULL);
  ts = rpmtsCreate();
  rpmtsInitIterator(ts, RPMDBI_PACKAGES, NULL, 0);
  db = rpmtsGetRdb(ts);
  rpmdbMatchIterator mi = rpmdbInitIterator(db, RPMDBI_LABEL, NULL, 0);
  int count = rpmdbGetIteratorCount(mi);
  printf("count: %d\n", count);
}

int main() { t2(); }
