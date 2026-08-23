FUNCTION FUN_00000f04 @ 0x00000f04 size=164
CALLERS (1): FUN_00001240@0x00001240
CALLEES (1): FUN_000021e0@0x000021e0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00000f04(int param_1,int param_2)

{
  undefined4 uVar1;
  
  _DAT_bf80146c = (ushort)(param_1 == 1) << 2;
  if (param_1 == 2) {
    _DAT_bf80146c = 8;
  }
  if (param_2 == 1) {
    _DAT_bf80146c = _DAT_bf80146c | 0x10;
  }
  FUN_000021e0(22000);
  uVar1 = 0;
  if ((_DAT_bf801462 & 0x100) == 0) {
    _DAT_bf80146c = 0;
    uVar1 = 0xffffffff;
  }
  return uVar1;
}


================================================================