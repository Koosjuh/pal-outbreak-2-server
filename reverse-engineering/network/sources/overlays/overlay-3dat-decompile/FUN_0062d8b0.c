FUNCTION FUN_0062d8b0 @ 0x0062d8b0  size=160
CALLERS (0): 
CALLEES (2): FUN_005b9110@0x005b9110, FUN_00617a00@0x00617a00
----------------------------------------------------------------

void FUN_0062d8b0(undefined4 *param_1)

{
  undefined1 uStack_10;
  
  if ((cRam006c4b90 != '\x06') && (cRam006c4fbb == '\x05')) {
    uStack_10 = (char)*param_1;
    cRam006c4fbb = '\0';
    if (uStack_10 == '\0') {
      uRam006c4b9f = 0;
      uRam006c4ba0 = 0;
      cRam006c4b9e = cRam006c4b9e + '\x01';
    }
    else {
      FUN_005b9110(0x4c);
      FUN_00617a00(0x6c4b90);
    }
  }
  return;
}



================================================================