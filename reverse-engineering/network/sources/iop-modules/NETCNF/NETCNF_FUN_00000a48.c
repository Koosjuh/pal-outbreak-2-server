FUNCTION FUN_00000a48 @ 0x00000a48 size=100
CALLERS (0): 
CALLEES (3): FUN_000016e8@0x000016e8, FUN_000095cc@0x000095cc, FUN_000095d4@0x000095d4

undefined4 FUN_00000a48(undefined4 param_1)

{
  undefined4 uVar1;
  
  FUN_000095d4(DAT_0000afe0);
  uVar1 = FUN_000016e8(param_1);
  FUN_000095cc(DAT_0000afe0);
  return uVar1;
}


================================================================