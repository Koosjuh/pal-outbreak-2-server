
undefined4 FUN_001e0428(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  if ((param_1 == 1) && (DAT_0025b78c != 0)) {
    if (*(int *)(DAT_0025b78c + 0x50c) == 0) {
      FUN_001d4d24(1,0x2c,param_2);
      uVar1 = 0;
    }
    else {
      DAT_0025b790 = 0x66;
      uVar1 = 0xffffffff;
    }
  }
  else {
    DAT_0025b790 = 100;
    uVar1 = 0xffffffff;
  }
  return uVar1;
}

