FUNCTION FUN_000015d8 @ 0x000015d8 size=112
CALLERS (1): FUN_00002098@0x00002098
CALLEES (1): FUN_00002804@0x00002804

void FUN_000015d8(int param_1)

{
  short sVar1;
  undefined2 local_28 [2];
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  int local_18;
  int local_14;
  int local_10;
  undefined4 local_c;
  
  local_28[0] = 0;
  local_24 = 0;
  local_20 = *(undefined4 *)(param_1 + 0x1c);
  local_18 = param_1 + 0x20;
  local_14 = param_1 + 0x24;
  local_10 = param_1 + 0x28;
  local_1c = 0;
  local_c = *(undefined4 *)(param_1 + 0x2c);
  sVar1 = FUN_00002804(&DAT_00004178,local_28,0);
  *(int *)(param_1 + 0x18) = (int)sVar1;
  return;
}


================================================================