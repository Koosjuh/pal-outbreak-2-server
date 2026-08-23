FUNCTION FUN_00627a20 @ 0x00627a20  size=84
CALLERS (1): FUN_005acab0@0x005acab0
CALLEES (0): 
----------------------------------------------------------------

void FUN_00627a20(void)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  iVar1 = 0;
  do {
    iVar1 = (iVar1 + iVar2) * 4;
    if (*(char *)(iVar1 + 0x715510) != '\0') {
      if (0 < *(short *)(iVar1 + 0x715512)) {
        *(short *)(iVar1 + 0x715512) = *(short *)(iVar1 + 0x715512) + -1;
      }
    }
    iVar2 = iVar2 + 1;
    iVar1 = iVar2 * 4;
  } while (iVar2 < 0x32);
  return;
}



================================================================