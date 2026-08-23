FUNCTION FUN_005d1c20 @ 0x005d1c20  size=320
CALLERS (0): 
CALLEES (0): 
----------------------------------------------------------------

void FUN_005d1c20(void)

{
  int iVar1;
  
  if (*(int *)(iRam00701070 + 8) < 0) {
    *(undefined4 *)(iRam00701070 + 8) = 0;
  }
  iVar1 = *(int *)(iRam00701070 + 0x10) + -0x17c;
  if (iVar1 < *(int *)(iRam00701070 + 8)) {
    *(int *)(iRam00701070 + 8) = iVar1;
  }
  if (*(int *)(iRam00701070 + 4) < 0) {
    *(undefined4 *)(iRam00701070 + 4) = 0;
  }
  iVar1 = *(int *)(iRam00701070 + 0xc) + -0x248;
  if (iVar1 < *(int *)(iRam00701070 + 4)) {
    *(int *)(iRam00701070 + 4) = iVar1;
  }
  if (*(short *)(iRam00701078 + 0x12) < *(short *)(iRam00701070 + 0x1a)) {
    *(short *)(iRam00701078 + 0x12) = *(short *)(iRam00701070 + 0x1a);
  }
  iVar1 = 0x1b6 - *(short *)(iRam00701070 + 0x1c);
  if ((long)iVar1 < (long)*(short *)(iRam00701078 + 0x12)) {
    *(short *)(iRam00701078 + 0x12) = (short)iVar1;
  }
  if (*(short *)(iRam00701078 + 0x10) < *(short *)(iRam00701070 + 0x1e)) {
    *(short *)(iRam00701078 + 0x10) = *(short *)(iRam00701070 + 0x1e);
  }
  iVar1 = 0x276 - *(short *)(iRam00701070 + 0x20);
  if ((long)iVar1 < (long)*(short *)(iRam00701078 + 0x10)) {
    *(short *)(iRam00701078 + 0x10) = (short)iVar1;
  }
  return;
}



================================================================