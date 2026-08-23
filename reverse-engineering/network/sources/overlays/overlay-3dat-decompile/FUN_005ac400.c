FUNCTION FUN_005ac400 @ 0x005ac400  size=188
CALLERS (1): FUN_005ac8a0@0x005ac8a0
CALLEES (5): FUN_00606f60@0x00606f60, FUN_00618b60@0x00618b60, FUN_00618c30@0x00618c30, FUN_00605f80@0x00605f80, FUN_00605fa0@0x00605fa0
----------------------------------------------------------------

void FUN_005ac400(void)

{
  long lVar1;
  
  uRam006c4fde = 1;
  if (cRam006c4fab != '\x02') {
    if (cRam006c4fab == '\x01') {
      lVar1 = FUN_00605fa0();
      if (lVar1 < 0) {
        FUN_00618b60();
        FUN_00606f60();
      }
      else if (lVar1 != 0) {
        uRam006c4faa = 0;
        cRam006c4fab = '\0';
        uRam006c4fac = 0;
        uRam006c4fad = 0;
        FUN_00618b60();
      }
    }
    else if (cRam006c4fab == '\0') {
      FUN_00605f80();
      cRam006c4fab = cRam006c4fab + '\x01';
    }
  }
  FUN_00618c30();
  return;
}



================================================================