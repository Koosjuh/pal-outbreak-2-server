FUNCTION FUN_005b5fb0 @ 0x005b5fb0  size=116
CALLERS (0): 
CALLEES (2): FUN_005c4ce0@0x005c4ce0, FUN_006000e0@0x006000e0
----------------------------------------------------------------

void FUN_005b5fb0(void)

{
  undefined1 auStack_310 [16];
  int iStack_300;
  undefined1 uStack_2fc;
  
  if (cRam006c4b90 != '\x06') {
    FUN_005c4ce0(auStack_310);
    if (iStack_300 == 0) {
      uRam006c5539 = uStack_2fc;
    }
    else if ((iStack_300 == 1) && (cRam006c4b90 == '\f')) {
      FUN_006000e0(auStack_310);
    }
  }
  return;
}



================================================================