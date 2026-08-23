FUNCTION FUN_006063c0 @ 0x006063c0  size=248
CALLERS (1): FUN_005ac8a0@0x005ac8a0
CALLEES (8): thunk_FUN_005f4480@0x006069a0, FUN_00606720@0x00606720, FUN_00606520@0x00606520, FUN_00606980@0x00606980, FUN_00606610@0x00606610, FUN_00606780@0x00606780, FUN_006069b0@0x006069b0, FUN_006064c0@0x006064c0
----------------------------------------------------------------

undefined4 FUN_006063c0(void)

{
  undefined4 uVar1;
  
  if (sRam0070cdc8 == 99) {
    FUN_006069b0();
    uVar1 = 0;
  }
  else if (sRam0070cdc8 == 6) {
    thunk_FUN_005f4480();
    uVar1 = 1;
  }
  else {
    if (sRam0070cdc8 == 5) {
      FUN_00606980();
    }
    else if (sRam0070cdc8 == 4) {
      FUN_00606780();
    }
    else if (sRam0070cdc8 == 3) {
      FUN_00606720();
    }
    else if (sRam0070cdc8 == 2) {
      FUN_00606610();
    }
    else if (sRam0070cdc8 == 1) {
      FUN_00606520();
    }
    else {
      if (sRam0070cdc8 != 0) {
        return 0;
      }
      FUN_006064c0();
    }
    uVar1 = 0;
  }
  return uVar1;
}



================================================================