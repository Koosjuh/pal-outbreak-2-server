FUNCTION FUN_005d09d0 @ 0x005d09d0  size=100
CALLERS (3): FUN_005ce530@0x005ce530, FUN_005d3930@0x005d3930, FUN_005ca290@0x005ca290
CALLEES (5): FUN_005d5b10@0x005d5b10, FUN_005d71e0@0x005d71e0, FUN_005d5a40@0x005d5a40, FUN_005d72d0@0x005d72d0, FUN_005d5cc0@0x005d5cc0
----------------------------------------------------------------

void FUN_005d09d0(void)

{
  long lVar1;
  
  lVar1 = FUN_005d72d0();
  if (lVar1 == 0) {
    FUN_005d5b10();
  }
  else {
    lVar1 = FUN_005d71e0();
    if (lVar1 == 0) {
      FUN_005d5b10();
    }
    else {
      FUN_005d5cc0(lVar1);
      FUN_005d5a40();
    }
  }
  return;
}



================================================================