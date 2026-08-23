FUNCTION FUN_0062cba0 @ 0x0062cba0  size=188
CALLERS (0): 
CALLEES (1): FUN_005be9a0@0x005be9a0
----------------------------------------------------------------

void FUN_0062cba0(undefined4 *param_1)

{
  undefined1 uStack_10;
  
  if ((cRam006c4b90 != '\x06') && (cRam006c4fbb == '\x1f')) {
    uStack_10 = (char)*param_1;
    cRam006c4fbb = '\0';
    if (uStack_10 == '\0') {
      uRam006c5c44 = 2;
      uRam006c45f8 = (undefined1)uRam006c5c48;
      uRam006c45fc = (undefined1)uRam006c5c4a;
      uRam006c4600 = (undefined1)uRam006c5c4c;
    }
    else {
      uRam006c5c44 = 1;
      FUN_005be9a0(0x6c517c);
    }
  }
  return;
}



================================================================