FUNCTION FUN_00618090 @ 0x00618090  size=148
CALLERS (0): 
CALLEES (1): FUN_005be9a0@0x005be9a0
----------------------------------------------------------------

void FUN_00618090(undefined4 *param_1)

{
  undefined1 uStack_10;
  
  if ((cRam006c4b90 != '\x06') && (cRam006c4fbb == '\x1a')) {
    uStack_10 = (char)*param_1;
    cRam006c4fbb = '\0';
    if (uStack_10 == '\0') {
      cRam006c4b9f = cRam006c4b9f + '\x01';
    }
    else {
      uRam006c5521 = 1;
      FUN_005be9a0(0x6c517c);
    }
  }
  return;
}



================================================================