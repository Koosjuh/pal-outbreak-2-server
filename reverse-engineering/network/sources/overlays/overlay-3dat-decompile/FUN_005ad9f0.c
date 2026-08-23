FUNCTION FUN_005ad9f0 @ 0x005ad9f0  size=160
CALLERS (0): 
CALLEES (2): FUN_005f74d0@0x005f74d0, FUN_005be9a0@0x005be9a0
----------------------------------------------------------------

void FUN_005ad9f0(undefined4 *param_1)

{
  char cStack_10;
  
  if ((cRam006c4b90 != '\x06') && (cRam006c4fbb == '\x01')) {
    cStack_10 = (char)*param_1;
    cRam006c4fbb = '\0';
    if (cStack_10 == '\0') {
      FUN_005f74d0();
    }
    else {
      uRam006c4b9f = 6;
      uRam006c4ba0 = 0;
      uRam006c4ba1 = 0;
      uRam006c4ba2 = 0;
      FUN_005be9a0(0x6c517c);
    }
  }
  return;
}



================================================================