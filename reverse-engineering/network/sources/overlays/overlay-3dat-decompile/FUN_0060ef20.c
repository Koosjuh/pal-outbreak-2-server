FUNCTION FUN_0060ef20 @ 0x0060ef20  size=204
CALLERS (3): FUN_00610580@0x00610580, FUN_006101d0@0x006101d0, FUN_00610830@0x00610830
CALLEES (4): FUN_0060eff0@0x0060eff0, FUN_0060eba0@0x0060eba0, FUN_0060ec60@0x0060ec60, FUN_0060eaa0@0x0060eaa0
----------------------------------------------------------------

undefined8 FUN_0060ef20(undefined8 param_1)

{
  long lVar1;
  undefined8 uVar2;
  
  *(undefined4 *)((int)param_1 + 0x19ae4) = *(undefined4 *)((int)param_1 + 0x19ae0);
  FUN_0060eaa0(param_1,1);
  lVar1 = FUN_0060eba0(param_1);
  if (lVar1 < 1) {
    FUN_0060eaa0(param_1,2);
    lVar1 = FUN_0060eba0(param_1);
    if (lVar1 < 1) {
      FUN_0060eaa0(param_1,0);
      lVar1 = FUN_0060eba0(param_1);
      if (lVar1 < 1) {
        uVar2 = 0;
      }
      else {
        FUN_0060ec60(param_1);
        uVar2 = FUN_0060eff0(param_1);
      }
    }
    else {
      FUN_0060ec60(param_1);
      uVar2 = FUN_0060eff0(param_1);
    }
  }
  else {
    FUN_0060ec60(param_1);
    uVar2 = FUN_0060eff0(param_1);
  }
  return uVar2;
}



================================================================