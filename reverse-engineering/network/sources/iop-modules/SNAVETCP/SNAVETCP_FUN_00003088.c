FUNCTION FUN_00003088 @ 0x00003088 size=108
CALLERS (1): FUN_0000313c@0x0000313c
CALLEES (1): FUN_00006c88@0x00006c88

undefined * FUN_00003088(void)

{
  short sVar1;
  
  if (DAT_00016526 == 0) {
    sVar1 = FUN_00006c88(&DAT_000164e0,0x5dc,3);
    if (sVar1 != 0) {
      return (undefined *)0x0;
    }
    DAT_00016526 = 1;
  }
  DAT_000164f0 = 0;
  DAT_000164ec = &DAT_000164e0;
  return &DAT_000164e8;
}


================================================================