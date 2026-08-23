
int FUN_001c3da0(int param_1,undefined1 param_2)

{
  int iVar1;
  undefined1 uStack_1;
  
  iVar1 = *(int *)(param_1 + 0x2c) + *(int *)(param_1 + 0x38);
  if (*(int *)(param_1 + 0x38) + 1U <= *(uint *)(param_1 + 0x20)) {
    uStack_1 = param_2;
    FUN_001069a8(iVar1,&uStack_1,1);
    *(int *)(param_1 + 0x38) = *(int *)(param_1 + 0x38) + 1;
  }
  return iVar1;
}

