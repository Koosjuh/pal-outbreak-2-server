FUNCTION FUN_00637980 @ 0x00637980  size=84
CALLERS (3): FUN_00630750@0x00630750, FUN_00630910@0x00630910, FUN_006379e0@0x006379e0
CALLEES (0): 
----------------------------------------------------------------

undefined4 FUN_00637980(ushort param_1)

{
  undefined4 uVar1;
  
  if (param_1 == 9999) {
    uVar1 = 0;
  }
  else if (param_1 == 0x2c) {
    uVar1 = 1;
  }
  else {
    uVar1 = 1;
    if ((0x1f < param_1) && (param_1 < 0x7f)) {
      uVar1 = 0;
    }
  }
  return uVar1;
}



================================================================