FUNCTION FUN_000007dc @ 0x000007dc size=88
CALLERS (1): FUN_00002098@0x00002098
CALLEES (1): FUN_00002804@0x00002804

void FUN_000007dc(int param_1)

{
  short sVar1;
  undefined2 local_18;
  undefined2 local_16;
  int local_14;
  undefined4 local_10;
  
  local_18 = *(undefined2 *)(param_1 + 0x1c);
  local_16 = *(undefined2 *)(param_1 + 0x1e);
  local_14 = param_1 + 0x20;
  local_10 = 0;
  sVar1 = FUN_00002804(&DAT_00004119,&local_18,0);
  *(int *)(param_1 + 0x18) = (int)sVar1;
  return;
}


================================================================