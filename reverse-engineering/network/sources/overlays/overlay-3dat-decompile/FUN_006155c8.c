FUNCTION FUN_006155c8 @ 0x006155c8  size=164
CALLERS (1): FUN_00615670@0x00615670
CALLEES (0): 
----------------------------------------------------------------

undefined4 FUN_006155c8(void)

{
  int iVar1;
  undefined4 uVar2;
  long lVar3;
  
  if (DAT_00654204 == 0) {
    while( true ) {
      lVar3 = func_0x00115a98(0x70d200,0xffffffff80001101,1);
      uVar2 = 0xffffffff;
      if (lVar3 < 0) break;
      do {
        lVar3 = func_0x00115e60(0x70d200);
      } while (lVar3 != 0);
      if (iRam0070d224 != 0) {
        DAT_00654204 = 1;
        return 0;
      }
      iVar1 = 0x10000;
      do {
        iVar1 = iVar1 + -1;
      } while (iVar1 != -1);
    }
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



================================================================