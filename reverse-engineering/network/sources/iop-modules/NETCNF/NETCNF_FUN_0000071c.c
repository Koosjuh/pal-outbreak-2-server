FUNCTION FUN_0000071c @ 0x0000071c size=132
CALLERS (0): 
CALLEES (3): FUN_000095cc@0x000095cc, FUN_000095d4@0x000095d4, FUN_00003988@0x00003988

undefined4 FUN_0000071c(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  FUN_000095d4(DAT_0000afe0);
  uVar1 = FUN_00003988(param_1,param_2,param_3);
  FUN_000095cc(DAT_0000afe0);
  return uVar1;
}


================================================================