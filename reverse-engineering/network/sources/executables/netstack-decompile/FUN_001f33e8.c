
undefined4 FUN_001f33e8(int param_1,uint param_2)

{
  int iVar1;
  
  if (iRam0037e940 <= param_1) {
    return 0xfffffff5;
  }
  if (1 < param_2) {
    return 0xfffffff4;
  }
  iVar1 = param_1 * 0x38 + iRam0037e944;
  if (param_2 == *(uint *)(iVar1 + 0xc)) {
    *(uint *)(iVar1 + 0xc) = param_2;
  }
  else {
    *(undefined4 *)(iVar1 + 0x14) = 0;
    *(undefined4 *)(iVar1 + 0x2c) = 0;
    *(undefined4 *)(iVar1 + 0x30) = 0;
    uRam0037e950 = 0;
    *(undefined2 *)(iVar1 + 0x20) = 0;
    *(uint *)(iVar1 + 0xc) = param_2;
  }
  return 0;
}

