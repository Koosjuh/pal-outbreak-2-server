FUNCTION FUN_0000070c @ 0x0000070c size=76
CALLERS (1): FUN_00000b9c@0x00000b9c
CALLEES (2): FUN_000022a8@0x000022a8, FUN_000022b0@0x000022b0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0000070c(ushort param_1)

{
  undefined4 local_10 [2];
  
  FUN_000022a8(local_10);
  _DAT_b000002a = _DAT_b000002a & ~param_1;
  FUN_000022b0(local_10[0]);
  return;
}


================================================================