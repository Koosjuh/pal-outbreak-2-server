FUNCTION FUN_00633840 @ 0x00633840  size=228
CALLERS (2): FUN_00631d60@0x00631d60, FUN_00633470@0x00633470
CALLEES (3): FUN_00633650@0x00633650, FUN_00633590@0x00633590, FUN_006335f0@0x006335f0
----------------------------------------------------------------

void FUN_00633840(void)

{
  int iVar1;
  long extraout_t0;
  int extraout_t1_lo;
  long lVar2;
  
  if (*(char *)(iRam00715da8 + 0x36) != '\0') {
    *(undefined4 *)(iRam00715da8 + 0x24c) = 0;
    *(undefined4 *)(iRam00715da8 + 0x250) = 0;
    if (*(int *)(iRam00715da8 + 600) != 0) {
      func_0x00106b60(0x7158f0,0,0x240);
      func_0x00106b60(0x715b30,0,0x30);
      iVar1 = *(int *)(iRam00715da8 + 600) + -1;
      if (3 < *(int *)(iRam00715da8 + 600)) {
        iVar1 = 2;
      }
      lVar2 = (long)iVar1;
      iVar1 = 0;
      while (iVar1 < (int)lVar2 + 1) {
        FUN_006335f0(iVar1,0);
        lVar2 = extraout_t0;
        iVar1 = extraout_t1_lo + 1;
      }
      FUN_00633650();
      iVar1 = 0;
      do {
        FUN_00633590(iVar1);
        iVar1 = iVar1 + 1;
      } while (iVar1 < 3);
    }
  }
  return;
}



================================================================