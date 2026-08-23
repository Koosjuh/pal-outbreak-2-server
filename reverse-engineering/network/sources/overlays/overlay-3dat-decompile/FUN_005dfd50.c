FUNCTION FUN_005dfd50 @ 0x005dfd50  size=48
CALLERS (1): FUN_005dfde0@0x005dfde0
CALLEES (0): 
----------------------------------------------------------------

void FUN_005dfd50(void)

{
  int iVar1;
  
  iVar1 = *(int *)(iRam00701068 + 0x5ff6c);
  if (iVar1 != 0) {
    *(int *)(iRam00701068 + 0x5ff6c) = *(int *)(iVar1 + 0x20);
  }
  return;
}



================================================================