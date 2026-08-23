FUNCTION FUN_005cd1d0 @ 0x005cd1d0  size=324
CALLERS (1): FUN_005ca0a0@0x005ca0a0
CALLEES (3): FUN_005d59f0@0x005d59f0, FUN_005dedf0@0x005dedf0, FUN_005d5c20@0x005d5c20
----------------------------------------------------------------

undefined4 FUN_005cd1d0(void)

{
  int iVar1;
  
  if (*(char *)(iRam00701070 + 0x38) != '\0') {
    *(char *)(iRam00701070 + 0x38) = *(char *)(iRam00701070 + 0x38) + -1;
  }
  iVar1 = *(int *)(iRam00701068 + 0x69014);
  if (0 < iVar1) {
    if (*(char *)(iRam00701068 + 0x68e83) != '\0') {
      return 0;
    }
    if (*(char *)(iRam00701068 + 0x68e84) != '\x02') {
      return 0;
    }
    iVar1 = iVar1 + -1;
    if (*(char *)(iRam00701068 + 0x68e85) != '\x01') {
      return 0;
    }
    *(int *)(iRam00701068 + 0x69014) = iVar1;
    if (iVar1 == 0) {
      FUN_005dedf0(iRam00701068 + 0x4f97c,iRam00701070 + 0x3b);
      if (*(char *)(iRam00701070 + 0x2e) == '\b') {
        FUN_005d5c20();
        return 1;
      }
      FUN_005d59f0();
      return 1;
    }
  }
  iVar1 = *(int *)(iRam00701068 + 0x69018);
  if (iVar1 < 1) {
    *(undefined1 *)(iRam00701078 + 3) = 0;
  }
  else {
    *(int *)(iRam00701068 + 0x69018) = iVar1 + -1;
  }
  return 0;
}



================================================================