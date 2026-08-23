FUNCTION FUN_000053b4 @ 0x000053b4 size=140
CALLERS (4): FUN_0000d9a8@0x0000d9a8, FUN_0000d8c0@0x0000d8c0, FUN_0000c028@0x0000c028, FUN_000073fc@0x000073fc
CALLEES (1): FUN_000103cc@0x000103cc

undefined4 FUN_000053b4(void)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_000103cc();
  uVar2 = 0;
  if (((DAT_00012ecc == 5) || (DAT_00012ee4 != 0)) ||
     ((uint)(*(short *)(DAT_0001345c + 4) * 1000) < (uint)(iVar1 - DAT_00012ec0))) {
    uVar2 = 1;
  }
  return uVar2;
}


================================================================