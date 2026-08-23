FUNCTION FUN_00008698 @ 0x00008698 size=212
CALLERS (1): FUN_00007660@0x00007660
CALLEES (4): FUN_0001073c@0x0001073c, FUN_000103cc@0x000103cc, FUN_00010764@0x00010764, FUN_000107dc@0x000107dc

uint FUN_00008698(int param_1)

{
  short sVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  iVar2 = FUN_000103cc();
  if (DAT_00014ba8 == (short *)0x0) {
    sVar1 = *(short *)(param_1 + 4);
  }
  else {
    sVar1 = *DAT_00014ba8;
  }
  while (DAT_00012ee4 == 0) {
    iVar3 = FUN_000103cc();
    uVar4 = 0;
    if ((uint)(sVar1 * 1000) < (uint)(iVar3 - iVar2)) goto LAB_00008750;
    FUN_00010764();
    FUN_000107dc();
    FUN_0001073c();
  }
  uVar4 = 0x40000;
LAB_00008750:
  return uVar4 >> 0x10;
}


================================================================