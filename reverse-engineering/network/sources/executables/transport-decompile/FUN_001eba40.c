
undefined4 FUN_001eba40(int *param_1,undefined2 param_2,undefined2 param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_001e1e4c(param_2);
  if (iVar1 == 0) {
    uVar2 = 0xffffe4a9;
  }
  else {
    *(undefined2 *)(iVar1 + 8) = param_2;
    *(undefined2 *)(iVar1 + 10) = param_3;
    *(undefined2 *)(iVar1 + 0xe) = 0;
    *(undefined2 *)(iVar1 + 0xc) = 0;
    *param_1 = iVar1;
    uVar2 = 0;
  }
  return uVar2;
}

