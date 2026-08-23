FUNCTION FUN_00601690 @ 0x00601690  size=104
CALLERS (0): 
CALLEES (1): FUN_005c2370@0x005c2370
----------------------------------------------------------------

void FUN_00601690(undefined4 *param_1)

{
  undefined1 uStack_10;
  
  if (cRam006c4b90 != '\x06') {
    uStack_10 = (char)*param_1;
    if (uStack_10 == '\0') {
      FUN_005c2370(0x6c0602);
    }
    else {
      uRam006c0602 = 0;
    }
  }
  return;
}



================================================================