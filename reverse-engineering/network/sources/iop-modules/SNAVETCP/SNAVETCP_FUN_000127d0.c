FUNCTION FUN_000127d0 @ 0x000127d0 size=36
CALLERS (1): FUN_0001298c@0x0001298c
CALLEES (1): FUN_00014e58@0x00014e58

uint FUN_000127d0(short param_1)

{
  uint uVar1;
  
  uVar1 = FUN_00014e58((int)param_1);
  return uVar1 & 2;
}


================================================================