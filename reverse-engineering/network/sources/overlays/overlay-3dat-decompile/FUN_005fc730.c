FUNCTION FUN_005fc730 @ 0x005fc730  size=132
CALLERS (0): 
CALLEES (1): FUN_005f6970@0x005f6970
----------------------------------------------------------------

void FUN_005fc730(undefined4 *param_1)

{
  undefined1 uStack_10;
  
  if ((cRam006c4b90 != '\x06') && (cRam006c4fbb == '\x14')) {
    uStack_10 = (char)*param_1;
    cRam006c4fbb = '\0';
    if (uStack_10 == '\0') {
      cRam006c4ba0 = cRam006c4ba0 + '\x01';
    }
    else {
      FUN_005f6970(4);
    }
  }
  return;
}



================================================================