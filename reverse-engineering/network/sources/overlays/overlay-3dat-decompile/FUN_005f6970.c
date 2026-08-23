FUNCTION FUN_005f6970 @ 0x005f6970  size=164
CALLERS (13): FUN_005fc6b0@0x005fc6b0, FUN_005b2e40@0x005b2e40, FUN_005fc730@0x005fc730, FUN_005b2bc0@0x005b2bc0, FUN_005b1a30@0x005b1a30, FUN_005aedc0@0x005aedc0, FUN_005b6900@0x005b6900, FUN_005f8060@0x005f8060, FUN_005b2260@0x005b2260, FUN_005b6070@0x005b6070, FUN_00617a50@0x00617a50, FUN_0062ed30@0x0062ed30, ...
CALLEES (4): FUN_00637180@0x00637180, FUN_00606de0@0x00606de0, FUN_00606da0@0x00606da0, FUN_005b1d10@0x005b1d10
----------------------------------------------------------------

void FUN_005f6970(char param_1)

{
  uRam006c4b9e = 0;
  uRam006c4b9f = 0;
  uRam006c4b90 = 6;
  uRam006c50f8 = 0xffff;
  uRam006c4ba1 = 0;
  uRam006c4ba2 = 0;
  cRam006c4ba0 = param_1;
  cRam006c550b = param_1;
  FUN_00637180();
  FUN_005b1d10(0x6c4b90);
  if (param_1 == '\a') {
    uRam00874f36 = 1;
    FUN_00606de0();
  }
  else {
    FUN_00606da0();
  }
  return;
}



================================================================