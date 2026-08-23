FUNCTION FUN_005c2ae0 @ 0x005c2ae0  size=52
CALLERS (3): FUN_005c2f40@0x005c2f40, FUN_005c3490@0x005c3490, FUN_005c3b10@0x005c3b10
CALLEES (1): FUN_005c2a40@0x005c2a40
----------------------------------------------------------------

int FUN_005c2ae0(void)

{
  int iVar1;
  uint extraout_a1_lo;
  
  iVar1 = FUN_005c2a40();
  return iVar1 + (extraout_a1_lo & 0xffff) * 0x3c + 0x16c;
}



================================================================