import rpm
ts = rpm.TransactionSet()
rpmdb=ts.dbMatch()
print(len(list(rpmdb)))
