FUNCTION FUN_005fc520 @ 0x005fc520  size=148
CALLERS (0): 
CALLEES (1): FUN_005f8d00@0x005f8d00
----------------------------------------------------------------

void FUN_005fc520(undefined4 *param_1)

{
  undefined1 uStack_10;
  
  if ((cRam006c4b90 != '\x06') && (cRam006c4fbb == '\x0f')) {
    uStack_10 = (char)*param_1;
    if (uStack_10 == '\0') {
      cRam006c4fbb = '\0';
      cRam006c4ba0 = cRam006c4ba0 + '\x01';
    }
    else if (uStack_10 == -1) {
      cRam006c4fbb = '\0';
      FUN_005f8d00(0x48);
    }
  }
  return;
}



================================================================