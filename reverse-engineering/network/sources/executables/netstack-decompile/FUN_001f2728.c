
undefined4 FUN_001f2728(int param_1,ulong param_2)

{
  if (iRam0037e940 <= param_1) {
    return 0xfffffff5;
  }
  if (1 < param_2) {
    return 0xfffffff4;
  }
  *(int *)(param_1 * 0x38 + iRam0037e944 + 4) = (int)param_2;
  return 0;
}

