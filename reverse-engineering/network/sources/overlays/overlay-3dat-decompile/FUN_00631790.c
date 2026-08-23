FUNCTION FUN_00631790 @ 0x00631790  size=128
CALLERS (1): FUN_006300a0@0x006300a0
CALLEES (3): FUN_00631ec0@0x00631ec0, FUN_00630c70@0x00630c70, FUN_00631810@0x00631810
----------------------------------------------------------------

void FUN_00631790(void)

{
  long lVar1;
  
  if (*(char *)(iRam00715da8 + 0x2f) == '\0') {
    *(undefined4 *)(iRam00715da8 + 0x248) = 1;
    lVar1 = FUN_00630c70();
    if (lVar1 == 0) {
      FUN_00631ec0();
    }
    else if (*(short *)(iRam00715da8 + 0x260) == 0) {
      FUN_00631810(iRam00715da8 + 0x4c,*(undefined2 *)(iRam00715da8 + 0x2a));
    }
    else {
      FUN_00631810(iRam00715da8 + 0x260,*(undefined2 *)(iRam00715da8 + 0x2c));
    }
  }
  else {
    *(undefined4 *)(iRam00715da8 + 0x248) = 5;
  }
  return;
}



================================================================