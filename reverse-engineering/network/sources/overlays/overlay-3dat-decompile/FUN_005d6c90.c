FUNCTION FUN_005d6c90 @ 0x005d6c90  size=80
CALLERS (2): FUN_005d8340@0x005d8340, FUN_005d7760@0x005d7760
CALLEES (1): FUN_005d6b80@0x005d6b80
----------------------------------------------------------------

void FUN_005d6c90(undefined8 param_1)

{
  FUN_005d6b80(iRam00701068 + 0x4f370,param_1);
  func_0x00106b60(*(undefined4 *)((int)param_1 + 0x10c),0,0x8000);
  *(undefined4 *)((int)param_1 + 0x110) = 0;
  return;
}



================================================================