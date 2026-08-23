FUNCTION FUN_000002a4 @ 0x000002a4 size=96
CALLERS (1): FUN_00002098@0x00002098
CALLEES (1): FUN_00002804@0x00002804

void FUN_000002a4(int param_1)

{
  short sVar1;
  undefined2 local_18;
  undefined2 local_16;
  undefined2 local_14;
  int local_10;
  
  local_18 = *(undefined2 *)(param_1 + 0x1c);
  local_16 = *(undefined2 *)(param_1 + 0x1e);
  local_14 = *(undefined2 *)(param_1 + 0x20);
  local_10 = param_1 + 0x22;
  sVar1 = FUN_00002804(&DAT_00004108,&local_18,0);
  *(int *)(param_1 + 0x18) = (int)sVar1;
  return;
}


================================================================