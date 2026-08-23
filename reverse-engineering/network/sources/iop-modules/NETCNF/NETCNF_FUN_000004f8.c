FUNCTION FUN_000004f8 @ 0x000004f8 size=184
CALLERS (0): 
CALLEES (3): FUN_000095cc@0x000095cc, FUN_000095d4@0x000095d4, FUN_000027e4@0x000027e4

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_000004f8(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  
  FUN_000095d4(DAT_0000afe0);
  uVar1 = FUN_000027e4(param_1,param_2,param_3,param_4,&DAT_0000afe8,&DAT_0000b0e8,ram0x0000ab48);
  FUN_000095cc(DAT_0000afe0);
  return uVar1;
}


================================================================