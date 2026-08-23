
undefined4 FUN_001f26e0(int param_1,long param_2,long param_3)

{
  int iVar1;
  
  if (param_2 < 0) {
    return 0xfffffff5;
  }
  if (param_3 < 0) {
    return 0xfffffff4;
  }
  iVar1 = param_1 * 0x38 + iRam0037e944;
  *(int *)(iVar1 + 0x1c) = (int)param_3;
  *(int *)(iVar1 + 0x18) = (int)param_2;
  *(undefined4 *)(iVar1 + 0x14) = 0;
  return 0;
}

