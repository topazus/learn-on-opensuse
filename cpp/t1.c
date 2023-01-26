#include <fcntl.h>
#include <rpm/rpmdb.h>
#include <rpm/rpmlib.h>
#include <rpm/rpmlog.h>
#include <rpm/rpmts.h>
#include <stdio.h>
#include <unistd.h>

enum modes {
  MODE_INITDB = (1 << 0),
  MODE_REBUILDDB = (1 << 1),
  MODE_VERIFYDB = (1 << 2),
  MODE_EXPORTDB = (1 << 3),
  MODE_IMPORTDB = (1 << 4),
  MODE_SALVAGEDB = (1 << 5),
};
static int mode = 0;

void test1() {
  Header h;
  rpmdb db;
  char time_buffer[512];
  rpmdbMatchIterator mi;
  rpmts ts = NULL;
  rpmtd td, tn;
  ts = rpmtsCreate();
  td = rpmtdNew();
  tn = rpmtdNew();
  int rc1, rc2;
  rpmReadConfigFiles(NULL, NULL);

  // check open rpm database
  //    if (rpmdbOpenAll(db) != 0) {
  //        std::cerr << "Failed to open rpm database" << std::endl;
  //        return 1;
  //    }

  mi = rpmdbInitIterator(db, RPMDBI_PACKAGES, NULL, 0);
  int count = 0;
  while ((h = rpmdbNextIterator(mi)) != NULL) {
    h = headerLink(h);
    rc1 = headerGet(h, RPMTAG_NAME, td, HEADERGET_EXT);
    rc2 = headerGet(h, RPMTAG_SIZE, tn, HEADERGET_EXT);
    fprintf(stdout, " %s-%lu\n", rpmtdGetString(td), rpmtdGetNumber(tn));
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

void test2() {
  const char *DNEVR;
  rpmds ds = NULL;
  int rc;
  rpmReadConfigFiles(NULL, NULL);
  rc = rpmdsRpmlib(&ds, NULL);
  ds = rpmdsInit(ds);
  fprintf(stdout, "feature: \n");
  while (rpmdsNext(ds) >= 0) {
    if ((DNEVR = rpmdsDNEVR(ds)) != NULL) {
      fprintf(stdout, " %s\n", DNEVR + 2);
    }
  }
}

void test3() {
  printf("%s\n", RPMVERSION);
  int status;
  status = rpmReadConfigFiles((const char *)NULL, (const char *)NULL);
  if (status) {
    printf("error: reading RC files\n");
  }

  rpmShowRC(stdout);
}

void test4() {
  Header h;
  rpmdb db;
  rpmdbMatchIterator mi;
  rpmts ts = NULL;
  ts = rpmtsCreate();
  const char *n, *v, *r, *g, *a;
  // read rpm db
  db = rpmtsGetRdb(ts);
  rpmReadConfigFiles(NULL, NULL);
  mi = rpmdbInitIterator(db, RPMDBI_PACKAGES, NULL, 0);
  while ((h = rpmdbNextIterator(mi)) != NULL) {
    printf("ffff");
    h = headerLink(h);
    n = headerGetString(h, RPMTAG_NAME);
    v = headerGetString(h, RPMTAG_VERSION);
    r = headerGetString(h, RPMTAG_RELEASE);
    g = headerGetString(h, RPMTAG_GROUP);
    a = headerGetString(h, RPMTAG_ARCH);
    //        printf("%s %s %s %s %s",n,v,r,g,a);
    fprintf(stdout, "%s %s %s %s %s", n, v, r, g, a);
    headerFree(h);
  }
  rpmdbFreeIterator(mi);
  rpmtsFree(ts);
}

void test5() {
  Header h;
  rpmdb db;
  rpmdbMatchIterator mi;
  rpmts ts = NULL;
  // create a transaction set and open the rpm database
  ts = rpmtsCreate();
  db = rpmtsGetRdb(ts);
  rpmReadConfigFiles(NULL, NULL);
  mi = rpmdbInitIterator(db, RPMDBI_LABEL, NULL, 0);
  if (mi == NULL) {
    printf("mi is null\n");
  }
  int count = rpmdbGetIteratorCount(mi);
  printf("%d\n", count);
  rpmdbFreeIterator(mi);
  rpmtsFree(ts);
}

int main() { test5(); }
