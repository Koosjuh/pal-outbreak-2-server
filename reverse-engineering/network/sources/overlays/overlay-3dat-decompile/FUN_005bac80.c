FUNCTION FUN_005bac80 @ 0x005bac80  size=88
CALLERS (9): FUN_005fd630@0x005fd630, FUN_005fd9e0@0x005fd9e0, FUN_005fe140@0x005fe140, FUN_005fbbf0@0x005fbbf0, FUN_005b3790@0x005b3790, FUN_005fcc70@0x005fcc70, FUN_005fcba0@0x005fcba0, FUN_00602700@0x00602700, FUN_00605a90@0x00605a90
CALLEES (0): 
----------------------------------------------------------------

undefined4 FUN_005bac80(char param_1)

{
  undefined4 uVar1;
  undefined8 uVar2;
  
  if (param_1 < '\f') {
    uVar2 = func_0x001b6f50(param_1);
    func_0x00109728(0x6ca260,0x639e50,uVar2);
    uVar1 = 0x6ca260;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}



================================================================