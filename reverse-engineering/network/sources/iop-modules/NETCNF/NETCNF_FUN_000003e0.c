FUNCTION FUN_000003e0 @ 0x000003e0 size=132
CALLERS (0): 
CALLEES (3): FUN_000095cc@0x000095cc, FUN_000095d4@0x000095d4, FUN_00002280@0x00002280

undefined4 FUN_000003e0(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  FUN_000095d4(DAT_0000afe0);
  uVar1 = FUN_00002280(param_1,param_2,param_3);
  FUN_000095cc(DAT_0000afe0);
  return uVar1;
}


================================================================