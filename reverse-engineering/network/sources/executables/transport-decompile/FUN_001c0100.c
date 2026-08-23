
char FUN_001c0100(void)

{
  long lVar1;
  
  switch(cRam0035a6b0) {
  case '\0':
    FUN_001c04a0();
    cRam0035a6b0 = cRam0035a6b0 + '\x01';
    break;
  case '\x01':
    lVar1 = FUN_001c0630();
    if (lVar1 != 0) {
      if (lVar1 == 4) {
        cRam0035a6b0 = '\x04';
      }
      else if (lVar1 == 2) {
        FUN_001c00e0(uRam0035ba98);
        cRam0035a6b0 = cRam0035a6b0 + '\x01';
      }
    }
    break;
  case '\x02':
    lVar1 = FUN_001ee360();
    if (lVar1 != 0) {
      cRam0035a6b0 = 4;
      return '\x04';
    }
    break;
  case '\x03':
    lVar1 = FUN_001c2770(0x35a6b3,0x35a6b4);
    if (lVar1 != 0) {
      FUN_001bf580();
      cRam0035a6b0 = '\x05';
    }
  }
  return cRam0035a6b0;
}

