
undefined4 FUN_001dbdd0(int param_1)

{
  undefined4 uVar1;
  
  if ((param_1 == 1) && (DAT_0025b78c != 0)) {
    uVar1 = *(undefined4 *)(DAT_0025b78c + 0x508);
  }
  else {
    DAT_0025b790 = 100;
    uVar1 = 0xffffffff;
  }
  return uVar1;
}

