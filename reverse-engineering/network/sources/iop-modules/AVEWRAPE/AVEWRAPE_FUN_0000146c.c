FUNCTION FUN_0000146c @ 0x0000146c size=88
CALLERS (1): FUN_00002098@0x00002098
CALLEES (1): FUN_00002804@0x00002804

void FUN_0000146c(int param_1)

{
  short sVar1;
  undefined4 local_18;
  int local_14;
  int local_10;
  int local_c;
  
  local_14 = param_1 + 0x1c;
  local_10 = param_1 + 0x11c;
  local_c = param_1 + 0x120;
  local_18 = 0;
  sVar1 = FUN_00002804(&DAT_00004173,&local_18,0);
  *(int *)(param_1 + 0x18) = (int)sVar1;
  return;
}


================================================================