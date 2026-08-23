FUNCTION FUN_005da780 @ 0x005da780  size=328
CALLERS (2): FUN_005c80a0@0x005c80a0, FUN_005da370@0x005da370
CALLEES (0): 
----------------------------------------------------------------

void FUN_005da780(char param_1,char param_2)

{
  ushort uVar1;
  
  *(undefined2 *)(iRam00701070 + 0x1a) = 0x10;
  *(undefined2 *)(iRam00701070 + 0x1c) = 0x10;
  *(undefined2 *)(iRam00701070 + 0x1e) = 0x14;
  *(undefined2 *)(iRam00701070 + 0x20) = 0x14;
  if (param_1 == '\0') {
    uVar1 = *(ushort *)(iRam00701070 + 0x18);
    if ((uVar1 & 1) == 0) {
      *(undefined2 *)(iRam00701070 + 0x1c) = 0x22;
      *(undefined2 *)(iRam00701070 + 0x1a) = 0x22;
      *(undefined2 *)(iRam00701070 + 0x20) = 0x1c;
      *(undefined2 *)(iRam00701070 + 0x1e) = 0x1c;
    }
    else if ((int)(uVar1 & 2) >> 1 != 0) {
      if ((int)(uVar1 & 4) >> 2 != 0) {
        *(undefined2 *)(iRam00701070 + 0x1a) = 0x10;
        *(undefined2 *)(iRam00701070 + 0x1c) = 0x10;
      }
      *(undefined2 *)(iRam00701070 + 0x1e) = 0x14;
      *(undefined2 *)(iRam00701070 + 0x20) = 0x14;
    }
  }
  else {
    *(undefined2 *)(iRam00701070 + 0x1a) = 0x30;
    *(undefined2 *)(iRam00701070 + 0x1c) = 0x30;
    *(undefined2 *)(iRam00701070 + 0x1e) = 0x14;
    *(undefined2 *)(iRam00701070 + 0x20) = 0x14;
    if (((int)(*(ushort *)(iRam00701070 + 0x18) & 2) >> 1 != 0) && (param_2 == '\x01')) {
      *(undefined1 *)(iRam00701068 + 0x68e81) = 1;
    }
  }
  return;
}



================================================================