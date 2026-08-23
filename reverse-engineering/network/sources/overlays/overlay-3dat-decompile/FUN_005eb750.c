FUNCTION FUN_005eb750 @ 0x005eb750  size=120
CALLERS (0): 
CALLEES (4): FUN_005f0e10@0x005f0e10, FUN_005ef5e0@0x005ef5e0, FUN_005ef850@0x005ef850, FUN_005eb7d0@0x005eb7d0
----------------------------------------------------------------

undefined4 FUN_005eb750(undefined8 param_1,undefined8 param_2)

{
  undefined4 uVar1;
  long lVar2;
  
  lVar2 = FUN_005f0e10(param_1,param_2,4);
  if (lVar2 < 0) {
    uVar1 = 0xffffffff;
  }
  else {
    *(undefined4 *)(iRam007012a0 + 4) = 0;
    *(undefined1 *)param_2 = 0;
    FUN_005ef5e0();
    lVar2 = FUN_005ef850(4);
    if (lVar2 < 0) {
      uVar1 = 0xffffffff;
    }
    else {
      FUN_005eb7d0(param_1,param_2);
      uVar1 = 0;
    }
  }
  return uVar1;
}



================================================================