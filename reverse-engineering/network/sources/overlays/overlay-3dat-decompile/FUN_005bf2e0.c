FUNCTION FUN_005bf2e0 @ 0x005bf2e0  size=84
CALLERS (1): FUN_005c0060@0x005c0060
CALLEES (0): 
----------------------------------------------------------------

int FUN_005bf2e0(int param_1)

{
  int iVar1;
  
  iVar1 = 0;
  while( true ) {
    if (0x1d < iVar1) {
      return -1;
    }
    if (*(int *)(iVar1 * 0x24 + 0x6fee8c) == param_1) break;
    iVar1 = iVar1 + 1;
  }
  return iVar1;
}



================================================================