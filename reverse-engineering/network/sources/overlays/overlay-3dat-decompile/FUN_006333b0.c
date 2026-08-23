FUNCTION FUN_006333b0 @ 0x006333b0  size=124
CALLERS (2): FUN_00631d60@0x00631d60, FUN_00633470@0x00633470
CALLEES (1): FUN_00633390@0x00633390
----------------------------------------------------------------

void FUN_006333b0(void)

{
  undefined4 uVar1;
  
  if (*(char *)(iRam00715da8 + 0x36) != '\0') {
    *(undefined2 *)(iRam00715da8 + 0x260) = 0;
    *(undefined2 *)(iRam00715da8 + 0x47c) = 0;
    *(undefined2 *)(iRam00715da8 + 0x48c) = 0;
    uVar1 = FUN_00633390();
    *(undefined4 *)(iRam00715da8 + 600) = uVar1;
    *(undefined2 *)(iRam00715da8 + 0x46c) = 0;
    *(undefined1 *)(iRam00715da8 + 0x2f) = 1;
    *(undefined1 *)(iRam00715da8 + 0x26) = 1;
  }
  return;
}



================================================================