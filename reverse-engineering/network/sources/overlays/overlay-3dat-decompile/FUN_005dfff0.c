FUNCTION FUN_005dfff0 @ 0x005dfff0  size=96
CALLERS (0): 
CALLEES (0): 
----------------------------------------------------------------

void FUN_005dfff0(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(param_1 * 4 + iRam00701068 + 0x5ff70);
  while (iVar2 = iVar1, iVar2 != 0) {
    iVar1 = *(int *)(iVar2 + 0x20);
    if (*(char *)(iVar2 + 1) != '\0') {
      (**(code **)(iVar2 + 0x18))();
    }
  }
  return;
}



================================================================