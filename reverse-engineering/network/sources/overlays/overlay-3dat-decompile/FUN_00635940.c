FUNCTION FUN_00635940 @ 0x00635940  size=356
CALLERS (1): FUN_00634ab0@0x00634ab0
CALLEES (2): FUN_00635ab0@0x00635ab0, FUN_00631670@0x00631670
----------------------------------------------------------------

void FUN_00635940(void)

{
  if (((*(char *)(iRam00715da8 + 0x2f) == '\0') && ((*(uint *)(iRam00715da8 + 0x20) & 0x20) == 0))
     && (*(int *)(*(int *)(iRam00715da8 + 0x10) + 0x28) != 0)) {
    if ((*(byte *)(iRam00715da8 + 0x4a) & 1) == 0) {
      *(undefined1 *)(iRam00715da8 + 0x26) = 0;
      *(byte *)(iRam00715da8 + 0x4a) = *(byte *)(iRam00715da8 + 0x4a) | 1;
      *(undefined2 *)(iRam00715da8 + 0x48) = 1;
      FUN_00631670();
    }
    else {
      *(short *)(iRam00715da8 + 0x48) = *(short *)(iRam00715da8 + 0x48) + 5;
      if (0x3b < *(short *)(iRam00715da8 + 0x48)) {
        *(undefined2 *)(iRam00715da8 + 0x48) = 1;
      }
      *(char *)(iRam00715da8 + 0x24) = (char)((*(short *)(iRam00715da8 + 0x48) + 1) % 0x14);
      *(char *)(iRam00715da8 + 0x25) = (char)((*(short *)(iRam00715da8 + 0x48) + 1) / 0x14);
      if ((0x13 < *(byte *)(iRam00715da8 + 0x24)) || (2 < *(byte *)(iRam00715da8 + 0x25))) {
        *(undefined1 *)(iRam00715da8 + 0x24) = 5;
        *(undefined1 *)(iRam00715da8 + 0x25) = 0;
        *(undefined2 *)(iRam00715da8 + 0x48) = 1;
      }
    }
    FUN_00635ab0();
  }
  else {
    *(undefined4 *)(iRam00715da8 + 0x248) = 5;
  }
  return;
}



================================================================