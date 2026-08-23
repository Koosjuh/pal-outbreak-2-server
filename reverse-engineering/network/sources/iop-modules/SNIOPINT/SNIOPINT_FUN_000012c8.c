FUNCTION FUN_000012c8 @ 0x000012c8 size=352
CALLERS (1): FUN_00002858@0x00002858
CALLEES (4): FUN_000037d4@0x000037d4, FUN_00003818@0x00003818, FUN_00003810@0x00003810, FUN_0000374c@0x0000374c

void FUN_000012c8(int param_1)

{
  int *piVar1;
  ushort uVar2;
  ushort uVar3;
  short sVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  short *psVar7;
  short *psVar8;
  int iVar9;
  uint uVar10;
  
  uVar2 = *(ushort *)(param_1 + 0x26);
  uVar3 = *(ushort *)(param_1 + 0x1e);
  FUN_00003818(DAT_00008be8);
  puVar5 = DAT_00008be4;
  uVar10 = (uint)uVar2 + (uint)uVar3 + 0xc & 0xffff;
  if ((int)(DAT_00008be4[1] - DAT_00008be4[2]) < (int)(uVar10 + 2)) {
    sVar4 = *(short *)(DAT_00008be4 + 3);
    uVar6 = *DAT_00008be4;
    *(undefined2 *)(DAT_00008be4 + 3) = 0;
    DAT_00003ad8 = DAT_00003ad8 + sVar4;
    puVar5[2] = uVar6;
  }
  FUN_0000374c(DAT_00008be4[2],(short *)(param_1 + 0x1c),uVar10);
  puVar5 = DAT_00008be4;
  piVar1 = DAT_00008be4 + 2;
  sVar4 = *(short *)(DAT_00008be4 + 3);
  *(short *)(DAT_00008be4 + 3) = sVar4 + 1;
  puVar5[2] = *piVar1 + uVar10;
  if ((short)(sVar4 + 1) == 1) {
    FUN_000037d4(DAT_00008bec,1);
  }
  *(undefined4 *)(param_1 + 0x18) = 0;
  iVar9 = 0;
  psVar8 = &DAT_00008bf2;
  psVar7 = &DAT_00008bf0;
  do {
    iVar9 = iVar9 + 1;
    if (*psVar7 == *(short *)(param_1 + 0x1c)) {
      *(int *)(param_1 + 0x18) = (int)*psVar8;
      *psVar7 = -1;
      *psVar8 = 0;
      break;
    }
    psVar8 = psVar8 + 2;
    psVar7 = psVar7 + 2;
  } while (iVar9 < 8);
  FUN_00003810(DAT_00008be8);
  return;
}


================================================================