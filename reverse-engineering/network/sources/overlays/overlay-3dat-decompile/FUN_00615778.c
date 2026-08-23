FUNCTION FUN_00615778 @ 0x00615778  size=96
CALLERS (0): 
CALLEES (2): FUN_00615670@0x00615670, FUN_00616518@0x00616518
----------------------------------------------------------------

long FUN_00615778(void)

{
  long lVar1;
  
  FUN_00616518();
  FUN_00615670();
  lVar1 = func_0x00115c68(0x70d200,0xf,0,0x70d240,0x1000,0x70d240,0x1000,0);
  if (-1 < lVar1) {
    lVar1 = 0;
  }
  return lVar1;
}



================================================================
FUNCTION thunk_FUN_00616b40 @ 0x006157d8  size=8
CALLERS (1): FUN_00615a58@0x00615a58
CALLEES (0): 
----------------------------------------------------------------

undefined4 thunk_FUN_00616b40(int param_1)

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