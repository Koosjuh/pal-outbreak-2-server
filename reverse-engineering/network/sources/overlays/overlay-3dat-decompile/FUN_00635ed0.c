FUNCTION FUN_00635ed0 @ 0x00635ed0  size=172
CALLERS (3): FUN_00630c90@0x00630c90, FUN_00634ab0@0x00634ab0, FUN_00633470@0x00633470
CALLEES (1): FUN_00631ff0@0x00631ff0
----------------------------------------------------------------

void FUN_00635ed0(void)

{
  if (*(short *)(iRam00715da8 + 0x260) == 0) {
    if (*(int *)(iRam00715da8 + 0x44) != 0) {
      if (-1 < *(int *)(iRam00715da8 + 0x44)) {
        *(undefined4 *)(iRam00715da8 + 0x248) = 5;
        return;
      }
      *(undefined4 *)(iRam00715da8 + 0x44) = 0;
    }
    *(undefined1 *)(iRam00715da8 + 0x32) = 1;
    if ((*(short *)(iRam00715da8 + 0x260) == 0) && (*(short *)(iRam00715da8 + 0x4c) == 0)) {
      *(undefined4 *)(iRam00715da8 + 0x248) = 5;
    }
    else {
      *(undefined4 *)(iRam00715da8 + 0x248) = 1;
    }
  }
  else {
    FUN_00631ff0();
    *(undefined4 *)(iRam00715da8 + 0x248) = 1;
  }
  return;
}



================================================================