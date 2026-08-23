
undefined4 FUN_001eef00(int *param_1)

{
  short sVar1;
  undefined4 uVar2;
  
  sVar1 = FUN_001f0f10();
  if (sVar1 < 0) {
    uVar2 = 0xffffffff;
  }
  else {
    *param_1 = (int)sVar1;
    uVar2 = 0;
  }
  return uVar2;
}

