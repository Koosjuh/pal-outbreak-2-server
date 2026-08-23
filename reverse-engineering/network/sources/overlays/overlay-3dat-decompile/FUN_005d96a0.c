FUNCTION FUN_005d96a0 @ 0x005d96a0  size=232
CALLERS (1): FUN_005ee220@0x005ee220
CALLEES (3): FUN_005da730@0x005da730, FUN_005da650@0x005da650, FUN_005cab10@0x005cab10
----------------------------------------------------------------

void FUN_005d96a0(undefined8 param_1,undefined8 param_2,ulong param_3,ulong param_4)

{
  long lVar1;
  
  if (((0 < (int)(((uint)param_3 & 0xffff) - ((uint)param_1 & 0xffff))) &&
      (0 < (int)(((uint)param_4 & 0xffff) - ((uint)param_2 & 0xffff)))) &&
     (lVar1 = FUN_005da730(), lVar1 == 0)) {
    FUN_005da650(param_3 & 0xffff,param_4 & 0xffff);
    FUN_005cab10(0xd,2,param_1,param_2,param_3,param_4,0xffffffffff000001,0x10);
  }
  return;
}



================================================================