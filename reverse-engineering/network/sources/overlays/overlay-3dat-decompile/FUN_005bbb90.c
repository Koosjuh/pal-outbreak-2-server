FUNCTION FUN_005bbb90 @ 0x005bbb90  size=136
CALLERS (1): FUN_005bba20@0x005bba20
CALLEES (2): FUN_005bdfe0@0x005bdfe0, FUN_005c50a0@0x005c50a0
----------------------------------------------------------------

void FUN_005bbb90(undefined8 param_1,int param_2)

{
  func_0x00106b60(0x6fc2d8,0,0x310);
  FUN_005c50a0(param_1,0x6fc2d8);
  func_0x001069a8(0x6fc2e8,param_2 + 4,0x300);
  uRam006febe8 = (undefined4)param_1;
  uRam006cbc7e = 0x10;
  uRam006cbc84 = 0;
  FUN_005bdfe0(0xc);
  return;
}



================================================================