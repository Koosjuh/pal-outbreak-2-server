FUNCTION FUN_005c8e00 @ 0x005c8e00  size=100
CALLERS (0): 
CALLEES (1): FUN_005de170@0x005de170
----------------------------------------------------------------

void FUN_005c8e00(void)

{
  long lVar1;
  
  lVar1 = FUN_005de170(1);
  if ((lVar1 != 0) && (*(short *)lVar1 == 2)) {
    *(undefined1 *)(iRam00701070 + 1) = 2;
    *(undefined1 *)(iRam00701070 + 2) = 0;
  }
  return;
}



================================================================