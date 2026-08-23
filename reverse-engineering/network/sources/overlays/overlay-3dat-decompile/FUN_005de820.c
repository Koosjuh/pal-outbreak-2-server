FUNCTION FUN_005de820 @ 0x005de820  size=88
CALLERS (1): FUN_005de8d0@0x005de8d0
CALLEES (0): 
----------------------------------------------------------------

int FUN_005de820(void)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  while( true ) {
    if (0x1ff < iVar2) {
      return 0;
    }
    iVar1 = iRam00701068 + iVar2 * 0xc;
    if (*(int *)(iVar1 + 0x4db70) == 0) break;
    iVar2 = iVar2 + 1;
  }
  return iVar1 + 0x4db70;
}



================================================================