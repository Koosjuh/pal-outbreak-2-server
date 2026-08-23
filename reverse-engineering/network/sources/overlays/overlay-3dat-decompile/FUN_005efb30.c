FUNCTION FUN_005efb30 @ 0x005efb30  size=296
CALLERS (1): FUN_005ea900@0x005ea900
CALLEES (0): 
----------------------------------------------------------------

void FUN_005efb30(int param_1)

{
  uint uVar1;
  
  if (*(char *)(iRam007012a0 + 0x186) == -10) {
    *(undefined1 *)(param_1 + 0x4c) = 0;
    *(undefined1 *)(param_1 + 0x4d) = 0;
    *(undefined2 *)(param_1 + 0x1c) = *(undefined2 *)(iRam007012a0 + 0xe02);
    *(undefined2 *)(param_1 + 0x1e) = *(undefined2 *)(iRam007012a0 + 0xe04);
    *(undefined2 *)(param_1 + 0x26) = *(undefined2 *)(iRam007012a0 + 0xe02);
    if (*(short *)(iRam007012a0 + 0xe02) != 0) {
      *(byte *)(param_1 + 0x46) = *(byte *)(param_1 + 0x46) | 5;
    }
    if (*(short *)(iRam007012a0 + 0xe04) != 0) {
      *(byte *)(param_1 + 0x46) = *(byte *)(param_1 + 0x46) | 2;
    }
    *(undefined1 *)(param_1 + 0x45) = *(undefined1 *)(iRam007012a0 + 0xdfc);
    if ((*(char *)(iRam007012a0 + 0xdfc) != '\0') && (*(ushort *)(iRam007012a0 + 0xdfe) < 2)) {
      *(undefined2 *)(iRam007012a0 + 0xdfe) = 2;
    }
    *(undefined2 *)(param_1 + 0x32) = *(undefined2 *)(iRam007012a0 + 0xe00);
    *(undefined2 *)(param_1 + 0x30) = *(undefined2 *)(iRam007012a0 + 0xdfe);
    *(undefined1 *)(param_1 + 0x44) = 0;
    *(undefined2 *)(param_1 + 0x20) = *(undefined2 *)(iRam007012a0 + 0xe02);
    uVar1 = ((uint)*(byte *)(param_1 + 0x45) + (uint)*(ushort *)(param_1 + 0x32)) * 2;
    if (*(ushort *)(param_1 + 0x1c) < uVar1) {
      *(short *)(param_1 + 0x1c) = (short)uVar1;
    }
  }
  return;
}



================================================================