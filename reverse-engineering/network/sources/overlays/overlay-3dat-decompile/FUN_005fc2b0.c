FUNCTION FUN_005fc2b0 @ 0x005fc2b0  size=172
CALLERS (0): 
CALLEES (2): FUN_005be9a0@0x005be9a0, FUN_005f8d00@0x005f8d00
----------------------------------------------------------------

void FUN_005fc2b0(undefined4 *param_1)

{
  undefined1 uStack_10;
  
  if ((cRam006c4b90 != '\x06') && (cRam006c4fbb == '\n')) {
    uStack_10 = (char)*param_1;
    if (uStack_10 == '\0') {
      cRam006c4fbb = '\0';
      uRam006c550e = 1;
      uRam006c4b9f = 1;
      uRam006c4ba0 = 0;
    }
    else if (uStack_10 == -1) {
      cRam006c4fbb = '\0';
      FUN_005be9a0(0x6c517c);
      FUN_005f8d00(0x14);
    }
  }
  return;
}



================================================================