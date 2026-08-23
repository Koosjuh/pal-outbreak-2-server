FUNCTION FUN_00606fa0 @ 0x00606fa0  size=20
CALLERS (3): FUN_00606fc0@0x00606fc0, FUN_00607260@0x00607260, FUN_00607370@0x00607370
CALLEES (0): 
----------------------------------------------------------------

void FUN_00606fa0(undefined1 *param_1,undefined4 param_2)

{
  *param_1 = 5;
  param_1[1] = 0;
  *(undefined4 *)(param_1 + 8) = param_2;
  return;
}



================================================================