#include <rpm/rpmdb.h>
#include <rpm/rpmlib.h>
#include <rpm/rpmlog.h>
#include <rpm/rpmtd.h>
#include <rpm/rpmts.h>

int get_rpm_packages_count_by_librpm() {
  // use rpm c library to query rpm database
  rpmReadConfigFiles(NULL, NULL);
  rpmts ts = rpmtsCreate();
  rpmtsInitIterator(ts, RPMDBI_PACKAGES, NULL, 0);
  rpmdb db = rpmtsGetRdb(ts);
  rpmdbMatchIterator mi = rpmdbInitIterator(db, RPMDBI_LABEL, NULL, 0);
  int count = rpmdbGetIteratorCount(mi);
  return count;
}
// const char **rpm_packages_name() {
//   rpmReadConfigFiles(NULL, NULL);
//   rpmts ts = rpmtsCreate();
//   rpmtsInitIterator(ts, RPMDBI_PACKAGES, NULL, 0);
//   rpmdb db = rpmtsGetRdb(ts);
//   rpmdbMatchIterator mi = rpmdbInitIterator(db, RPMDBI_LABEL, NULL, 0);
//   Header h;
//   const char **names;
//   int i = 0;
//   while ((h = rpmdbNextIterator(mi)) != NULL) {
//     const char *name;
//     rpmtd td = rpmtdNew();
//     if (headerGet(h, RPMTAG_NAME, td, HEADERGET_MINMEM)) {
//       name = rpmtdGetString(td);
//       names[i] = name;
//       i++;
//     }
//   }
//   return names;
// }
