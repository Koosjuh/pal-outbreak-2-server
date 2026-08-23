FUNCTION FUN_005b0950 @ 0x005b0950  size=88
CALLERS (2): FUN_005f84c0@0x005f84c0, FUN_005affb0@0x005affb0
CALLEES (1): FUN_005bf980@0x005bf980
----------------------------------------------------------------

void FUN_005b0950(undefined1 param_1,undefined8 param_2)

{
  ushort *puVar1;
  
  FUN_005bf980(param_1,2,param_2);
  puVar1 = (ushort *)param_2;
  if (9999 < *puVar1) {
    *puVar1 = 9999;
  }
  if (9999 < puVar1[1]) {
    puVar1[1] = 9999;
  }
  return;
}



================================================================