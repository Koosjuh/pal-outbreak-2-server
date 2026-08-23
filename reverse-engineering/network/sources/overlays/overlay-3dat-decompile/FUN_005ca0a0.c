FUNCTION FUN_005ca0a0 @ 0x005ca0a0  size=248
CALLERS (0): 
CALLEES (5): FUN_005cce30@0x005cce30, FUN_005d5c20@0x005d5c20, FUN_005cd1d0@0x005cd1d0, FUN_005d0a40@0x005d0a40, FUN_005ca6a0@0x005ca6a0
----------------------------------------------------------------

void FUN_005ca0a0(void)

{
  char cVar1;
  
  if ((*(char *)(iRam00701070 + 0x2e) == '\b') && (*(char *)(iRam00701070 + 0x38) == '\0')) {
    if ((((int)(*(ushort *)(iRam00701070 + 0x18) & 0x20) >> 5 != 0) &&
        ((((*(ushort *)(iRam00701068 + 0x4f8a4) & 0x8000) != 0 &&
          (*(char *)(iRam00701070 + 0x34) == '\0')) && (*(char *)(iRam00701068 + 0x68e85) == '\x01')
         ))) && (*(char *)(iRam00701068 + 0x68e84) == '\x02')) {
      *(undefined1 *)(iRam00701070 + 0x2e) = 9;
      FUN_005d5c20(6);
      return;
    }
    cVar1 = FUN_005cce30();
    if (cVar1 == -1) {
      FUN_005d0a40();
      *(undefined1 *)(iRam00701070 + 0x3a) = 0;
      return;
    }
  }
  FUN_005ca6a0();
  FUN_005cd1d0();
  return;
}



================================================================