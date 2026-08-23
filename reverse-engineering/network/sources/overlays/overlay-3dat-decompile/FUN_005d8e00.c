FUNCTION FUN_005d8e00 @ 0x005d8e00  size=160
CALLERS (1): FUN_005ed6e0@0x005ed6e0
CALLEES (2): FUN_005da650@0x005da650, FUN_005cab10@0x005cab10
----------------------------------------------------------------

void FUN_005d8e00(undefined8 param_1,undefined8 param_2,ulong param_3,ulong param_4)

{
  FUN_005da650(param_3 & 0xffff,param_4 & 0xffff);
  FUN_005cab10(4,1,param_1,param_2,param_3,param_4,0xffffffffff000001,0x10);
  return;
}



================================================================