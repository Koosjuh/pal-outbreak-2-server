FUNCTION FUN_005bf280 @ 0x005bf280  size=84
CALLERS (2): FUN_005bf740@0x005bf740, FUN_005c70e0@0x005c70e0
CALLEES (0): 
----------------------------------------------------------------

int FUN_005bf280(int param_1)

{
  int iVar1;
  
  iVar1 = 0;
  while( true ) {
    if (9 < iVar1) {
      return -1;
    }
    if (*(int *)(iVar1 * 0x24 + 0x6fec28) == param_1) break;
    iVar1 = iVar1 + 1;
  }
  return iVar1;
}



================================================================