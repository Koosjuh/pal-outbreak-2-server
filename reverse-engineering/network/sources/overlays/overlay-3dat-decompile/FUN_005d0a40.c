FUNCTION FUN_005d0a40 @ 0x005d0a40  size=164
CALLERS (3): FUN_005ca0a0@0x005ca0a0, FUN_005ce0e0@0x005ce0e0, FUN_005ca420@0x005ca420
CALLEES (5): FUN_005d73c0@0x005d73c0, FUN_005d7320@0x005d7320, FUN_005d5b10@0x005d5b10, FUN_005d5a40@0x005d5a40, FUN_005d5cc0@0x005d5cc0
----------------------------------------------------------------

void FUN_005d0a40(void)

{
  long lVar1;
  
  lVar1 = FUN_005d73c0();
  if (((lVar1 != 0) && (*(char *)(iRam00701070 + 0x38) == '\0')) &&
     (*(char *)(iRam00701070 + 0x3a) == '\0')) {
    lVar1 = FUN_005d7320();
    if (lVar1 == 0) {
      FUN_005d5b10();
    }
    else {
      *(undefined1 *)(iRam00701068 + 0x68e83) = 0;
      *(undefined1 *)(iRam00701078 + 1) = 0;
      *(undefined1 *)(iRam00701078 + 4) = 0;
      FUN_005d5cc0(lVar1);
      FUN_005d5a40();
    }
  }
  return;
}



================================================================