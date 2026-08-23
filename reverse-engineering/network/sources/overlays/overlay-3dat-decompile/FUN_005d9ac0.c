FUNCTION FUN_005d9ac0 @ 0x005d9ac0  size=272
CALLERS (1): FUN_005f2280@0x005f2280
CALLEES (2): FUN_005da650@0x005da650, FUN_005cab10@0x005cab10
----------------------------------------------------------------

void FUN_005d9ac0(undefined8 param_1,undefined8 param_2,ulong param_3,ulong param_4,
                 undefined8 param_5,undefined8 param_6,undefined8 param_7,char *param_8)

{
  FUN_005da650(param_3 & 0xffff,param_4 & 0xffff);
  if (*param_8 != '\0') {
    FUN_005cab10(0xd,4,param_1,param_2,param_3,param_4,0xffffffffff000001,param_5);
  }
  FUN_005cab10(0xf,1,param_1,param_2,param_3,param_4,param_6,param_5);
  return;
}



================================================================