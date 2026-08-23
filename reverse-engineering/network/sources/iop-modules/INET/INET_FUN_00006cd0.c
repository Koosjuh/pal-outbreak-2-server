FUNCTION FUN_00006cd0 @ 0x00006cd0 size=68
CALLERS (0): 
CALLEES (2): FUN_00017ad8@0x00017ad8, FUN_0000da44@0x0000da44

void FUN_00006cd0(void)

{
  if (DAT_0001b6f8 != 0) {
    DAT_0001b6f8 = 0;
    FUN_0000da44(FUN_00006c2c);
  }
  DAT_0001b6f4 = FUN_00017ad8(FUN_00006cd0,0,100);
  return;
}


================================================================