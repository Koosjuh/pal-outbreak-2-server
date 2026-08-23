FUNCTION FUN_000012cc @ 0x000012cc size=80
CALLERS (1): FUN_00002098@0x00002098
CALLEES (1): FUN_00002804@0x00002804

void FUN_000012cc(int param_1)

{
  short sVar1;
  undefined2 local_10 [4];
  
  local_10[0] = 0;
  FUN_00002804(&DAT_00004142,local_10,0);
  sVar1 = FUN_00002804(&DAT_00004162,0,0);
  *(int *)(param_1 + 0x18) = (int)sVar1;
  return;
}


================================================================