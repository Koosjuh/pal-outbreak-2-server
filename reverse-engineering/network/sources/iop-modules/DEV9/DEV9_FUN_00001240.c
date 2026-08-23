FUNCTION FUN_00001240 @ 0x00001240 size=192
CALLERS (1): FUN_00000118@0x00000118
CALLEES (2): FUN_00000f04@0x00000f04, FUN_000021e0@0x000021e0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00001240(void)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = 0xffffffff;
  if ((_DAT_bf801462 & 3) == 0) {
    _DAT_bf80147e = 1;
    iVar2 = FUN_00000f04(DAT_00002734,1);
    if (iVar2 < 0) {
      uVar1 = 0xffffffff;
    }
    else {
      _DAT_bf80146c = _DAT_bf80146c | 2;
      FUN_000021e0(500000);
      _DAT_bf80146c = _DAT_bf80146c | 1;
      uVar1 = 0;
    }
  }
  return uVar1;
}


================================================================