FUNCTION FUN_0000876c @ 0x0000876c size=184
CALLERS (1): FUN_00007660@0x00007660
CALLEES (3): FUN_0001073c@0x0001073c, FUN_000107dc@0x000107dc, FUN_00010764@0x00010764

undefined4 FUN_0000876c(void)

{
  DAT_00012ecc = 9;
  while ((DAT_00012ee4 == 0 && (DAT_00012ecc == 9))) {
    FUN_00010764();
    FUN_000107dc();
    FUN_0001073c();
    if (DAT_00012ecc == 2) {
      return 0;
    }
  }
  return 4;
}


================================================================