
undefined4 FUN_001c0d60(void)

{
  undefined4 uVar1;
  
  if (cRam0035bec0 == '\x01') {
    uVar1 = 0xffffffff;
    if (sRam0035cc18 == 1) {
      uVar1 = 0;
      sRam0035cc18 = 0;
    }
  }
  else if (sRam0035cc18 == 0) {
    uVar1 = 0;
    sRam0035cc18 = 1;
  }
  else {
    uVar1 = 0xffffffff;
  }
  return uVar1;
}

