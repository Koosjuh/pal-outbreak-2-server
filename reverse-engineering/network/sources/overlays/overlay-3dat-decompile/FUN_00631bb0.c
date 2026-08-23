FUNCTION FUN_00631bb0 @ 0x00631bb0  size=208
CALLERS (2): FUN_00635030@0x00635030, FUN_006300a0@0x006300a0
CALLEES (4): FUN_00631910@0x00631910, FUN_00631a30@0x00631a30, FUN_00630c70@0x00630c70, FUN_00633fa0@0x00633fa0
----------------------------------------------------------------

void FUN_00631bb0(void)

{
  short sVar1;
  long lVar2;
  
  lVar2 = FUN_00631a30();
  if (lVar2 == 1) {
    FUN_00631910(0);
    *(byte *)(iRam00715da8 + 0x4a) = *(byte *)(iRam00715da8 + 0x4a) & 0xfe;
  }
  else if (((*(char *)(iRam00715da8 + 0x2f) == '\0') && (*(short *)(iRam00715da8 + 0x260) == 0)) &&
          (*(short *)(iRam00715da8 + 0x2a) != 0)) {
    lVar2 = FUN_00630c70();
    if (lVar2 == 0) {
      sVar1 = FUN_00633fa0(iRam00715da8 + 0x4c,*(undefined2 *)(iRam00715da8 + 0x2a));
      *(short *)(iRam00715da8 + 0x2a) = *(short *)(iRam00715da8 + 0x2a) - sVar1;
    }
    else {
      *(undefined2 *)(iRam00715da8 + 0x2a) = 0;
    }
    *(undefined1 *)(iRam00715da8 + 0x28) = 0;
    *(undefined4 *)(iRam00715da8 + 0x248) = 0;
  }
  return;
}



================================================================