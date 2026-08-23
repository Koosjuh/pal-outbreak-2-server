FUNCTION FUN_006179e0 @ 0x006179e0  size=28
CALLERS (1): FUN_005aec70@0x005aec70
CALLEES (1): FUN_005aec20@0x005aec20
----------------------------------------------------------------

void FUN_006179e0(undefined1 *param_1,undefined1 param_2)

{
  *param_1 = 8;
  param_1[0xe] = 0;
  param_1[0xf] = 0;
  param_1[0x10] = 0;
  param_1[0x11] = param_2;
  FUN_005aec20();
  return;
}



================================================================