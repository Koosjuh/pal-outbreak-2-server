FUNCTION FUN_0000150c @ 0x0000150c size=84
CALLERS (1): FUN_00002098@0x00002098
CALLEES (1): FUN_00002804@0x00002804

void FUN_0000150c(int param_1)

{
  short sVar1;
  int local_18;
  int local_14;
  int local_10;
  
  local_18 = param_1 + 0x1c;
  local_14 = param_1 + 0x20;
  local_10 = param_1 + 0x24;
  sVar1 = FUN_00002804(&DAT_00004175,&local_18,0);
  *(int *)(param_1 + 0x18) = (int)sVar1;
  return;
}


================================================================