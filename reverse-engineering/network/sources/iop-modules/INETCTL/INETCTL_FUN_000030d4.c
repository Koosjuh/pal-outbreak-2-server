FUNCTION FUN_000030d4 @ 0x000030d4 size=84
CALLERS (0): 
CALLEES (3): FUN_00002f5c@0x00002f5c, FUN_00000148@0x00000148, FUN_00000104@0x00000104

undefined4 FUN_000030d4(undefined4 param_1)

{
  undefined4 uVar1;
  
  FUN_00000104();
  uVar1 = FUN_00002f5c(param_1,1);
  FUN_00000148();
  return uVar1;
}


================================================================