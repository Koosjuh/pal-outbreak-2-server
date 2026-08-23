FUNCTION FUN_00000204 @ 0x00000204 size=76
CALLERS (1): FUN_00000c9c@0x00000c9c
CALLEES (1): FUN_00001320@0x00001320

undefined4 FUN_00000204(void)

{
  undefined4 uVar1;
  
  if (DAT_000025c8 == 0) {
    uVar1 = FUN_00001320();
  }
  else {
    uVar1 = 0xffffffff;
    if (DAT_000025c8 == 1) {
      uVar1 = 0;
    }
  }
  return uVar1;
}


================================================================