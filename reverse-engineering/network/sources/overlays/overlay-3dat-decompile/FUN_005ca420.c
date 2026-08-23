FUNCTION FUN_005ca420 @ 0x005ca420  size=92
CALLERS (0): 
CALLEES (3): FUN_005cce30@0x005cce30, FUN_005d0a40@0x005d0a40, FUN_005ca6a0@0x005ca6a0
----------------------------------------------------------------

void FUN_005ca420(void)

{
  FUN_005ca6a0();
  if (*(char *)(iRam00701070 + 0x2e) == '\n') {
    FUN_005d0a40();
  }
  else if (*(char *)(iRam00701070 + 0x2e) == '\b') {
    FUN_005cce30();
  }
  return;
}



================================================================