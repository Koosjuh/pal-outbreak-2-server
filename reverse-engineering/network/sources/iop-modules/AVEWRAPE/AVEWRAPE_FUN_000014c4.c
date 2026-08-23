FUNCTION FUN_000014c4 @ 0x000014c4 size=72
CALLERS (1): FUN_00002098@0x00002098
CALLEES (1): FUN_00002804@0x00002804

void FUN_000014c4(int param_1)

{
  short sVar1;
  undefined4 local_10;
  int local_c;
  
  local_c = param_1 + 0x1c;
  local_10 = 0;
  sVar1 = FUN_00002804(&DAT_00004174,&local_10,0);
  *(int *)(param_1 + 0x18) = (int)sVar1;
  return;
}


================================================================