FUNCTION FUN_005c7a00 @ 0x005c7a00  size=220
CALLERS (2): FUN_00606fc0@0x00606fc0, FUN_00607370@0x00607370
CALLEES (1): FUN_005c7ae0@0x005c7ae0
----------------------------------------------------------------

undefined8 FUN_005c7a00(void)

{
  long lVar1;
  undefined8 uVar2;
  
  if (cRam00700fd8 == '\x02') {
    uVar2 = 1;
  }
  else {
    if (cRam00700fd8 == '\x01') {
      lVar1 = FUN_005c7ae0((uRam0086f800 - 1) * 0x260 + 0x365e20);
      if (lVar1 == -1) {
        return 0xffffffffffffffff;
      }
      if (lVar1 == 1) {
        cRam00700fd8 = cRam00700fd8 + '\x01';
      }
    }
    else {
      if (cRam00700fd8 != '\0') {
        return 0;
      }
      cRam00700fd8 = '\x01';
      uRam00700fd0 = 0;
    }
    uVar2 = 0;
  }
  return uVar2;
}



================================================================