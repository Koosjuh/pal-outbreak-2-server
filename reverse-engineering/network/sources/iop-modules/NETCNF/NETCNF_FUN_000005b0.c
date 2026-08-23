FUNCTION FUN_000005b0 @ 0x000005b0 size=200
CALLERS (0): 
CALLEES (3): FUN_000095cc@0x000095cc, FUN_000095d4@0x000095d4, FUN_000032bc@0x000032bc

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
FUN_000005b0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)

{
  undefined4 uVar1;
  
  FUN_000095d4(DAT_0000afe0);
  uVar1 = FUN_000032bc(param_1,param_2,param_3,param_4,param_5,&DAT_0000afe8,&DAT_0000b0e8,
                       ram0x0000ab48);
  FUN_000095cc(DAT_0000afe0);
  return uVar1;
}


================================================================