FUNCTION FUN_005fc6b0 @ 0x005fc6b0  size=128
CALLERS (0): 
CALLEES (2): FUN_005f8b50@0x005f8b50, FUN_005f6970@0x005f6970
----------------------------------------------------------------

void FUN_005fc6b0(undefined4 *param_1)

{
  char cStack_10;
  
  if ((cRam006c4b90 != '\x06') && (cRam006c4fbb == '\x13')) {
    cStack_10 = (char)*param_1;
    cRam006c4fbb = '\0';
    if (cStack_10 == '\0') {
      FUN_005f8b50(uRam006c4600);
    }
    else {
      FUN_005f6970(4);
    }
  }
  return;
}



================================================================