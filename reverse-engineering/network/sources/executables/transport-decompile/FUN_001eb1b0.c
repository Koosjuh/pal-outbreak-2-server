
undefined4 FUN_001eb1b0(int *param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_001e1e4c(0x14);
  if (iVar1 == 0) {
    uVar2 = 0xffffe4a9;
  }
  else {
    uVar2 = FUN_001eb22c(iVar1,param_2);
    *param_1 = iVar1;
  }
  return uVar2;
}

