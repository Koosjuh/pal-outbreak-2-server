FUNCTION FUN_00637c70 @ 0x00637c70  size=40
CALLERS (2): FUN_00630910@0x00630910, FUN_006379e0@0x006379e0
CALLEES (0): 
----------------------------------------------------------------

undefined4 FUN_00637c70(ushort param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if ((0x40 < param_1) && (param_1 < 0x5b)) {
    uVar1 = 1;
  }
  return uVar1;
}



================================================================