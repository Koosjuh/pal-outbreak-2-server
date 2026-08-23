
int FUN_001c3ea0(int param_1,uint param_2)

{
  int iVar1;
  uint uStack_4;
  
  uStack_4 = param_2 << 0x18 | (param_2 & 0xff00) << 8 | param_2 >> 0x18 | param_2 >> 8 & 0xff00;
  iVar1 = *(int *)(param_1 + 0x2c) + *(int *)(param_1 + 0x38);
  if (*(int *)(param_1 + 0x38) + 4U <= *(uint *)(param_1 + 0x20)) {
    FUN_001069a8(iVar1,&uStack_4,4);
    *(int *)(param_1 + 0x38) = *(int *)(param_1 + 0x38) + 4;
  }
  return iVar1;
}

