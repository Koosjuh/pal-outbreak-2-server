FUNCTION FUN_00001228 @ 0x00001228 size=132
CALLERS (1): FUN_000000dc@0x000000dc
CALLEES (1): FUN_000005a8@0x000005a8

undefined4 FUN_00001228(void)

{
  undefined4 uVar1;
  int iVar2;
  
  DAT_00002f50 = 0;
  if (((DAT_00002eb0 == 3) || (DAT_00002eb0 == 4)) || (DAT_00002eb0 == 5)) {
    iVar2 = FUN_000005a8(6);
    if (iVar2 != 0) {
      DAT_00002f50 = 0x10;
    }
    uVar1 = 0;
  }
  else {
    DAT_00002f50 = 2;
    uVar1 = 0xffffffff;
  }
  return uVar1;
}


================================================================