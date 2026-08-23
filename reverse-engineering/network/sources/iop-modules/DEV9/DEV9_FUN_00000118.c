FUNCTION FUN_00000118 @ 0x00000118 size=80
CALLERS (1): FUN_00000c9c@0x00000c9c
CALLEES (2): FUN_00001810@0x00001810, FUN_00001240@0x00001240

undefined4 FUN_00000118(void)

{
  undefined4 uVar1;
  
  if (DAT_000025c8 == 0) {
    uVar1 = FUN_00001240();
  }
  else {
    uVar1 = 0xffffffff;
    if (DAT_000025c8 == 1) {
      uVar1 = FUN_00001810();
    }
  }
  return uVar1;
}


================================================================