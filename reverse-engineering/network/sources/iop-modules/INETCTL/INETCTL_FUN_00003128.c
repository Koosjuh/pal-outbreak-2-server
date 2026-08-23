FUNCTION FUN_00003128 @ 0x00003128 size=84
CALLERS (0): 
CALLEES (3): FUN_00002f5c@0x00002f5c, FUN_00000148@0x00000148, FUN_00000104@0x00000104

undefined4 FUN_00003128(undefined4 param_1)

{
  undefined4 uVar1;
  
  FUN_00000104();
  uVar1 = FUN_00002f5c(param_1,0);
  FUN_00000148();
  return uVar1;
}


================================================================