FUNCTION FUN_00631ff0 @ 0x00631ff0  size=252
CALLERS (11): FUN_00631e40@0x00631e40, FUN_00630750@0x00630750, FUN_00635ed0@0x00635ed0, FUN_00635bb0@0x00635bb0, FUN_006353e0@0x006353e0, FUN_006355a0@0x006355a0, FUN_00634ab0@0x00634ab0, FUN_00633430@0x00633430, FUN_00631670@0x00631670, FUN_006312c0@0x006312c0, FUN_006378b0@0x006378b0
CALLEES (3): FUN_00634880@0x00634880, FUN_00637ed0@0x00637ed0, FUN_006320f0@0x006320f0
----------------------------------------------------------------

void FUN_00631ff0(void)

{
  short sVar1;
  
  if (*(short *)(iRam00715da8 + 0x260) == 0) {
    return;
  }
  FUN_00637ed0(iRam00715da8 + 0x45c,iRam00715da8 + 0x260,8);
  if (*(char *)(iRam00715da8 + 0x2f) != '\x01') {
    if (*(char *)(iRam00715da8 + 0x2f) != '\x03') goto LAB_0063206c;
    FUN_00634880();
  }
  if (*(char *)(iRam00715da8 + 0x30) == '\x01') {
    *(undefined1 *)(iRam00715da8 + 0x26) = 0;
  }
LAB_0063206c:
  *(undefined1 *)(iRam00715da8 + 0x2f) = 0;
  sVar1 = FUN_006320f0(iRam00715da8 + 0x4c,iRam00715da8 + 0x45c,*(undefined2 *)(iRam00715da8 + 0x2a)
                       ,*(undefined2 *)(iRam00715da8 + 0x3a));
  func_0x00106b60(iRam00715da8 + 0x260,0,0xfa);
  *(short *)(iRam00715da8 + 0x2a) = *(short *)(iRam00715da8 + 0x2a) + sVar1;
  *(undefined2 *)(iRam00715da8 + 0x2c) = 0;
  *(undefined1 *)(iRam00715da8 + 0x28) = 0;
  return;
}



================================================================