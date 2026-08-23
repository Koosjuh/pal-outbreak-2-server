FUNCTION FUN_0061f8d0 @ 0x0061f8d0  size=148
CALLERS (3): FUN_006205c0@0x006205c0, FUN_005c80a0@0x005c80a0, FUN_00620d60@0x00620d60
CALLEES (3): FUN_0061f840@0x0061f840, FUN_0061ea10@0x0061ea10, thunk_FUN_0061f0d0@0x0061ea00
----------------------------------------------------------------

undefined4 FUN_0061f8d0(long param_1)

{
  long lVar1;
  
  lVar1 = FUN_0061f840();
  if (lVar1 == 0) {
    if (param_1 == 2) {
      func_0x001a02d0(1);
    }
    else if (param_1 == 1) {
      func_0x001a02d0(0);
    }
    else if (param_1 == 0) {
      thunk_FUN_0061f0d0(0);
      FUN_0061ea10();
      uRam0071530c = 0;
      func_0x001a0320();
    }
  }
  return 1;
}



================================================================