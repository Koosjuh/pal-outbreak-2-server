FUNCTION FUN_00606520 @ 0x00606520  size=228
CALLERS (1): FUN_006063c0@0x006063c0
CALLEES (2): FUN_005c4690@0x005c4690, FUN_00605d30@0x00605d30
----------------------------------------------------------------

void FUN_00606520(void)

{
  long lVar1;
  undefined4 uStack_8;
  undefined2 uStack_2;
  
  sRam0070cdca = sRam0070cdca + -1;
  if (sRam0070cdca < 1) {
    sRam0070cdca = 0;
    sRam0070cdcc = sRam0070cdcc + 1;
    if (sRam0070cdcc < 4) {
      FUN_005c4690(&uStack_8,&uStack_2);
      lVar1 = FUN_00605d30(uStack_8,uStack_2,0);
      uRam0035a6f4 = (undefined4)lVar1;
      if (lVar1 < 0) {
        sRam0070cdca = 300;
      }
      else {
        sRam0070cdca = 300;
        sRam0070cdc8 = sRam0070cdc8 + 1;
      }
    }
    else {
      sRam0070cdca = 0;
      sRam0070cdc8 = 99;
      uRam0035b723 = 5;
      sRam0070cdcc = 0;
    }
  }
  return;
}



================================================================