FUNCTION FUN_00000e50 @ 0x00000e50 size=68
CALLERS (2): FUN_00001164@0x00001164, FUN_0000159c@0x0000159c
CALLEES (0): 

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00000e50(void)

{
  if ((_DAT_bf801462 & 3) == 0) {
    return 1;
  }
  if (2 < (_DAT_bf801462 & 3)) {
    return 0;
  }
  return 2;
}


================================================================