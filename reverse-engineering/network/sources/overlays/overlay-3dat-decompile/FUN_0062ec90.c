FUNCTION FUN_0062ec90 @ 0x0062ec90  size=156
CALLERS (0): 
CALLEES (1): FUN_005be9a0@0x005be9a0
----------------------------------------------------------------

void FUN_0062ec90(undefined4 *param_1)

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
      uRam006c4ba1 = 0;
      cRam006c4ba0 = '\x05';
    }
  }
  return;
}



================================================================