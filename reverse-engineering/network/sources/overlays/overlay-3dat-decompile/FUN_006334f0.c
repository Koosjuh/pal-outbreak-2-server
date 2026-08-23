FUNCTION FUN_006334f0 @ 0x006334f0  size=152
CALLERS (1): FUN_00632330@0x00632330
CALLEES (1): FUN_006320f0@0x006320f0
----------------------------------------------------------------

void FUN_006334f0(void)

{
  short sVar1;
  
  if ((*(short *)(iRam00715da8 + 0x47c) != 0) && (*(char *)(iRam00715da8 + 0x2f) == '\x01')) {
    sVar1 = FUN_006320f0(iRam00715da8 + 0x4c,iRam00715da8 + 0x47c,
                         *(undefined2 *)(iRam00715da8 + 0x2a),*(undefined2 *)(iRam00715da8 + 0x3a));
    *(short *)(iRam00715da8 + 0x2a) = *(short *)(iRam00715da8 + 0x2a) + sVar1;
    func_0x00106b60(iRam00715da8 + 0x260,0,0xfa);
    *(undefined1 *)(iRam00715da8 + 0x2f) = 0;
    *(undefined1 *)(iRam00715da8 + 0x26) = 0;
    *(undefined2 *)(iRam00715da8 + 0x2c) = 0;
  }
  return;
}



================================================================