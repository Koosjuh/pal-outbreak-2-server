FUNCTION FUN_00618800 @ 0x00618800  size=136
CALLERS (2): FUN_005b3790@0x005b3790, FUN_005ae8a0@0x005ae8a0
CALLEES (0): 
----------------------------------------------------------------

undefined4 FUN_00618800(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  if (cRam006cbb44 == '\0') {
    uRam006fe8f4 = 0;
    uRam006fe8ec = param_1;
    func_0x00106b60(0x6fe8f8,0,0x180);
    cRam006cbb44 = '\x01';
    pcRam006cbb20 = FUN_006188b0;
    uVar1 = 0;
    uRam006cbb40 = 0;
    uRam006cbb24 = param_2;
  }
  else {
    uVar1 = 0xffffffff;
  }
  return uVar1;
}



================================================================