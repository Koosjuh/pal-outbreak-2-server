FUNCTION FUN_006014c0 @ 0x006014c0  size=192
CALLERS (0): 
CALLEES (1): FUN_005be9a0@0x005be9a0
----------------------------------------------------------------

void FUN_006014c0(undefined4 *param_1)

{
  undefined1 uStack_10;
  
  if ((cRam006c4b90 != '\x06') && (cRam006c4fbb == '!')) {
    uStack_10 = (char)*param_1;
    cRam006c4fbb = '\0';
    if (uStack_10 == '\0') {
      uRam006c4b9f = 0;
      cRam006c4b9e = cRam006c4b9e + '\x01';
    }
    else {
      FUN_005be9a0(0x6c517c);
      uRam006c4b9f = 0;
      cRam006c4b9e = '\x04';
      uRam006c4ba5 = 0x14;
      uRam006c4ba0 = 0;
      uRam006c4ba1 = 0;
    }
  }
  return;
}



================================================================