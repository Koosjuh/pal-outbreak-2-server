FUNCTION FUN_005ca560 @ 0x005ca560  size=96
CALLERS (0): 
CALLEES (2): FUN_005d8340@0x005d8340, FUN_005d5ba0@0x005d5ba0
----------------------------------------------------------------

void FUN_005ca560(void)

{
  long lVar1;
  
  lVar1 = FUN_005d8340(iRam00701068 + 0x4f97c);
  if (lVar1 != 0) {
    uRam00700fe8 = 0;
    FUN_005d5ba0(0);
    *(undefined1 *)(iRam00701078 + 2) = 1;
    *(undefined1 *)(iRam00701070 + 2) = 5;
  }
  return;
}



================================================================