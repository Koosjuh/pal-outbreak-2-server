FUNCTION FUN_00600ff0 @ 0x00600ff0  size=112
CALLERS (0): 
CALLEES (1): FUN_005c0fd0@0x005c0fd0
----------------------------------------------------------------

void FUN_00600ff0(undefined4 *param_1)

{
  undefined1 uStack_10;
  
  if (cRam006c4b90 != '\x06') {
    uStack_10 = (char)*param_1;
    if (uStack_10 == '\0') {
      FUN_005c0fd0(uRam006c4600,0x6c5510);
    }
    else {
      uRam006c5510 = 0;
    }
  }
  return;
}



================================================================