FUNCTION FUN_005dfcf0 @ 0x005dfcf0  size=92
CALLERS (2): FUN_005cd650@0x005cd650, FUN_005c80a0@0x005c80a0
CALLEES (0): 
----------------------------------------------------------------

void FUN_005dfcf0(void)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  *(int *)(iRam00701068 + 0x5ff6c) = iRam00701068 + 0x4ff6c;
  iVar1 = iRam00701068 + 0x4ff6c;
  do {
    iVar2 = iVar2 + 1;
    *(int *)(iVar1 + 0x20) = iVar1 + 0x80;
    iVar1 = iVar1 + 0x80;
  } while (iVar2 < 0x1ff);
  return;
}



================================================================