FUNCTION FUN_005dea10 @ 0x005dea10  size=232
CALLERS (0): 
CALLEES (3): FUN_005de8d0@0x005de8d0, FUN_005de880@0x005de880, FUN_005de9a0@0x005de9a0
----------------------------------------------------------------

long FUN_005dea10(long param_1,uint param_2)

{
  uint uVar1;
  long lVar2;
  
  param_2 = param_2 + (0x10 - (param_2 & 0xf));
  if (param_1 == 0) {
    lVar2 = FUN_005de8d0(param_2);
  }
  else if (param_2 == 0) {
    FUN_005de9a0();
    lVar2 = 0;
  }
  else {
    lVar2 = FUN_005de880();
    if (lVar2 == 0) {
      lVar2 = 0;
    }
    else {
      uVar1 = *(uint *)lVar2;
      lVar2 = FUN_005de8d0(param_2);
      if (lVar2 == 0) {
        lVar2 = 0;
      }
      else {
        FUN_005de9a0(param_1);
        if (uVar1 < param_2) {
          func_0x00106a58(lVar2,param_1,uVar1);
        }
        else {
          func_0x00106a58(lVar2,param_1,param_2);
        }
      }
    }
  }
  return lVar2;
}



================================================================