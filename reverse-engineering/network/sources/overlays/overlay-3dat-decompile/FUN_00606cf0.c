FUNCTION FUN_00606cf0 @ 0x00606cf0  size=168
CALLERS (1): FUN_005ac8a0@0x005ac8a0
CALLEES (7): FUN_00606fc0@0x00606fc0, FUN_00607260@0x00607260, FUN_006076c0@0x006076c0, FUN_00618c30@0x00618c30, FUN_00607370@0x00607370, FUN_006075e0@0x006075e0, FUN_00607340@0x00607340
----------------------------------------------------------------

void FUN_00606cf0(void)

{
  switch(uRam0070cdb8) {
  case 0:
    FUN_00606fc0();
    break;
  case 1:
    FUN_00607260();
    break;
  case 2:
    FUN_00607340();
    break;
  case 3:
    FUN_00607370();
    break;
  case 4:
    FUN_006075e0();
    break;
  case 5:
    FUN_006076c0(0x70cdb8);
  }
  FUN_00618c30();
  return;
}



================================================================