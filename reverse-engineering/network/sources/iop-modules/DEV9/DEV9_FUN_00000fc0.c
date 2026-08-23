FUNCTION FUN_00000fc0 @ 0x00000fc0 size=140
CALLERS (1): FUN_0000002c@0x0000002c
CALLEES (0): 

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00000fc0(ushort param_1)

{
  _DAT_bf801476 = param_1 & 1;
  if ((param_1 & 0x10) != 0) {
    _DAT_bf801476 = 1;
  }
  if ((param_1 & 2) != 0) {
    _DAT_bf801476 = _DAT_bf801476 | 2;
  }
  if ((param_1 & 0x20) != 0) {
    _DAT_bf801476 = _DAT_bf801476 | 2;
  }
  if ((param_1 & 4) != 0) {
    _DAT_bf801476 = _DAT_bf801476 | 8;
  }
  if ((param_1 & 8) != 0) {
    _DAT_bf801476 = _DAT_bf801476 | 0x10;
  }
  if ((param_1 & 0x200) != 0) {
    _DAT_bf801476 = _DAT_bf801476 | 0x20;
  }
  if ((param_1 & 0x100) != 0) {
    _DAT_bf801476 = _DAT_bf801476 | 0x40;
  }
  if ((param_1 & 0x400) != 0) {
    _DAT_bf801476 = _DAT_bf801476 | 0x80;
  }
  if ((param_1 & 0x800) != 0) {
    _DAT_bf801476 = _DAT_bf801476 | 4;
  }
  return;
}


================================================================