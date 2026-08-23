FUNCTION FUN_000000c8 @ 0x000000c8 size=80
CALLERS (2): FUN_00001810@0x00001810, FUN_00000c9c@0x00000c9c
CALLEES (2): FUN_00001164@0x00001164, FUN_000017e8@0x000017e8

undefined4 FUN_000000c8(void)

{
  undefined4 uVar1;
  
  if (DAT_000025c8 == 0) {
    uVar1 = FUN_00001164();
  }
  else {
    uVar1 = 0xffffffff;
    if (DAT_000025c8 == 1) {
      uVar1 = FUN_000017e8();
    }
  }
  return uVar1;
}


================================================================