FUNCTION FUN_000027e4 @ 0x000027e4 size=56
CALLERS (1): FUN_00010824@0x00010824
CALLEES (3): FUN_00010ad4@0x00010ad4, FUN_00010adc@0x00010adc, FUN_0000fd28@0x0000fd28

undefined4 FUN_000027e4(void)

{
  int iVar1;
  
  iVar1 = FUN_00010adc(0);
  if (iVar1 != 0) {
    FUN_00010ad4(0);
  }
  FUN_0000fd28();
  return 0;
}


================================================================