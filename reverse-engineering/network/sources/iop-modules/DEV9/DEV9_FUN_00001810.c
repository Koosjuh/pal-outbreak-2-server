FUNCTION FUN_00001810 @ 0x00001810 size=136
CALLERS (1): FUN_00000118@0x00000118
CALLEES (2): FUN_000021e0@0x000021e0, FUN_000000c8@0x000000c8

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00001810(void)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_000000c8();
  if (iVar1 == 0) {
    _DAT_bf80146c = _DAT_bf80146c & 0xfffe | 4;
    FUN_000021e0(500000);
    _DAT_bf801460 = _DAT_bf801460 | 1;
    _DAT_bf80146c = _DAT_bf80146c | 1;
    FUN_000021e0(500000);
    uVar2 = 0;
  }
  else {
    uVar2 = 0xffffffff;
  }
  return uVar2;
}


================================================================