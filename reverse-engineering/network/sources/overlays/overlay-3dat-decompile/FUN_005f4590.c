FUNCTION FUN_005f4590 @ 0x005f4590  size=152
CALLERS (0): 
CALLEES (0): 
----------------------------------------------------------------

undefined4 FUN_005f4590(char param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  if (iRam00343628 != 0) {
    iVar1 = iRam00343628 + *(int *)(iRam00343628 + 8);
    do {
      if (*(char *)(iVar1 + 1) == param_1) {
        if (cRam0034359d == '\0') {
          func_0x001b6650(iVar1 + 8,0x702040);
        }
        else {
          func_0x001b6650(iVar1 + 0x28,0x702040);
        }
        return 0x702040;
      }
      iVar2 = iVar2 + 1;
      iVar1 = iVar1 + 0x58;
    } while (iVar2 < 0x7f);
  }
  return 0;
}



================================================================