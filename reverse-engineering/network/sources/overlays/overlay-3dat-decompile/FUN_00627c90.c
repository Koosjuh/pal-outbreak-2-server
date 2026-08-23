FUNCTION FUN_00627c90 @ 0x00627c90  size=168
CALLERS (0): 
CALLEES (1): FUN_005c4420@0x005c4420
----------------------------------------------------------------

void FUN_00627c90(undefined4 *param_1)

{
  char cStack_10;
  
  if ((cRam006c4b90 != '\x06') && (cRam006c4fbb == '$')) {
    cStack_10 = (char)*param_1;
    cRam006c4fbb = '\0';
    if (cStack_10 == '\0') {
      uRam006c5c44 = 2;
      FUN_005c4420(0x6c5c48,0x6c5c4a,0x6c5c4c,0x6c5c4f);
    }
    else {
      uRam006c5c44 = 1;
    }
  }
  return;
}



================================================================