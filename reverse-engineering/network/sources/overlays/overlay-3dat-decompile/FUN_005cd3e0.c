FUNCTION FUN_005cd3e0 @ 0x005cd3e0  size=284
CALLERS (0): 
CALLEES (1): FUN_005e2060@0x005e2060
----------------------------------------------------------------

void FUN_005cd3e0(void)

{
  *(undefined1 *)(iRam00701068 + 0x60dc4) = 0;
  *(undefined1 *)(iRam00701068 + 0x68e7e) = 4;
  *(undefined1 *)(iRam00701068 + 0x68e7f) = 5;
  *(undefined1 *)(iRam00701068 + 0x68e82) = 5;
  *(undefined1 *)(iRam00701068 + 0x68e81) = 5;
  *(undefined1 *)(iRam00701068 + 0x68e80) = 5;
  *(undefined1 *)(iRam00701068 + 0x68e83) = 2;
  *(undefined1 *)(iRam00701068 + 0x68e84) = 3;
  *(undefined1 *)(iRam00701068 + 0x68e85) = 0xc;
  *(undefined1 *)(iRam00701068 + 0x68e86) = 3;
  if (*(char *)(iRam00701070 + 0x36) == '\0') {
    FUN_005e2060();
  }
  *(undefined1 *)(iRam00701070 + 2) = 1;
  return;
}



================================================================