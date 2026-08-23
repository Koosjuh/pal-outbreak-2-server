FUNCTION FUN_00000168 @ 0x00000168 size=52
CALLERS (1): FUN_00002098@0x00002098
CALLEES (1): FUN_0000280c@0x0000280c

void FUN_00000168(int param_1)

{
  short sVar1;
  undefined1 auStack_10 [8];
  
  sVar1 = FUN_0000280c(auStack_10);
  *(int *)(param_1 + 0x18) = (int)sVar1;
  return;
}


================================================================