FUNCTION FUN_005b67b0 @ 0x005b67b0  size=164
CALLERS (0): 
CALLEES (2): FUN_005bdea0@0x005bdea0, FUN_005be9a0@0x005be9a0
----------------------------------------------------------------

void FUN_005b67b0(undefined4 *param_1)

{
  undefined1 uStack_10;
  
  if (cRam006c4b90 != '\x06') {
    uStack_10 = (char)*param_1;
    if (uStack_10 == '\0') {
      uRam006c4ba0 = 0;
      cRam006c4b9f = cRam006c4b9f + '\x01';
      FUN_005bdea0(0x6c9c28);
    }
    else {
      FUN_005be9a0(0x6c517c);
      uRam006c4ba0 = 0;
      cRam006c4b9f = cRam006c4b9f + '\x01';
    }
  }
  return;
}



================================================================