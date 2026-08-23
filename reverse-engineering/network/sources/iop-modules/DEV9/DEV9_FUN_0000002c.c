FUNCTION FUN_0000002c @ 0x0000002c size=80
CALLERS (1): FUN_00000b9c@0x00000b9c
CALLEES (2): FUN_000017d0@0x000017d0, FUN_00000fc0@0x00000fc0

void FUN_0000002c(void)

{
  if (DAT_000025c8 == 0) {
    FUN_00000fc0();
  }
  else if (DAT_000025c8 == 1) {
    FUN_000017d0();
  }
  return;
}


================================================================