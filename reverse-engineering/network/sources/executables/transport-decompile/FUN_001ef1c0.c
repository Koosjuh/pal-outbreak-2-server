
short FUN_001ef1c0(undefined4 *param_1)

{
  short sVar1;
  
  if (cRam0037a278 == '\0') {
    sVar1 = FUN_001f0d90();
    if (sVar1 != 0) {
      cRam0037a278 = '\x01';
      uRam0037a280 = *param_1;
    }
  }
  else {
    sVar1 = 1;
    *param_1 = uRam0037a280;
  }
  return sVar1;
}

