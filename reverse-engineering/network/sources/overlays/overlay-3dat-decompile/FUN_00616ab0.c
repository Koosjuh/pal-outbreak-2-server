FUNCTION FUN_00616ab0 @ 0x00616ab0  size=144
CALLERS (15): FUN_006160f8@0x006160f8, FUN_00615fc8@0x00615fc8, FUN_006158c8@0x006158c8, FUN_00615f48@0x00615f48, FUN_00615ea8@0x00615ea8, FUN_00616210@0x00616210, FUN_00616048@0x00616048, FUN_006160a0@0x006160a0, FUN_006161d8@0x006161d8, FUN_00615e20@0x00615e20, FUN_00616288@0x00616288, FUN_00616250@0x00616250, ...
CALLEES (1): FUN_00616a00@0x00616a00
----------------------------------------------------------------

long FUN_00616ab0(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  long lVar1;
  
  lVar1 = FUN_00616a00();
  if (lVar1 < 0) {
    func_0x00114ac8(0x693db8,param_3);
  }
  else {
    lVar1 = func_0x00115c68(param_1,param_3,1,param_2,0x1000,param_2,0x1000,0x6169d8);
  }
  return lVar1;
}



================================================================