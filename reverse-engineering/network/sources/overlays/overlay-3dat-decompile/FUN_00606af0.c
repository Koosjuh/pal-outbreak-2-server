FUNCTION FUN_00606af0 @ 0x00606af0  size=392
CALLERS (1): FUN_005ac8a0@0x005ac8a0
CALLEES (7): FUN_00606c80@0x00606c80, thunk_EXT_FUN_001b3720@0x005af360, FUN_00618b60@0x00618b60, FUN_005b14b0@0x005b14b0, FUN_00618c30@0x00618c30, FUN_00606a70@0x00606a70, FUN_005b8cf0@0x005b8cf0
----------------------------------------------------------------

void FUN_00606af0(void)

{
  long lVar1;
  
  switch(cRam006c4b9e) {
  case '\0':
    cRam006c4b9e = cRam006c4b9e + '\x01';
    FUN_00618b60();
    FUN_005b8cf0(0xffffffffffffff9d);
    break;
  case '\x01':
    cRam006c4b9e = cRam006c4b9e + '\x01';
    FUN_00618c30();
    break;
  case '\x02':
    cRam006c4b9e = cRam006c4b9e + '\x01';
    FUN_00618c30();
    break;
  case '\x03':
    if (cRam003c8a80 == '\0') {
      if ((long)cRam0070cd80 == -0x14d) {
        cRam006c4b9e = cRam006c4b9e + '\x01';
      }
      else {
        lVar1 = FUN_00606a70();
        if (lVar1 != 0) {
          if (cRam0070cd80 == -0x11) {
            cRam006c4b9e = cRam006c4b9e + '\x01';
          }
          else {
            FUN_00606c80();
          }
        }
      }
    }
    else {
      func_0x001ee650(uRam0035a6f4);
      func_0x001ee680(0x35a6f4);
      FUN_00606c80();
    }
    FUN_00618c30();
    break;
  case '\x04':
    FUN_00618b60();
    thunk_EXT_FUN_001b3720();
    FUN_005b8cf0(0x50);
    cRam006c4b9e = cRam006c4b9e + '\x01';
    break;
  case '\x05':
    lVar1 = FUN_005b14b0(0x10);
    if (lVar1 != 0) {
      FUN_00606c80();
    }
    FUN_00618c30();
  }
  return;
}



================================================================