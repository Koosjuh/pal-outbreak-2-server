FUNCTION FUN_00002620 @ 0x00002620 size=104
CALLERS (1): FUN_00002858@0x00002858
CALLEES (2): FUN_00003614@0x00003614, FUN_00003754@0x00003754

void FUN_00002620(int param_1)

{
  short sVar1;
  undefined2 local_18 [2];
  int *local_14;
  int local_10 [2];
  
  local_18[0] = *(undefined2 *)(param_1 + 0x1c);
  local_14 = local_10;
  sVar1 = FUN_00003614(&DAT_00004187,local_18,0);
  *(int *)(param_1 + 0x18) = (int)sVar1;
  if (sVar1 == 0) {
    if (local_10[0] != 0) {
      FUN_00003754(param_1 + 0x1e,local_10[0],0x100);
    }
  }
  return;
}


================================================================