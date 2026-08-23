FUNCTION FUN_005ca5c0 @ 0x005ca5c0  size=116
CALLERS (0): 
CALLEES (2): FUN_005cce30@0x005cce30, FUN_005d5ba0@0x005d5ba0
----------------------------------------------------------------

void FUN_005ca5c0(void)

{
  if (*(char *)(iRam00701070 + 0x2e) == '\n') {
    FUN_005d5ba0(0);
    *(undefined1 *)(iRam00701078 + 2) = 1;
    *(undefined1 *)(iRam00701070 + 2) = 5;
  }
  else if (*(char *)(iRam00701070 + 0x2e) == '\b') {
    FUN_005cce30();
  }
  return;
}



================================================================