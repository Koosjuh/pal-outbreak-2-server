FUNCTION FUN_005adcd0 @ 0x005adcd0  size=172
CALLERS (1): FUN_005f4480@0x005f4480
CALLEES (1): FUN_005fa820@0x005fa820
----------------------------------------------------------------

long FUN_005adcd0(int param_1)

{
  long lVar1;
  
  if (param_1 == 2) {
    if (cRam006c4b99 == '\0') {
      lVar1 = (long)cRam006c4b98;
    }
    else {
      lVar1 = 0;
    }
  }
  else if (param_1 == 1) {
    lVar1 = 0;
    if (cRam006c4b99 != '\0') {
      lVar1 = (long)sRam006c4b9c;
    }
  }
  else if (param_1 == 0) {
    if (cRam006c4b99 == '\0') {
      lVar1 = (long)sRam006c4b9c;
    }
    else {
      lVar1 = FUN_005fa820(sRam006c4b9c);
      if (lVar1 == 999) {
        lVar1 = 0;
      }
    }
  }
  else {
    lVar1 = 0;
  }
  return lVar1;
}



================================================================