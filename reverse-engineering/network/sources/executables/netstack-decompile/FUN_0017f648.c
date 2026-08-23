
undefined4 FUN_0017f648(int param_1)

{
  undefined4 uVar1;
  long lVar2;
  
  uRam0027b008 = 2;
  uRam0027b010 = *(undefined4 *)(param_1 + 8);
  uRam0027b014 = *(undefined4 *)(param_1 + 0xc);
  lVar2 = FUN_00115c68(0x27af88,0xffffffff8000131d,0,0x27b000,0x280,0x27b000,0x280,0);
  uVar1 = uRam0027b004;
  if (lVar2 < 0) {
    FUN_0017fd00(0x258b18);
    uVar1 = 0xffffffff;
  }
  return uVar1;
}
