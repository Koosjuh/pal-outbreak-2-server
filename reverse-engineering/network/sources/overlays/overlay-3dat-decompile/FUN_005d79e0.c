FUNCTION FUN_005d79e0 @ 0x005d79e0  size=76
CALLERS (1): FUN_005d7090@0x005d7090
CALLEES (2): FUN_005d6ce0@0x005d6ce0, FUN_005d6b40@0x005d6b40
----------------------------------------------------------------

void FUN_005d79e0(undefined8 param_1)

{
  long lVar1;
  
  lVar1 = FUN_005d6b40();
  while (lVar1 != 0) {
    FUN_005d6ce0(lVar1);
    lVar1 = FUN_005d6b40(param_1);
  }
  func_0x001841d0();
  return;
}



================================================================