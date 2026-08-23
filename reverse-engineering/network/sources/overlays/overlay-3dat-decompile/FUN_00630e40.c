FUNCTION FUN_00630e40 @ 0x00630e40  size=216
CALLERS (1): FUN_006300a0@0x006300a0
CALLEES (1): FUN_00634880@0x00634880
----------------------------------------------------------------

void FUN_00630e40(void)

{
  if ((*(char *)(iRam00715da8 + 0x2f) == '\x01') || (*(char *)(iRam00715da8 + 0x2f) == '\x03')) {
    *(undefined1 *)(iRam00715da8 + 0x28) = 0;
    *(undefined1 *)(iRam00715da8 + 0x26) = 0;
    *(undefined1 *)(iRam00715da8 + 0x2f) = 0;
    FUN_00634880();
    if (*(char *)(iRam00715da8 + 0x36) != '\0') {
      *(undefined2 *)(iRam00715da8 + 0x2c) = 0;
      *(undefined2 *)(iRam00715da8 + 0x260) = 0;
    }
  }
  else if (*(short *)(iRam00715da8 + 0x260) == 0) {
    *(undefined1 *)(iRam00715da8 + 0x32) = 0xff;
  }
  else {
    *(undefined1 *)(iRam00715da8 + 0x28) = 0;
    *(undefined2 *)(iRam00715da8 + 0x2c) = 0;
    *(undefined1 *)(iRam00715da8 + 0x2f) = 0;
    func_0x00106b60(iRam00715da8 + 0x260,0,4);
  }
  *(undefined4 *)(iRam00715da8 + 0x248) = 2;
  return;
}



================================================================