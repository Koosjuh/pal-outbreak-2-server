FUNCTION FUN_00001648 @ 0x00001648 size=124
CALLERS (1): FUN_00002098@0x00002098
CALLEES (1): FUN_00002804@0x00002804

void FUN_00001648(int param_1)

{
  short sVar1;
  undefined2 local_28 [2];
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 *local_18;
  undefined4 *local_14;
  undefined4 *local_10;
  undefined4 local_c;
  
  local_28[0] = 0;
  local_24 = 0;
  local_20 = *(undefined4 *)(param_1 + 0x1c);
  local_18 = &DAT_00003de4;
  local_14 = &DAT_00003de8;
  local_1c = 0;
  local_10 = &DAT_00003dec;
  local_c = *(undefined4 *)(param_1 + 0x20);
  sVar1 = FUN_00002804(&DAT_00004179,local_28,0);
  *(int *)(param_1 + 0x18) = (int)sVar1;
  return;
}


================================================================