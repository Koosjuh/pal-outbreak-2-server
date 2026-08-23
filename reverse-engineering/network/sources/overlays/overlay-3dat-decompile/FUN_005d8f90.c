FUNCTION FUN_005d8f90 @ 0x005d8f90  size=160
CALLERS (1): FUN_005e7e30@0x005e7e30
CALLEES (2): FUN_005da650@0x005da650, FUN_005cab10@0x005cab10
----------------------------------------------------------------

void FUN_005d8f90(undefined8 param_1,undefined8 param_2,ulong param_3,ulong param_4)

{
  FUN_005da650(param_3 & 0xffff,param_4 & 0xffff);
  FUN_005cab10(5,1,param_1,param_2,param_3,param_4,0xffffffffff000001,0x10);
  return;
}



================================================================