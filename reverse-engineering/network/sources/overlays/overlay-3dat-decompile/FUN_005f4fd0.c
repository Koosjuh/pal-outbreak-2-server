FUNCTION FUN_005f4fd0 @ 0x005f4fd0  size=256
CALLERS (1): FUN_005f54d0@0x005f54d0
CALLEES (0): 
----------------------------------------------------------------

undefined4 FUN_005f4fd0(void)

{
  undefined4 uVar1;
  
  if ((uRam006c4618 & 0x20002) == 0) {
    if (cRam006c462a == 'Q') {
      uVar1 = 1;
      cRam0070a148 = '\x14';
    }
    else if (cRam006c462a == 'N') {
      uVar1 = 5;
      cRam0070a148 = '\x14';
    }
    else if (cRam0070a148 == '\0') {
      if ((uRam006c4610 & 0x20002) == 0) {
        if (cRam006c4628 == 'Q') {
          uVar1 = 1;
          cRam0070a148 = '\x04';
        }
        else if (cRam006c4628 == 'N') {
          uVar1 = 5;
          cRam0070a148 = '\x04';
        }
        else {
          uVar1 = 0;
        }
      }
      else {
        uVar1 = 1;
        cRam0070a148 = '\x04';
      }
    }
    else {
      cRam0070a148 = cRam0070a148 + -1;
      uVar1 = 0;
    }
  }
  else {
    uVar1 = 1;
    cRam0070a148 = '\x14';
  }
  return uVar1;
}



================================================================