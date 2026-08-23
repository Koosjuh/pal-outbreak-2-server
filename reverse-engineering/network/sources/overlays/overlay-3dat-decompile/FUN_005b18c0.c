FUNCTION FUN_005b18c0 @ 0x005b18c0  size=308
CALLERS (1): FUN_005f4b80@0x005f4b80
CALLEES (0): 
----------------------------------------------------------------

undefined4 FUN_005b18c0(void)

{
  undefined4 uVar1;
  
  if ((uRam006c4618 & 0x20) == 0) {
    if (((bRam006c462a < 4) || ((0x39 < bRam006c462a && (bRam006c462a < 0x49)))) ||
       (((0x52 < bRam006c462a && (bRam006c462a < 0x87)) || (0x8b < bRam006c462a)))) {
      uVar1 = 0;
    }
    else {
      if (bRam006c462a != 0x8b) {
        if (bRam006c462a == 0x8a) {
          return 0;
        }
        if (((((bRam006c462a != 0x88) && (bRam006c462a != 0x52)) && (bRam006c462a != 0x51)) &&
            ((((bRam006c462a != 0x50 && (bRam006c462a != 0x4f)) &&
              ((bRam006c462a != 0x4e && ((bRam006c462a != 0x4d && (bRam006c462a != 0x4c)))))) &&
             (bRam006c462a != 0x4b)))) &&
           (((((bRam006c462a != 0x4a && (bRam006c462a != 0x49)) && (bRam006c462a != 0x39)) &&
             ((bRam006c462a != 0x2b && (bRam006c462a != 0x2a)))) &&
            ((bRam006c462a != 0x29 && (bRam006c462a != 0x28)))))) {
          return 1;
        }
      }
      uVar1 = 0;
    }
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}



================================================================