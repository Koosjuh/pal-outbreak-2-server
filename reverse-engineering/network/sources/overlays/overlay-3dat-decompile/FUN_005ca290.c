FUNCTION FUN_005ca290 @ 0x005ca290  size=140
CALLERS (0): 
CALLEES (4): FUN_005cce30@0x005cce30, FUN_005d09d0@0x005d09d0, FUN_005d0960@0x005d0960, FUN_005ca6a0@0x005ca6a0
----------------------------------------------------------------

void FUN_005ca290(void)

{
  FUN_005ca6a0();
  if (*(char *)(iRam00701070 + 0x2e) == '\n') {
    if (*(char *)(iRam00701070 + 0x2c) == '\x02') {
      FUN_005d0960();
    }
    else if (*(char *)(iRam00701070 + 0x2c) == '\x01') {
      FUN_005d09d0();
    }
  }
  else if (*(char *)(iRam00701070 + 0x2e) == '\b') {
    FUN_005cce30();
  }
  return;
}



================================================================