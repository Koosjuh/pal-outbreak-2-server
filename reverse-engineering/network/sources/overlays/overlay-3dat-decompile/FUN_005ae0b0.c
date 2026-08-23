FUNCTION FUN_005ae0b0 @ 0x005ae0b0  size=124
CALLERS (0): 
CALLEES (1): FUN_005be9a0@0x005be9a0
----------------------------------------------------------------

void FUN_005ae0b0(undefined4 *param_1)

{
  undefined1 uStack_10;
  
  if (cRam006c4b90 != '\x06') {
    uStack_10 = (char)*param_1;
    if (uStack_10 == '\0') {
      cRam006c4b9e = '\b';
    }
    else {
      cRam006c4b9e = cRam006c4b9e + '\x01';
      FUN_005be9a0(0x6c517c);
    }
  }
  return;
}



================================================================