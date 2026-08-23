FUNCTION FUN_00000b9c @ 0x00000b9c size=148
CALLERS (0): 
CALLEES (3): FUN_000095cc@0x000095cc, FUN_000095d4@0x000095d4, FUN_00003f98@0x00003f98

undefined4 FUN_00000b9c(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  
  FUN_000095d4(DAT_0000afe0);
  uVar1 = FUN_00003f98(param_1,param_2,param_3,param_4);
  FUN_000095cc(DAT_0000afe0);
  return uVar1;
}


================================================================