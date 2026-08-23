FUNCTION FUN_005c9360 @ 0x005c9360  size=256
CALLERS (0): 
CALLEES (0): 
----------------------------------------------------------------

void FUN_005c9360(void)

{
  long lVar1;
  
  uRam00700fe0 = 0;
  func_0x00109eb8(iRam00701068 + 0x4f7a0,0x701e20);
  lVar1 = func_0x00109d70(iRam00701068 + 0x4f7a0,iRam00701080 + 0x1c);
  if ((lVar1 == 0) ||
     (lVar1 = func_0x00109d70(iRam00701068 + 0x4f7a0,iRam00701080 + 0x11d), lVar1 == 0)) {
    *(undefined1 *)(iRam00701068 + 0x60dc7) = 1;
  }
  else {
    *(undefined1 *)(iRam00701068 + 0x60dc7) = 0;
  }
  *(int *)(iRam00701068 + 0x68dd4) = iRam00701068 + 0x60dd0;
  *(char *)(iRam00701070 + 2) = *(char *)(iRam00701070 + 2) + '\x01';
  *(undefined1 *)(iRam00701070 + 3) = 0;
  return;
}



================================================================