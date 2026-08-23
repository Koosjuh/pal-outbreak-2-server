FUNCTION FUN_0000113c @ 0x0000113c size=72
CALLERS (1): FUN_00002098@0x00002098
CALLEES (1): FUN_00002804@0x00002804

void FUN_0000113c(int param_1)

{
  short sVar1;
  undefined4 local_10 [2];
  
  sVar1 = FUN_00002804(&DAT_00004159,0,local_10);
  *(int *)(param_1 + 0x18) = (int)sVar1;
  *(undefined4 *)(param_1 + 0x1c) = local_10[0];
  return;
}


================================================================