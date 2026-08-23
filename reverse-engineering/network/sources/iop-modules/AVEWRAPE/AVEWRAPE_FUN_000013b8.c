FUNCTION FUN_000013b8 @ 0x000013b8 size=60
CALLERS (1): FUN_00002098@0x00002098
CALLEES (1): FUN_00002804@0x00002804

void FUN_000013b8(int param_1)

{
  short sVar1;
  
  sVar1 = FUN_00002804(&DAT_00004165,0,0);
  *(int *)(param_1 + 0x18) = (int)sVar1;
  return;
}


================================================================