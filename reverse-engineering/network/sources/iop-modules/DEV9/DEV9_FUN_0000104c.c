FUNCTION FUN_0000104c @ 0x0000104c size=280
CALLERS (1): FUN_0000007c@0x0000007c
CALLEES (2): FUN_00000fa8@0x00000fa8, FUN_000021e0@0x000021e0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0000104c(int param_1)

{
  ushort uVar1;
  ushort uVar2;
  
  uVar1 = _DAT_bf801474 & 7;
  uVar2 = _DAT_bf801474 & 7;
  if (param_1 == 3) {
    FUN_00000fa8(2);
    if (uVar1 != 0) {
      return 0xffffffff;
    }
    _DAT_bf801474 = 1;
    FUN_00000fa8();
    _DAT_bf801474 = 3;
  }
  else {
    if (param_1 != 5) {
      return 0xffffffff;
    }
    FUN_00000fa8(2);
    if (uVar2 != 0) {
      return 0xffffffff;
    }
    _DAT_bf801474 = (short)param_1;
    FUN_00000fa8(1);
    _DAT_bf801474 = 7;
  }
  _DAT_bf801418 = 0xe01a3043;
  DAT_b0000020 = 1;
  FUN_000021e0(5000);
  _DAT_bf80146c = _DAT_bf80146c & 0xfffe;
  return 0;
}


================================================================