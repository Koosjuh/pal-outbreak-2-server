
void FUN_001d1e40(int param_1,undefined8 param_2,int param_3,int param_4)

{
  int iVar1;
  undefined2 uVar2;
  ushort uVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  uint uVar10;
  undefined1 uVar11;
  float fVar12;
  undefined1 auStack_90 [64];
  undefined1 auStack_50 [16];
  ushort auStack_40 [32];
  
  uVar2 = FUN_00199850(param_2);
  *(undefined2 *)(param_1 + 0x816) = uVar2;
  bRam004ddb43 = FUN_00199890(param_2);
  for (uVar10 = 0; iVar1 = iRam003435bc, uVar10 < bRam004ddb43; uVar10 = uVar10 + 1 & 0xffff) {
    uVar3 = FUN_001998c0(param_2,uVar10);
    auStack_40[uVar10] = uVar3;
    *(char *)(uVar10 + 0x4e0660) = (char)auStack_40[uVar10] + (char)uVar10 * -2;
  }
  auStack_40[uVar10] = *(ushort *)(param_1 + 0x816);
  puVar8 = (undefined4 *)(iRam003435bc + 0x200000);
  FUN_00186320(auStack_90);
  uVar10 = 0;
  do {
    if (bRam004ddb43 <= uVar10) {
      return;
    }
    thunk_FUN_00199b60(auStack_50,puVar8,param_2,uVar10);
    uVar4 = FUN_001889b0(auStack_50);
    *(undefined4 *)(param_1 + 0x80c) = uVar4;
    FUN_001a9a90(*(undefined4 *)(param_1 + 0x80c));
    FUN_00189bb0(puVar8,*(undefined4 *)(param_1 + 0x80c));
    iVar5 = iVar1 + 0x200190;
    uVar3 = auStack_40[uVar10];
    while (uVar3 = uVar3 + 1, uVar3 < auStack_40[uVar10 + 1]) {
      if (*(int *)(iVar5 + 0x174) < 0) {
        fVar12 = *(float *)(iVar5 + 0xdc);
        if (fVar12 < 2.1474836e+09) {
          uVar11 = (undefined1)(int)fVar12;
        }
        else {
          uVar11 = (undefined1)(int)(fVar12 - 2.1474836e+09);
        }
        *(undefined1 *)(uVar10 + 0x4e0678) = uVar11;
        break;
      }
      iVar5 = iVar5 + 400;
    }
    FUN_00189880(puVar8,auStack_90);
    *(undefined1 *)(uVar10 + 0x4ddb44) = 0;
    puVar9 = puVar8;
    for (uVar3 = auStack_40[uVar10]; uVar3 < auStack_40[uVar10 + 1]; uVar3 = uVar3 + 1) {
      if (uVar3 == auStack_40[uVar10]) {
        FUN_00186610(uVar10 * 0xc + 0x4e0690,puVar9);
      }
      if (-1 < (int)puVar9[0x5d]) {
        iVar5 = 8;
        puVar7 = (undefined4 *)(param_3 + puVar9[0x5d] * 0x40);
        puVar6 = puVar9;
        do {
          iVar5 = iVar5 + -1;
          uVar4 = puVar6[1];
          *puVar7 = *puVar6;
          puVar6 = puVar6 + 2;
          puVar7[1] = uVar4;
          puVar7 = puVar7 + 2;
        } while (0 < iVar5);
        iVar5 = 8;
        puVar7 = (undefined4 *)(param_4 + puVar9[0x5d] * 0x40);
        puVar6 = puVar9;
        do {
          iVar5 = iVar5 + -1;
          uVar4 = puVar6[1];
          *puVar7 = *puVar6;
          puVar6 = puVar6 + 2;
          puVar7[1] = uVar4;
          puVar7 = puVar7 + 2;
        } while (0 < iVar5);
        *(char *)(uVar10 + 0x4ddb44) = *(char *)(uVar10 + 0x4ddb44) + '\x01';
      }
      puVar9 = puVar9 + 100;
    }
    FUN_00188ab0(*(undefined4 *)(param_1 + 0x80c));
    FUN_001a9ae0(*(undefined4 *)(param_1 + 0x80c));
    *(undefined4 *)(param_1 + 0x80c) = 0;
    uVar10 = uVar10 + 1 & 0xffff;
  } while( true );
}

