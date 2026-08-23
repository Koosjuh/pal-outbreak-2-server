FUNCTION FUN_005f4ed0 @ 0x005f4ed0  size=256
CALLERS (1): FUN_005f54d0@0x005f54d0
CALLEES (0): 
----------------------------------------------------------------

undefined4 FUN_005f4ed0(void)

{
  undefined4 uVar1;
  
  if ((uRam006c4618 & 0x10001) == 0) {
    if (cRam006c462a == 'R') {
      uVar1 = 1;
      cRam0070a140 = '\x14';
    }
    else if (cRam006c462a == 'K') {
      uVar1 = 5;
      cRam0070a140 = '\x14';
    }
    else if (cRam0070a140 == '\0') {
      if ((uRam006c4610 & 0x10001) == 0) {
        if (cRam006c4628 == 'R') {
          uVar1 = 1;
          cRam0070a140 = '\x04';
        }
        else if (cRam006c4628 == 'K') {
          uVar1 = 5;
          cRam0070a140 = '\x04';
        }
        else {
          uVar1 = 0;
        }
      }
      else {
        uVar1 = 1;
        cRam0070a140 = '\x04';
      }
    }
    else {
      cRam0070a140 = cRam0070a140 + -1;
      uVar1 = 0;
    }
  }
  else {
    uVar1 = 1;
    cRam0070a140 = '\x14';
  }
  return uVar1;
}



================================================================