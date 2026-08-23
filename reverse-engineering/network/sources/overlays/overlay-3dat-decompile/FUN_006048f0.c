FUNCTION FUN_006048f0 @ 0x006048f0  size=72
CALLERS (3): FUN_00603f30@0x00603f30, FUN_00604c90@0x00604c90, FUN_006049b0@0x006049b0
CALLEES (0): 
----------------------------------------------------------------

int FUN_006048f0(int param_1,uint param_2)

{
  int iVar1;
  
  iVar1 = 0;
  while( true ) {
    if ((int)(param_2 & 0xff) <= iVar1) {
      return -1;
    }
    if (*(char *)(param_1 + iVar1 * 0x38 + 0x10) == '\0') break;
    iVar1 = iVar1 + 1;
  }
  return iVar1;
}



================================================================