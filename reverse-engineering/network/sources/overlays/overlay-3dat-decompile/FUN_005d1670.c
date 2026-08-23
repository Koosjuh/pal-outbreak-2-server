FUNCTION FUN_005d1670 @ 0x005d1670  size=812
CALLERS (0): 
CALLEES (1): FUN_005d5df0@0x005d5df0
----------------------------------------------------------------

void FUN_005d1670(void)

{
  long lVar1;
  int iVar2;
  
  if (*(char *)(iRam00701078 + 4) != '\0') {
    return;
  }
  if (((long)(*(short *)(iRam00701070 + 0x1e) + 0x248) < (long)*(short *)(iRam00701078 + 0x10)) &&
     ((long)*(short *)(iRam00701078 + 0x10) < (long)(0x280 - *(short *)(iRam00701070 + 0x20)))) {
    if (*(int *)(iRam00701070 + 0x10) == 0) {
      return;
    }
    lVar1 = (long)*(short *)(iRam00701078 + 0x12);
    iVar2 = (int)*(short *)(iRam00701070 + 0x1a);
    if ((*(short *)(iRam00701070 + 0x1a) <= lVar1) && (lVar1 < iVar2 + 0x10)) {
      FUN_005d5df0(0,0xffffffffffffffec,1);
      *(undefined1 *)(iRam00701068 + 0x68e80) = 3;
      return;
    }
    if ((0x17c < lVar1) && (lVar1 < iVar2 + 0x17c)) {
      FUN_005d5df0(0,0x14,2);
      *(undefined1 *)(iRam00701068 + 0x68e80) = 4;
      return;
    }
    if ((iVar2 + 0x10 < lVar1) && (lVar1 < iVar2 + 0x17c)) {
      if (lVar1 < *(short *)(iRam00701070 + 0x24)) {
        *(int *)(iRam00701070 + 8) = *(int *)(iRam00701070 + 8) + -0x167;
      }
      if ((long)((int)*(short *)(iRam00701070 + 0x24) + (int)*(short *)(iRam00701070 + 0x22)) <
          (long)*(short *)(iRam00701078 + 0x12)) {
        *(int *)(iRam00701070 + 8) = *(int *)(iRam00701070 + 8) + 0x167;
      }
      *(short *)(iRam00701070 + 0x24) =
           (short)((*(int *)(iRam00701070 + 8) * 0x15c) / *(int *)(iRam00701070 + 0x10)) + 0x10;
    }
  }
  if ((((long)(*(short *)(iRam00701070 + 0x1a) + 0x17c) < (long)*(short *)(iRam00701078 + 0x12)) &&
      ((long)*(short *)(iRam00701078 + 0x12) < (long)(0x1ac - *(short *)(iRam00701070 + 0x1c)))) &&
     (*(int *)(iRam00701070 + 0xc) != 0)) {
    lVar1 = (long)*(short *)(iRam00701078 + 0x10);
    iVar2 = (int)*(short *)(iRam00701070 + 0x20);
    if ((lVar1 < *(short *)(iRam00701070 + 0x20)) || (iVar2 + 0x10 <= lVar1)) {
      if ((lVar1 < 0x24d) || (iVar2 + 0x248 <= lVar1)) {
        if ((iVar2 + 0x10 < lVar1) && (lVar1 < iVar2 + 0x24c)) {
          if (lVar1 < *(short *)(iRam00701070 + 0x28)) {
            *(int *)(iRam00701070 + 4) = *(int *)(iRam00701070 + 4) + -0x200;
          }
          if ((long)((int)*(short *)(iRam00701070 + 0x28) + (int)*(short *)(iRam00701070 + 0x26)) <
              (long)*(short *)(iRam00701078 + 0x10)) {
            *(int *)(iRam00701070 + 4) = *(int *)(iRam00701070 + 4) + 0x200;
          }
          *(short *)(iRam00701070 + 0x28) =
               (short)((*(int *)(iRam00701070 + 4) * 0x228) / *(int *)(iRam00701070 + 0xc)) + 0x10;
        }
      }
      else {
        FUN_005d5df0(0x14,0,4);
        *(undefined1 *)(iRam00701068 + 0x68e81) = 4;
      }
    }
    else {
      FUN_005d5df0(0xffffffffffffffec,0,3);
      *(undefined1 *)(iRam00701068 + 0x68e81) = 3;
    }
  }
  return;
}



================================================================