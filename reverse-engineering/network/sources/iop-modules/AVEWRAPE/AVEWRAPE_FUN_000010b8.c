FUNCTION FUN_000010b8 @ 0x000010b8 size=72
CALLERS (1): FUN_00002098@0x00002098
CALLEES (1): FUN_00002804@0x00002804

void FUN_000010b8(int param_1)

{
  short sVar1;
  undefined2 local_10 [2];
  undefined2 local_c;
  
  local_10[0] = 0;
  local_c = 1;
  sVar1 = FUN_00002804(&DAT_00004155,local_10,0);
  *(int *)(param_1 + 0x18) = (int)sVar1;
  return;
}


================================================================