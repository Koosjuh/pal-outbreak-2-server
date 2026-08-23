FUNCTION FUN_005d8b90 @ 0x005d8b90  size=244
CALLERS (1): FUN_005eca10@0x005eca10
CALLEES (2): FUN_005da650@0x005da650, FUN_005cab10@0x005cab10
----------------------------------------------------------------

void FUN_005d8b90(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                 ulong param_5,ulong param_6,undefined8 param_7)

{
  long lVar1;
  
  lVar1 = func_0x00109d70(param_7,0x643380);
  if (lVar1 != 0) {
    lVar1 = func_0x00109d70(param_7,0x643388);
    if (lVar1 != 0) {
      FUN_005da650(param_5 & 0xffff,param_6 & 0xffff);
      FUN_005cab10(1,1,param_1,param_2,param_5,param_6,param_3,param_4);
    }
  }
  return;
}



================================================================