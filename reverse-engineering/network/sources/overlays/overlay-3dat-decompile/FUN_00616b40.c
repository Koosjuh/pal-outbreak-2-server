FUNCTION FUN_00616b40 @ 0x00616b40  size=140
CALLERS (2): FUN_006162d8@0x006162d8, FUN_006157e0@0x006157e0
CALLEES (1): FUN_00616a58@0x00616a58
----------------------------------------------------------------

undefined4 FUN_00616b40(int param_1)

{
  undefined4 uVar1;
  long lVar2;
  
  if (DAT_00654208 < 0) {
    uVar1 = 0xffffffff;
  }
  else if (param_1 == 0) {
    func_0x001128e0(DAT_00654208);
    FUN_00616a58();
    uVar1 = 0;
  }
  else {
    uVar1 = 0xffffff9b;
    if (param_1 == 1) {
      lVar2 = func_0x001128f0(DAT_00654208);
      uVar1 = 1;
      if (lVar2 != -1) {
        FUN_00616a58();
        uVar1 = 0;
      }
    }
  }
  return uVar1;
}



================================================================