FUNCTION FUN_0000046c @ 0x0000046c size=316
CALLERS (5): FUN_00001568@0x00001568, FUN_000029ac@0x000029ac, FUN_00000e10@0x00000e10, FUN_00002150@0x00002150, FUN_00001a1c@0x00001a1c
CALLEES (2): FUN_00002d88@0x00002d88, FUN_00002d90@0x00002d90

undefined4 FUN_0000046c(short param_1,short param_2,int param_3)

{
  int iVar1;
  undefined2 *puVar2;
  uint uVar3;
  short *psVar4;
  short *psVar5;
  undefined **ppuVar6;
  int iVar7;
  
  uVar3 = 0;
  iVar7 = (int)param_2;
  psVar4 = &DAT_00002ebe;
  ppuVar6 = &PTR_DAT_00002ec0;
  puVar2 = &DAT_00002eba;
  psVar5 = &DAT_00002ebc;
  iVar1 = 0;
  while (*(short *)((int)&DAT_00002eb8 + iVar1) != param_1) {
    psVar4 = psVar4 + 6;
    ppuVar6 = ppuVar6 + 3;
    puVar2 = puVar2 + 6;
    psVar5 = psVar5 + 6;
    uVar3 = uVar3 + 1;
    iVar1 = iVar1 + 0xc;
    if (0xb < uVar3) {
      return 0xffffffff;
    }
  }
  if (1 < *psVar5) {
    return 0;
  }
  if (*psVar5 < 0) {
    return 0;
  }
  if (param_3 == 0) {
    *puVar2 = 0;
    if (iVar7 < 1) {
      return 0;
    }
    FUN_00002d90(*ppuVar6,0,(int)*psVar4);
    return 0;
  }
  *puVar2 = 1;
  FUN_00002d88(*ppuVar6,param_3,(int)*psVar4);
  if (*psVar5 != 0) {
    return 0;
  }
  iVar1 = *psVar4 + -1;
  if (iVar7 < *psVar4) {
    iVar1 = iVar7;
  }
  (*ppuVar6)[iVar1] = 0;
  return 0;
}


================================================================