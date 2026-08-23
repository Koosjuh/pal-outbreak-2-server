FUNCTION FUN_005ac4c0 @ 0x005ac4c0  size=324
CALLERS (1): FUN_005ac8a0@0x005ac8a0
CALLEES (3): FUN_005af2e0@0x005af2e0, FUN_005af2c0@0x005af2c0, FUN_005af1e0@0x005af1e0
----------------------------------------------------------------

void FUN_005ac4c0(void)

{
  if (cRam006c4fab != '\x02') {
    if (cRam006c4fab != '\x01') {
      if (cRam006c4fab != '\0') goto LAB_005ac5a0;
      if (cRam00874f35 != '\0') {
        uRam006c4faa = 1;
        cRam006c4fab = 0;
        return;
      }
      cRam006c4fab = '\x01';
      sRam006c4ba6 = 10;
    }
    sRam006c4ba6 = sRam006c4ba6 + -1;
    if (-1 < sRam006c4ba6) goto LAB_005ac5a0;
    cRam006c4fab = cRam006c4fab + '\x01';
    sRam006c4ba6 = 0;
  }
  if ((uRam003434a0 & 0x10) == 0) {
    if ((uRam003434a0 & 0x200) != 0) {
      uRam00874f33 = 0;
      uRam006c4faa = 1;
      cRam006c4fab = '\0';
    }
  }
  else {
    uRam00874f33 = 1;
    uRam006c4faa = 1;
    cRam006c4fab = '\0';
  }
LAB_005ac5a0:
  FUN_005af2e0(0x14);
  FUN_005af2c0(0);
  FUN_005af1e0(0xfa,0xbf,2,0x6387e0);
  FUN_005af1e0(0xff,0xed,2,0x638800);
  FUN_005af1e0(0x136,0x11b,2,0x638820);
  return;
}



================================================================