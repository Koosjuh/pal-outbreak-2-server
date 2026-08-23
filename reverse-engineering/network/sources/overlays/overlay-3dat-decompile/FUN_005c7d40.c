FUNCTION FUN_005c7d40 @ 0x005c7d40  size=176
CALLERS (1): FUN_005be330@0x005be330
CALLEES (3): FUN_005c7e30@0x005c7e30, FUN_005c7ca0@0x005c7ca0, FUN_005bdf90@0x005bdf90
----------------------------------------------------------------

undefined4 FUN_005c7d40(void)

{
  if (cRam006febde != '\0') {
    if (cRam006febdf == '\0') {
      sRam006febe0 = sRam006febe0 + -1;
      if (sRam006febe0 < 0) {
        FUN_005c7ca0();
      }
    }
    else {
      sRam006febe2 = sRam006febe2 + -1;
      if (sRam006febe2 < 0) {
        cRam006febde = 0;
        FUN_005c7e30(0xb);
        FUN_005bdf90(2,0);
        return 1;
      }
    }
  }
  return 0;
}



================================================================