FUNCTION FUN_00001950 @ 0x00001950 size=68
CALLERS (1): FUN_00000730@0x00000730
CALLEES (1): FUN_000081ac@0x000081ac

undefined4 FUN_00001950(undefined4 param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0xffffffff;
  if (DAT_0000d970 != 0) {
    uVar1 = FUN_000081ac(DAT_0000d974,param_1);
  }
  return uVar1;
}


================================================================