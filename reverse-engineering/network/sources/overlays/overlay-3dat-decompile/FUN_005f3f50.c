FUNCTION FUN_005f3f50 @ 0x005f3f50  size=156
CALLERS (1): FUN_005f3de0@0x005f3de0
CALLEES (5): FUN_005f47a0@0x005f47a0, FUN_0062ff30@0x0062ff30, FUN_005f4770@0x005f4770, FUN_00637970@0x00637970, FUN_00621f10@0x00621f10
----------------------------------------------------------------

void FUN_005f3f50(undefined8 param_1)

{
  if (iRam00701f30 == 1) {
    iRam00701f28 = iRam00701f28 + 1;
    if (iRam00701f28 == 0x1a5e0) {
      FUN_005f47a0();
    }
    if (iRam00701f28 == 0x1a5ea) {
      FUN_005f4770();
    }
  }
  FUN_00637970();
  FUN_0062ff30();
  FUN_00621f10(param_1);
  return;
}



================================================================