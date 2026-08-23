FUNCTION FUN_005fc610 @ 0x005fc610  size=148
CALLERS (0): 
CALLEES (2): FUN_005f7610@0x005f7610, FUN_005b9110@0x005b9110
----------------------------------------------------------------

void FUN_005fc610(undefined4 *param_1)

{
  char cStack_10;
  
  if ((cRam006c4b90 != '\x06') && (cRam006c4fbb == '\x12')) {
    cStack_10 = (char)*param_1;
    cRam006c4fbb = '\0';
    if (cStack_10 == '\0') {
      FUN_005f7610();
    }
    else {
      uRam006c4b9f = 0;
      uRam006c4ba0 = 0;
      uRam006c4ba1 = 0;
      FUN_005b9110(0x4c);
    }
  }
  return;
}



================================================================