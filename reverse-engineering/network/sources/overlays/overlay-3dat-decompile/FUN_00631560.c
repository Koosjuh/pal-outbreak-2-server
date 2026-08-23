FUNCTION FUN_00631560 @ 0x00631560  size=188
CALLERS (1): FUN_006314a0@0x006314a0
CALLEES (6): FUN_00637540@0x00637540, FUN_00637690@0x00637690, FUN_00637140@0x00637140, FUN_006322c0@0x006322c0, FUN_00633470@0x00633470, FUN_00637260@0x00637260
----------------------------------------------------------------

void FUN_00631560(char param_1)

{
  long lVar1;
  
  *(undefined4 *)(iRam00715da8 + 0x248) = 5;
  if ((*(char *)(iRam00715da8 + 0x2f) == '\0') &&
     (lVar1 = FUN_00637260(param_1 + -0x3a,iRam00715da8 + 0x1f,iRam00715da8 + 0x1e), lVar1 == 0)) {
    *(undefined4 *)(iRam00715da8 + 0x248) = 1;
    *(undefined1 *)(iRam00715da8 + 0x35) = 0;
    *(byte *)(iRam00715da8 + 0x4a) = *(byte *)(iRam00715da8 + 0x4a) & 0xfe;
    FUN_00637540();
    FUN_00637690();
    FUN_00637140();
    FUN_006322c0();
    if (*(char *)(iRam00715da8 + 0x36) != '\0') {
      FUN_00633470();
    }
  }
  return;
}



================================================================