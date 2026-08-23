FUNCTION FUN_005eb1d0 @ 0x005eb1d0  size=120
CALLERS (0): 
CALLEES (4): FUN_005eb250@0x005eb250, FUN_005ef5b0@0x005ef5b0, FUN_005f0e10@0x005f0e10, FUN_005ef850@0x005ef850
----------------------------------------------------------------

undefined4 FUN_005eb1d0(undefined8 param_1,undefined8 param_2)

{
  undefined4 uVar1;
  long lVar2;
  
  lVar2 = FUN_005f0e10(param_1,param_2,2);
  if (lVar2 < 0) {
    uVar1 = 0xffffffff;
  }
  else {
    *(undefined4 *)(iRam007012a0 + 4) = 0;
    *(undefined1 *)param_2 = 0;
    FUN_005ef5b0();
    lVar2 = FUN_005ef850(2);
    if (lVar2 < 0) {
      uVar1 = 0xffffffff;
    }
    else {
      FUN_005eb250(param_1,param_2);
      uVar1 = 0;
    }
  }
  return uVar1;
}



================================================================