FUNCTION FUN_00631030 @ 0x00631030  size=200
CALLERS (1): FUN_006300a0@0x006300a0
CALLEES (3): FUN_00631f80@0x00631f80, FUN_00630c70@0x00630c70, FUN_00635cb0@0x00635cb0
----------------------------------------------------------------

void FUN_00631030(void)

{
  short sVar1;
  long lVar2;
  short *psVar3;
  
  if ((*(byte *)(iRam00715da8 + 0x4a) & 1) == 0) {
    if ((*(char *)(iRam00715da8 + 0x2f) == '\0') && (lVar2 = FUN_00630c70(1), lVar2 != 0)) {
      if (*(short *)(iRam00715da8 + 0x260) == 0) {
        psVar3 = (short *)(iRam00715da8 + 0x2a);
        sVar1 = FUN_00631f80(iRam00715da8 + 0x4c,*(undefined2 *)(iRam00715da8 + 0x2a));
        *psVar3 = *psVar3 - sVar1;
      }
      else {
        FUN_00631f80(iRam00715da8 + 0x260,*(undefined2 *)(iRam00715da8 + 0x2c));
      }
      *(undefined4 *)(iRam00715da8 + 0x248) = 1;
    }
    else {
      FUN_00635cb0(1);
    }
  }
  else {
    *(undefined1 *)(iRam00715da8 + 0x32) = 0xff;
    *(undefined4 *)(iRam00715da8 + 0x248) = 2;
  }
  return;
}



================================================================