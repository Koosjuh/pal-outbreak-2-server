FUNCTION FUN_005d9160 @ 0x005d9160  size=296
CALLERS (1): FUN_005ed6e0@0x005ed6e0
CALLEES (2): FUN_005da650@0x005da650, FUN_005cab10@0x005cab10
----------------------------------------------------------------

void FUN_005d9160(undefined8 param_1,undefined8 param_2,ulong param_3,ulong param_4,
                 undefined8 param_5,undefined8 param_6)

{
  FUN_005da650(param_3 & 0xffff,param_4 & 0xffff);
  func_0x0010a050(param_6);
  FUN_005cab10(7,1,param_1,param_2,param_3,param_4,0xffffffffff000001,0x10);
  return;
}



================================================================