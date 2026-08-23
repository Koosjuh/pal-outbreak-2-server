FUNCTION FUN_0062bb20 @ 0x0062bb20  size=156
CALLERS (1): FUN_0062ba70@0x0062ba70
CALLEES (4): FUN_00618b60@0x00618b60, FUN_0062cd20@0x0062cd20, FUN_005af400@0x005af400, FUN_00629d00@0x00629d00
----------------------------------------------------------------

undefined8 FUN_0062bb20(int param_1,undefined8 param_2)

{
  char *pcVar1;
  
  func_0x00106b60(param_1 + 0x10b8,0,0x20a);
  func_0x00106b60(param_1 + 0x12c2,0,0x19e);
  FUN_005af400();
  FUN_00618b60();
  FUN_0062cd20(param_2,0);
  FUN_00629d00(param_2,3);
  FUN_00629d00(param_2,4);
  pcVar1 = (char *)param_2;
  pcVar1[0x10] = '\0';
  pcVar1[0x11] = '\0';
  pcVar1[0x12] = '\0';
  *pcVar1 = *pcVar1 + '\x01';
  return 0;
}



================================================================