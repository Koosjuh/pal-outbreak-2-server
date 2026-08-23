FUNCTION FUN_005ca320 @ 0x005ca320  size=92
CALLERS (0): 
CALLEES (3): FUN_005d59f0@0x005d59f0, FUN_005cce30@0x005cce30, FUN_005ca6a0@0x005ca6a0
----------------------------------------------------------------

void FUN_005ca320(void)

{
  FUN_005ca6a0();
  if (*(char *)(iRam00701070 + 0x2e) == '\n') {
    FUN_005d59f0();
  }
  else if (*(char *)(iRam00701070 + 0x2e) == '\b') {
    FUN_005cce30();
  }
  return;
}



================================================================