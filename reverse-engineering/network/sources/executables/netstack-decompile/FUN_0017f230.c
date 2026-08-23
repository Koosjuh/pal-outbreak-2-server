
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0017f230(undefined4 param_1)

{
  undefined4 uVar1;
  long lVar2;
  
  if (ram0x0022f590 == 0) {
    uVar1 = 0;
  }
  else {
    uRam0027b000 = param_1;
    lVar2 = FUN_00115c68(0x27af88,0xffffffff80001302,0,0x27b000,0x280,0x27b000,0x280,0);
    uVar1 = uRam0027b004;
    if (lVar2 < 0) {
      FUN_0017fd00(0x258a98);
      uVar1 = 0;
    }
  }
  return uVar1;
}

