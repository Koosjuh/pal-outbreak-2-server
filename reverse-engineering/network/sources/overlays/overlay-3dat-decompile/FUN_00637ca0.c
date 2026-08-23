FUNCTION FUN_00637ca0 @ 0x00637ca0  size=108
CALLERS (2): FUN_00630910@0x00630910, FUN_006379e0@0x006379e0
CALLEES (1): FUN_00637c40@0x00637c40
----------------------------------------------------------------

undefined8 FUN_00637ca0(short param_1)

{
  long lVar1;
  undefined8 uVar2;
  
  lVar1 = FUN_00637c40();
  uVar2 = 1;
  if (lVar1 != 1) {
    if (((param_1 == 0x2d) || (param_1 == 0x2a)) || (param_1 == 0x23)) {
      uVar2 = 1;
    }
    else {
      uVar2 = 0;
    }
  }
  return uVar2;
}



================================================================