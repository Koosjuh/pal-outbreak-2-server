FUNCTION FUN_005d9350 @ 0x005d9350  size=148
CALLERS (2): FUN_005f2b10@0x005f2b10, FUN_005ee010@0x005ee010
CALLEES (2): FUN_005da650@0x005da650, FUN_005cab10@0x005cab10
----------------------------------------------------------------

void FUN_005d9350(undefined8 param_1,undefined8 param_2,ulong param_3,ulong param_4)

{
  FUN_005da650(param_3 & 0xffff,param_4 & 0xffff);
  FUN_005cab10(8,0x1e,param_1,param_2,param_3,param_4,0xffffffffff000001,0x10);
  return;
}



================================================================