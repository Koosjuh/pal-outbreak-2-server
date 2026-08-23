FUNCTION FUN_005eb6f0 @ 0x005eb6f0  size=88
CALLERS (0): 
CALLEES (3): FUN_005f0e10@0x005f0e10, FUN_005ef5e0@0x005ef5e0, FUN_005ef850@0x005ef850
----------------------------------------------------------------

int FUN_005eb6f0(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  long lVar2;
  
  lVar2 = FUN_005f0e10(param_1,param_2,4);
  if (lVar2 < 0) {
    iVar1 = -1;
  }
  else {
    *(undefined4 *)(iRam007012a0 + 4) = 0;
    *(undefined1 *)param_2 = 0;
    FUN_005ef5e0();
    lVar2 = FUN_005ef850(4);
    iVar1 = -(uint)(lVar2 < 0);
  }
  return iVar1;
}



================================================================