FUNCTION FUN_005d9940 @ 0x005d9940  size=384
CALLERS (1): FUN_005f21f0@0x005f21f0
CALLEES (2): FUN_005da650@0x005da650, FUN_005cab10@0x005cab10
----------------------------------------------------------------

void FUN_005d9940(undefined8 param_1,undefined8 param_2,ulong param_3,ulong param_4,
                 undefined8 param_5,undefined8 param_6,uint param_7,undefined8 param_8,char *param_9
                 )

{
  FUN_005da650(param_3 & 0xffff,param_4 & 0xffff);
  if (*param_9 != '\0') {
    FUN_005cab10(0xd,4,param_1,param_2,param_3,param_4,0xffffffffff000001,param_5);
  }
  param_7 = param_7 & 0xff;
  FUN_005cab10(0x10,1,((uint)param_1 & 0xffff) + param_7 & 0xffff,
               ((uint)param_2 & 0xffff) + param_7 & 0xffff,
               ((uint)param_3 & 0xffff) - param_7 & 0xffff,
               ((uint)param_4 & 0xffff) - param_7 & 0xffff,param_6,param_5);
  FUN_005cab10(0x10,1,param_1,param_2,param_3,param_4,param_8,param_5);
  return;
}



================================================================