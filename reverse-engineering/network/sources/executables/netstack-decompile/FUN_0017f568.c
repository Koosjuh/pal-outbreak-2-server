
undefined4 FUN_0017f568(undefined4 param_1)

{
  undefined4 uVar1;
  long lVar2;
  
  uRam0027b000 = param_1;
  lVar2 = FUN_00115c68(0x27af88,0xffffffff80001316,0,0x27b000,0x280,0x27b000,0x280,0);
  uVar1 = uRam0027b004;
  if (lVar2 < 0) {
    FUN_0017fd00(0x258af8);
    uVar1 = 0;
  }
  return uVar1;
}
