FUNCTION FUN_005f08c0 @ 0x005f08c0  size=100
CALLERS (2): FUN_005f0930@0x005f0930, FUN_005f10a0@0x005f10a0
CALLEES (0): 
----------------------------------------------------------------

int FUN_005f08c0(int param_1)

{
  int iVar1;
  
  if ((*(int *)(param_1 + 4) != 0) && (iVar1 = *(int *)(*(int *)(param_1 + 4) + 0xc), iVar1 != 0)) {
    do {
      if (*(char *)(iVar1 + 0x4c) == *(char *)(param_1 + 0x4c)) {
        if (*(byte *)(iVar1 + 0x48) < 2) {
          return 0;
        }
        return iVar1;
      }
      iVar1 = *(int *)(iVar1 + 8);
    } while (iVar1 != 0);
  }
  return 0;
}



================================================================