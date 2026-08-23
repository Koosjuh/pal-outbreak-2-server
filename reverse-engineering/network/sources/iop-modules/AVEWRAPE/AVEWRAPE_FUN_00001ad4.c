FUNCTION FUN_00001ad4 @ 0x00001ad4 size=104
CALLERS (1): FUN_00002098@0x00002098
CALLEES (2): FUN_00002804@0x00002804, FUN_00002944@0x00002944

void FUN_00001ad4(int param_1)

{
  short sVar1;
  undefined2 local_18 [2];
  int *local_14;
  int local_10 [2];
  
  local_18[0] = *(undefined2 *)(param_1 + 0x1c);
  local_14 = local_10;
  sVar1 = FUN_00002804(&DAT_00004187,local_18,0);
  *(int *)(param_1 + 0x18) = (int)sVar1;
  if (sVar1 == 0) {
    if (local_10[0] != 0) {
      FUN_00002944(param_1 + 0x1e,local_10[0],0x100);
    }
  }
  return;
}


================================================================