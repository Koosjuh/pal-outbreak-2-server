FUNCTION FUN_005ca640 @ 0x005ca640  size=92
CALLERS (0): 
CALLEES (2): FUN_005d8340@0x005d8340, FUN_005d5b60@0x005d5b60
----------------------------------------------------------------

void FUN_005ca640(void)

{
  long lVar1;
  
  lVar1 = FUN_005d8340(iRam00701068 + 0x4f97c);
  if (lVar1 != 0) {
    uRam00700fe8 = 0;
    FUN_005d5b60(0);
    *(undefined1 *)(iRam00701070 + 1) = 2;
    *(undefined1 *)(iRam00701070 + 2) = 0;
  }
  return;
}



================================================================