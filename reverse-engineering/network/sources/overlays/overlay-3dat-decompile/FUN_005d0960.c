FUNCTION FUN_005d0960 @ 0x005d0960  size=108
CALLERS (1): FUN_005ca290@0x005ca290
CALLEES (5): FUN_005d5b10@0x005d5b10, FUN_005d5a40@0x005d5a40, FUN_005d71a0@0x005d71a0, FUN_005d70b0@0x005d70b0, FUN_005d5cc0@0x005d5cc0
----------------------------------------------------------------

void FUN_005d0960(void)

{
  long lVar1;
  
  lVar1 = FUN_005d71a0();
  if (lVar1 == 0) {
    FUN_005d5b10();
  }
  else {
    lVar1 = FUN_005d70b0();
    if (lVar1 == 0) {
      FUN_005d5b10();
    }
    else {
      *(undefined1 *)(iRam00701070 + 0x33) = 0;
      FUN_005d5cc0(lVar1);
      FUN_005d5a40();
    }
  }
  return;
}



================================================================