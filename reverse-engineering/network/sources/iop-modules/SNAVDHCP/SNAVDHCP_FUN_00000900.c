FUNCTION FUN_00000900 @ 0x00000900 size=228
CALLERS (2): FUN_00001d38@0x00001d38, FUN_00002150@0x00002150
CALLEES (3): FUN_00000844@0x00000844, FUN_00001394@0x00001394, FUN_00001438@0x00001438

undefined4 FUN_00000900(void)

{
  undefined4 uVar1;
  
  if (((DAT_00002eb0 == 4) || (DAT_00002eb0 == 5)) || (uVar1 = 0, DAT_00002eb0 == 6)) {
    if (-1 < (short)DAT_00002f88) {
      FUN_00001438();
    }
    DAT_00002f88 = FUN_00001394(0,0x4300,0x4400,0xe10);
    uVar1 = 0;
    if ((int)((uint)DAT_00002f88 << 0x10) < 0) {
      if (DAT_00002eb0 == 6) {
        DAT_00002f84 = FUN_00000844(0);
      }
      uVar1 = 0xffffffff;
      DAT_00002f50 = 4;
      DAT_00002f7c = 0xffffffff;
      DAT_00002eb0 = -2;
    }
  }
  return uVar1;
}


================================================================