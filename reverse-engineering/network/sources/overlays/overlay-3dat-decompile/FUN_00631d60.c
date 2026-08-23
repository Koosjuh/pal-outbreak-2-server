FUNCTION FUN_00631d60 @ 0x00631d60  size=224
CALLERS (1): FUN_006300a0@0x006300a0
CALLEES (9): FUN_00633840@0x00633840, FUN_00633930@0x00633930, FUN_00631e40@0x00631e40, FUN_00633ab0@0x00633ab0, FUN_00630c50@0x00630c50, FUN_00632290@0x00632290, FUN_006333b0@0x006333b0, FUN_00633390@0x00633390, FUN_00633470@0x00633470
----------------------------------------------------------------

void FUN_00631d60(void)

{
  long lVar1;
  undefined4 uVar2;
  
  lVar1 = FUN_00632290();
  if ((lVar1 == 1) && (*(char *)(iRam00715da8 + 0x36) == '\0')) {
    FUN_00631e40();
  }
  else if (*(char *)(iRam00715da8 + 0x2f) == '\0') {
    if (*(char *)(iRam00715da8 + 0x36) == '\0') {
      if (*(short *)(iRam00715da8 + 0x260) != 0) {
        FUN_006333b0();
        uVar2 = FUN_00633390();
        *(undefined4 *)(iRam00715da8 + 600) = uVar2;
        FUN_00633840();
        *(undefined4 *)(iRam00715da8 + 0x248) = 0;
      }
    }
    else {
      FUN_00633470();
    }
  }
  else {
    *(undefined4 *)(iRam00715da8 + 0x248) = 0;
    lVar1 = FUN_00630c50();
    if (lVar1 == 0) {
      FUN_00633ab0();
    }
    else {
      FUN_00633930();
    }
  }
  return;
}



================================================================