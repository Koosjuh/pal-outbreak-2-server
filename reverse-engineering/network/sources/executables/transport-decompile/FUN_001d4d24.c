
undefined4 FUN_001d4d24(int param_1,int param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  if ((param_1 == 1) && (DAT_0025b78c != 0)) {
    uVar1 = *(undefined4 *)(param_2 * 4 + DAT_0025b78c + 0x548);
    *(undefined4 *)(param_2 * 4 + DAT_0025b78c + 0x548) = param_3;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}

