FUNCTION FUN_00630010 @ 0x00630010  size=140
CALLERS (1): FUN_00634ab0@0x00634ab0
CALLEES (1): FUN_006300a0@0x006300a0
----------------------------------------------------------------

void FUN_00630010(void)

{
  *(undefined1 *)(iRam00715da8 + 0x4a5) = *(undefined1 *)(iRam00715da8 + 0x4a4);
  *(undefined1 *)(iRam00715da8 + 0x4a4) = *(undefined1 *)(iRam00715da8 + 0x49c);
  if ((*(byte *)(iRam00715da8 + 0x4a3) & 0x80) != 0) {
    *(undefined1 *)(iRam00715da8 + 0x4a3) = 0;
  }
  if ((*(char *)(iRam00715da8 + 0x4a4) != '\0') &&
     (*(char *)(iRam00715da8 + 0x4a4) != *(char *)(iRam00715da8 + 0x4a5))) {
    *(undefined1 *)(iRam00715da8 + 0x4a3) = 0x9e;
    FUN_006300a0();
  }
  return;
}



================================================================