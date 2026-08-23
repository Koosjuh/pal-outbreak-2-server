FUNCTION FUN_0062cc60 @ 0x0062cc60  size=192
CALLERS (0): 
CALLEES (3): FUN_005be9a0@0x005be9a0, FUN_005c4330@0x005c4330, FUN_005c4370@0x005c4370
----------------------------------------------------------------

void FUN_0062cc60(undefined4 *param_1)

{
  char cStack_10;
  
  if ((cRam006c4b90 != '\x06') && (cRam006c4fbb == '\x1e')) {
    cStack_10 = (char)*param_1;
    cRam006c4fbb = '\0';
    if (cStack_10 == '\0') {
      uRam006c5c44 = 2;
      FUN_005c4330(0x6c5c48,0x6c5c4a,0x6c5c4c,0x6c5c4f);
      FUN_005c4370(0x6c5c50);
    }
    else {
      uRam006c5c44 = 1;
      FUN_005be9a0(0x6c517c);
    }
  }
  return;
}



================================================================