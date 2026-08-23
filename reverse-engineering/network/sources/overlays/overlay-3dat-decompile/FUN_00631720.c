FUNCTION FUN_00631720 @ 0x00631720  size=100
CALLERS (1): FUN_006300a0@0x006300a0
CALLEES (0): 
----------------------------------------------------------------

void FUN_00631720(void)

{
  if (*(char *)(iRam00715da8 + 0x2f) == '\0') {
    if (*(short *)(iRam00715da8 + 0x260) == 0) {
      if (*(short *)(iRam00715da8 + 0x2a) != 0) {
        *(undefined2 *)(iRam00715da8 + 0x2a) = 0;
      }
    }
    else if (*(short *)(iRam00715da8 + 0x2c) != 0) {
      *(undefined2 *)(iRam00715da8 + 0x2c) = 0;
    }
  }
  *(undefined1 *)(iRam00715da8 + 0x28) = 0;
  *(undefined4 *)(iRam00715da8 + 0x248) = 1;
  return;
}



================================================================