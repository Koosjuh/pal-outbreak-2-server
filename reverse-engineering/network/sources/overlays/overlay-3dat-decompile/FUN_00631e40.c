FUNCTION FUN_00631e40 @ 0x00631e40  size=124
CALLERS (2): FUN_00631d60@0x00631d60, FUN_006300a0@0x006300a0
CALLEES (3): FUN_00631ff0@0x00631ff0, FUN_00633430@0x00633430, FUN_006343b0@0x006343b0
----------------------------------------------------------------

void FUN_00631e40(void)

{
  long lVar1;
  
  lVar1 = FUN_006343b0();
  if ((lVar1 != 0) && (*(short *)(iRam00715da8 + 0x260) != 0)) {
    *(undefined4 *)(iRam00715da8 + 0x248) = 1;
    *(byte *)(iRam00715da8 + 0x4a) = *(byte *)(iRam00715da8 + 0x4a) & 0xfe;
    if (*(char *)(iRam00715da8 + 0x2f) == '\0') {
      FUN_00631ff0();
    }
    else {
      FUN_00633430();
    }
  }
  return;
}



================================================================