FUNCTION FUN_00001c00 @ 0x00001c00 size=704
CALLERS (1): FUN_00002098@0x00002098
CALLEES (1): FUN_00002838@0x00002838

void FUN_00001c00(uint *param_1)

{
  uint uVar1;
  int iVar2;
  uint *puVar3;
  uint *puVar4;
  uint *puVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  
  uVar8 = *param_1;
  if (uVar8 < 4) {
    uVar1 = FUN_00002838(&DAT_00003df0,0xc30);
    puVar3 = param_1 + 10;
    param_1[6] = uVar1;
    iVar2 = uVar8 * 0x30c;
    puVar4 = (uint *)(&DAT_00003dfc + iVar2);
    param_1[7] = (&DAT_00003df0)[uVar8 * 0xc3];
    param_1[8] = *(uint *)(&DAT_00003df4 + iVar2);
    param_1[9] = *(uint *)(&DAT_00003df8 + iVar2);
    if (((uint)puVar3 & 3) == 0) {
      do {
        uVar1 = puVar4[1];
        uVar6 = puVar4[2];
        uVar7 = puVar4[3];
        *puVar3 = *puVar4;
        puVar3[1] = uVar1;
        puVar3[2] = uVar6;
        puVar3[3] = uVar7;
        puVar4 = puVar4 + 4;
        puVar3 = puVar3 + 4;
      } while (puVar4 != (uint *)(&DAT_00003efc + iVar2));
    }
    else {
      do {
        uVar1 = puVar4[1];
        uVar6 = puVar4[2];
        uVar7 = puVar4[3];
        *puVar3 = *puVar4;
        puVar3[1] = uVar1;
        puVar3[2] = uVar6;
        puVar3[3] = uVar7;
        puVar4 = puVar4 + 4;
        puVar3 = puVar3 + 4;
      } while (puVar4 != (uint *)(&DAT_00003efc + iVar2));
    }
    puVar5 = param_1 + 0x4a;
    puVar3 = (uint *)(&DAT_00003efc + uVar8 * 0x30c);
    puVar4 = (uint *)(uVar8 * 0x30c + 0x3ffc);
    if (((uint)puVar5 & 3) == 0) {
      do {
        uVar1 = puVar3[1];
        uVar6 = puVar3[2];
        uVar7 = puVar3[3];
        *puVar5 = *puVar3;
        puVar5[1] = uVar1;
        puVar5[2] = uVar6;
        puVar5[3] = uVar7;
        puVar3 = puVar3 + 4;
        puVar5 = puVar5 + 4;
      } while (puVar3 != puVar4);
    }
    else {
      do {
        uVar1 = puVar3[1];
        uVar6 = puVar3[2];
        uVar7 = puVar3[3];
        *puVar5 = *puVar3;
        puVar5[1] = uVar1;
        puVar5[2] = uVar6;
        puVar5[3] = uVar7;
        puVar3 = puVar3 + 4;
        puVar5 = puVar5 + 4;
      } while (puVar3 != puVar4);
    }
    param_1 = param_1 + 0x8a;
    puVar4 = (uint *)(uVar8 * 0x30c + 0x3ffc);
    if (((uint)param_1 & 3) == 0) {
      do {
        uVar1 = puVar4[1];
        uVar6 = puVar4[2];
        uVar7 = puVar4[3];
        *param_1 = *puVar4;
        param_1[1] = uVar1;
        param_1[2] = uVar6;
        param_1[3] = uVar7;
        puVar4 = puVar4 + 4;
        param_1 = param_1 + 4;
      } while (puVar4 != &DAT_000040fc + uVar8 * 0xc3);
    }
    else {
      do {
        uVar1 = puVar4[1];
        uVar6 = puVar4[2];
        uVar7 = puVar4[3];
        *param_1 = *puVar4;
        param_1[1] = uVar1;
        param_1[2] = uVar6;
        param_1[3] = uVar7;
        puVar4 = puVar4 + 4;
        param_1 = param_1 + 4;
      } while (puVar4 != &DAT_000040fc + uVar8 * 0xc3);
    }
  }
  else {
    param_1[6] = 0xffffffff;
  }
  return;
}


================================================================