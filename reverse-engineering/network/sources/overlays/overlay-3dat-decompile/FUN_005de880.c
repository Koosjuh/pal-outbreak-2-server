FUNCTION FUN_005de880 @ 0x005de880  size=76
CALLERS (1): FUN_005dea10@0x005dea10
CALLEES (0): 
----------------------------------------------------------------

int FUN_005de880(int param_1)

{
  int iVar1;
  
  iVar1 = iRam00701068 + 0x4db70;
  do {
    if (*(int *)(iVar1 + 4) == param_1) {
      return iVar1;
    }
    iVar1 = *(int *)(iVar1 + 8);
  } while (iVar1 != iRam00701068 + 0x4f364);
  return 0;
}



================================================================