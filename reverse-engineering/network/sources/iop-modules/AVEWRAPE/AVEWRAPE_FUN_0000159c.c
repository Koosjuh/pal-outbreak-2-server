FUNCTION FUN_0000159c @ 0x0000159c size=60
CALLERS (1): FUN_00002098@0x00002098
CALLEES (1): FUN_00002804@0x00002804

void FUN_0000159c(int param_1)

{
  short sVar1;
  
  sVar1 = FUN_00002804(&DAT_00004177,param_1 + 0x1c,0);
  *(int *)(param_1 + 0x18) = (int)sVar1;
  return;
}


================================================================