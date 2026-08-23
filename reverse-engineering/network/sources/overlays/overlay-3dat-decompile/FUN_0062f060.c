FUNCTION FUN_0062f060 @ 0x0062f060  size=208
CALLERS (0): 
CALLEES (1): FUN_005be9a0@0x005be9a0
----------------------------------------------------------------

void FUN_0062f060(undefined4 *param_1)

{
  undefined1 uStack_10;
  
  if ((cRam006c4b90 != '\x06') && (cRam006c4fbb == '\n')) {
    uStack_10 = (char)*param_1;
    if (uStack_10 == '\0') {
      cRam006c4fbb = '\0';
      uRam006c550e = 1;
      cRam006c4ba0 = cRam006c4ba0 + '\x01';
    }
    else if (uStack_10 == -1) {
      cRam006c4fbb = '\0';
      FUN_005be9a0(0x6c517c);
      cRam006c4ba0 = '\0';
      uRam006c4b9f = 1;
      uRam006c5530 = 0x708;
      uRam006c4ba1 = 0;
    }
  }
  return;
}



================================================================