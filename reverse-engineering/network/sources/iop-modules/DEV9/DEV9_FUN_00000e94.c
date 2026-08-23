FUNCTION FUN_00000e94 @ 0x00000e94 size=112
CALLERS (2): FUN_00001164@0x00001164, FUN_0000159c@0x0000159c
CALLEES (0): 

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00000e94(void)

{
  ushort uVar1;
  
  uVar1 = _DAT_bf801462 & 0xc;
  if (uVar1 == 4) {
    return 3;
  }
  if (uVar1 < 5) {
    if ((_DAT_bf801462 & 0xc) == 0) {
      return 1;
    }
  }
  else {
    if (uVar1 == 8) {
      return 1;
    }
    if (uVar1 == 0xc) {
      return 2;
    }
  }
  return 0;
}


================================================================