import std/[strutils, osproc]

proc get_rpm_pkgs*(): string =
  let count = osproc.execCmdEx("rpm -qa").output
  # result = $(count.split("\n").len - 1)
  result = $(count.splitLines().len - 1)

proc get_rpm_pkgs()=
  let count = osproc.execCmdEx("rpm -qa").output
  result = $(count.split("\n").len - 1)

echo get_rpm_pkgs()
