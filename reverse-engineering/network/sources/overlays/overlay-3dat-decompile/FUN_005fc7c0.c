FUNCTION FUN_005fc7c0 @ 0x005fc7c0  size=144
CALLERS (0): 
CALLEES (2): FUN_005be9a0@0x005be9a0, FUN_005f8d00@0x005f8d00
----------------------------------------------------------------

void FUN_005fc7c0(undefined4 *param_1)

{
  undefined1 uStack_10;
  
  if ((cRam006c4b90 != '\x06') && (cRam006c4fbb == '\x11')) {
    uStack_10 = (char)*param_1;
    cRam006c4fbb = '\0';
    if (uStack_10 == '\0') {
      cRam006c4ba0 = cRam006c4ba0 + '\x01';
    }
    else {
      FUN_005be9a0(0x6c517c);
      FUN_005f8d00(0x14);
    }
  }
  return;
}



================================================================