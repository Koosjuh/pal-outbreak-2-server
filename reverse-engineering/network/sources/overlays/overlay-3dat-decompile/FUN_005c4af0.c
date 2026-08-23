FUNCTION FUN_005c4af0 @ 0x005c4af0  size=156
CALLERS (1): FUN_005f4be0@0x005f4be0
CALLEES (2): FUN_005c4bd0@0x005c4bd0, FUN_005bdf90@0x005bdf90
----------------------------------------------------------------

void FUN_005c4af0(undefined1 param_1,undefined8 param_2,undefined2 param_3)

{
  undefined8 uVar1;
  
  FUN_005c4bd0();
  func_0x00106b60(0x6fc05a,0,0x128);
  uRam006fc17e = param_1;
  uVar1 = func_0x0010a050(0x6febb8);
  func_0x001069a8(0x6fc06a,0x6febb8,uVar1);
  func_0x0010a4f0(0x6fc07e,param_2,param_3);
  FUN_005bdf90(5,0);
  return;
}



================================================================