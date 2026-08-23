FUNCTION FUN_005adbe0 @ 0x005adbe0  size=156
CALLERS (0): 
CALLEES (2): FUN_005b9110@0x005b9110, FUN_005f74d0@0x005f74d0
----------------------------------------------------------------

void FUN_005adbe0(undefined4 *param_1)

{
  char cStack_10;
  
  if ((cRam006c4b90 != '\x06') && (cRam006c4fbb == '\x05')) {
    cStack_10 = (char)*param_1;
    cRam006c4fbb = '\0';
    if (cStack_10 == '\0') {
      FUN_005f74d0();
    }
    else {
      uRam006c4b9e = 0;
      uRam006c4b9f = 0;
      uRam006c4ba0 = 0;
      uRam006c4ba1 = 0;
      FUN_005b9110(0x4c);
    }
  }
  return;
}



================================================================