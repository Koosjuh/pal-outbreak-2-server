FUNCTION FUN_000004e8 @ 0x000004e8 size=124
CALLERS (1): FUN_00002098@0x00002098
CALLEES (1): FUN_00002804@0x00002804

void FUN_000004e8(int param_1)

{
  short sVar1;
  undefined2 local_18 [2];
  undefined4 local_14;
  undefined4 local_10;
  
  if (DAT_00002c58 != -0xe) {
    DAT_00002c58 = -0xe;
    DAT_00002c5a = 0;
    DAT_00002c5c = 0;
    DAT_00002c60 = 0;
  }
  local_18[0] = *(undefined2 *)(param_1 + 0x1c);
  local_14 = 0x4b4;
  local_10 = 0;
  sVar1 = FUN_00002804(&DAT_00004112,local_18,0);
  *(int *)(param_1 + 0x18) = (int)sVar1;
  return;
}


================================================================