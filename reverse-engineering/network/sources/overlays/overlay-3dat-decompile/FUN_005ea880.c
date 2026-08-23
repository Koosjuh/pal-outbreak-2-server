FUNCTION FUN_005ea880 @ 0x005ea880  size=120
CALLERS (0): 
CALLEES (5): FUN_005f0e10@0x005f0e10, FUN_005ea900@0x005ea900, FUN_005ef850@0x005ef850, FUN_005ef0e0@0x005ef0e0, FUN_005ef550@0x005ef550
----------------------------------------------------------------

undefined4 FUN_005ea880(undefined8 param_1,undefined8 param_2)

{
  undefined4 uVar1;
  long lVar2;
  
  lVar2 = FUN_005f0e10(param_1,param_2,1);
  if (lVar2 < 0) {
    uVar1 = 0xffffffff;
  }
  else {
    FUN_005ef0e0(param_2);
    FUN_005ef550();
    lVar2 = FUN_005ef850(1);
    if (lVar2 < 0) {
      uVar1 = 0xffffffff;
    }
    else {
      FUN_005ea900(param_1,param_2);
      uVar1 = 0;
    }
  }
  return uVar1;
}



================================================================