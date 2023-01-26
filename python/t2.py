#! /usr/bin/python
import zypp
# ========================================================================================

def poolInstall( Z, capstr ):
  print ("Request: install %s") % capstr
  Z.resolver().addRequire( zypp.Capability( capstr ) )

def poolRemove( Z, capstr ):
  print ("Request: delete  %s") % capstr
  Z.resolver().addConflict( zypp.Capability( capstr ) )

def poolPrintTransaction( Z ):
  todo = Z.pool().getTransaction()
  for item in todo._toDelete:
    print ('-- %s | %s-%s | %s') % (item.repoInfo().alias(), item.name(), item.edition(), item.status() )
  for item in todo._toInstall:
    print ('++ %s | %s-%s | %s') % (item.repoInfo().alias(), item.name(), item.edition(), item.status() )

