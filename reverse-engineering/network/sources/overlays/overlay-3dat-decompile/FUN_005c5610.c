FUNCTION FUN_005c5610 @ 0x005c5610  size=136
CALLERS (0): 
CALLEES (2): FUN_005c5460@0x005c5460, FUN_005c5390@0x005c5390
----------------------------------------------------------------

void FUN_005c5610(char *param_1,int *param_2)

{
  int iVar1;
  
  if (*param_1 == '\0') {
    for (iVar1 = 0; iVar1 < 0x1e; iVar1 = iVar1 + 1) {
      if (*(int *)(iVar1 * 0x24 + 0x6fee8c) == *param_2) {
        FUN_005c5390(iVar1 + 1U & 0xffff);
        FUN_005c5460(iVar1 + 1U & 0xffff);
        return;
      }
    }
  }
  return;
}



================================================================