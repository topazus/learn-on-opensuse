import archey.distributions
print(archey.distributions.Distributions.get_local())

# get number of rpm packages from reading rpm database file by using the sqlite module
def get_rpm_packages_by_sqlite3():
    import sqlite3
    conn = sqlite3.connect('/var/lib/rpm/Packages.sqlite')
    c = conn.cursor()
    c.execute('SELECT COUNT(*) FROM packages')
    return c.fetchone()[0]
# get number of rpm packages by using the rpm module
def get_rpm_packages_by_rpm():
    import rpm
    ts = rpm.TransactionSet()
    rpmdb=ts.dbMatch()
    return len(list(rpmdb))
print(get_rpm_packages_by_rpm())
