FUNCTION FUN_000006c4 @ 0x000006c4 size=72
CALLERS (0): 
CALLEES (2): FUN_000022a8@0x000022a8, FUN_000022b0@0x000022b0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_000006c4(ushort param_1)

{
  undefined4 local_10 [2];
  
  FUN_000022a8(local_10);
  _DAT_b000002a = _DAT_b000002a | param_1;
  FUN_000022b0(local_10[0]);
  return;
}


================================================================