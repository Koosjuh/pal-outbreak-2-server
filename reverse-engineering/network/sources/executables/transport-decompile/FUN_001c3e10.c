
int FUN_001c3e10(int param_1,uint param_2)

{
  int iVar1;
  ushort uStack_2;
  
  uStack_2 = (ushort)((param_2 & 0xffff) << 8) | (ushort)((param_2 & 0xffff) >> 8);
  iVar1 = *(int *)(param_1 + 0x2c) + *(int *)(param_1 + 0x38);
  if (*(int *)(param_1 + 0x38) + 2U <= *(uint *)(param_1 + 0x20)) {
    FUN_001069a8(iVar1,&uStack_2,2);
    *(int *)(param_1 + 0x38) = *(int *)(param_1 + 0x38) + 2;
  }
  return iVar1;
}

