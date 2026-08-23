FUNCTION FUN_005e0050 @ 0x005e0050  size=144
CALLERS (1): FUN_005cd650@0x005cd650
CALLEES (0): 
----------------------------------------------------------------

void FUN_005e0050(void)

{
  long lVar1;
  int iVar2;
  
  lVar1 = 0;
  while( true ) {
    iVar2 = (int)lVar1 * 4;
    if (*(char *)(iRam00701068 + 0x609c0) <= lVar1) break;
    if (*(int *)(iRam00701068 + iVar2 + 0x607c0) != 0) {
      func_0x001cbbb0();
      *(undefined4 *)(iRam00701068 + iVar2 + 0x607c0) = 0;
    }
    lVar1 = (long)((int)lVar1 + 1);
  }
  *(char *)(iRam00701068 + 0x609c0) = '\0';
  return;
}



================================================================