FUNCTION FUN_000126d4 @ 0x000126d4 size=36
CALLERS (1): FUN_00012ae8@0x00012ae8
CALLEES (1): FUN_00014e58@0x00014e58

uint FUN_000126d4(short param_1)

{
  uint uVar1;
  
  uVar1 = FUN_00014e58((int)param_1);
  return uVar1 & 4;
}


================================================================