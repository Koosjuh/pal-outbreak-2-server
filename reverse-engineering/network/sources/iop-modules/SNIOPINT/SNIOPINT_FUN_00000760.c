FUNCTION FUN_00000760 @ 0x00000760 size=52
CALLERS (1): FUN_00002858@0x00002858
CALLEES (1): FUN_0000361c@0x0000361c

void FUN_00000760(int param_1)

{
  short sVar1;
  undefined1 auStack_10 [8];
  
  sVar1 = FUN_0000361c(auStack_10);
  *(int *)(param_1 + 0x18) = (int)sVar1;
  return;
}


================================================================