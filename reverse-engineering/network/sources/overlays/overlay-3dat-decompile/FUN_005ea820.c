FUNCTION FUN_005ea820 @ 0x005ea820  size=88
CALLERS (0): 
CALLEES (4): FUN_005f0e10@0x005f0e10, FUN_005ef850@0x005ef850, FUN_005ef0e0@0x005ef0e0, FUN_005ef550@0x005ef550
----------------------------------------------------------------

int FUN_005ea820(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  long lVar2;
  
  lVar2 = FUN_005f0e10(param_1,param_2,1);
  if (lVar2 < 0) {
    iVar1 = -1;
  }
  else {
    FUN_005ef0e0(param_2);
    FUN_005ef550();
    lVar2 = FUN_005ef850(1);
    iVar1 = -(uint)(lVar2 < 0);
  }
  return iVar1;
}



================================================================