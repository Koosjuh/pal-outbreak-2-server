FUNCTION FUN_0000bb10 @ 0x0000bb10 size=52
CALLERS (0): 
CALLEES (1): FUN_0000e904@0x0000e904

void FUN_0000bb10(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x30);
  FUN_0000e904(*(undefined4 *)(iVar1 + 0x98));
  *(undefined4 *)(iVar1 + 0x98) = 0;
  return;
}


================================================================