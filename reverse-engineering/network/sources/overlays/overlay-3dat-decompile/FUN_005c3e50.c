FUNCTION FUN_005c3e50 @ 0x005c3e50  size=24
CALLERS (7): FUN_005c1770@0x005c1770, FUN_005c7320@0x005c7320, FUN_005bf470@0x005bf470, FUN_005c75d0@0x005c75d0, FUN_005c0ff0@0x005c0ff0, FUN_005c14a0@0x005c14a0, FUN_005c7020@0x005c7020
CALLEES (0): 
----------------------------------------------------------------

void FUN_005c3e50(long param_1,undefined4 param_2,undefined4 *param_3)

{
  if (-1 < param_1) {
    *param_3 = (int)param_1;
    param_3[1] = param_2;
  }
  return;
}



================================================================