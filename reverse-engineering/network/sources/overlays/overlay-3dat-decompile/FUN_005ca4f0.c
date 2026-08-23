FUNCTION FUN_005ca4f0 @ 0x005ca4f0  size=104
CALLERS (0): 
CALLEES (3): FUN_005cce30@0x005cce30, FUN_005d5b60@0x005d5b60, FUN_005ca6a0@0x005ca6a0
----------------------------------------------------------------

void FUN_005ca4f0(void)

{
  FUN_005ca6a0();
  if (*(char *)(iRam00701070 + 0x2e) == '\n') {
    uRam00701e18 = 2;
    FUN_005d5b60(0);
  }
  else if (*(char *)(iRam00701070 + 0x2e) == '\b') {
    FUN_005cce30();
  }
  return;
}



================================================================