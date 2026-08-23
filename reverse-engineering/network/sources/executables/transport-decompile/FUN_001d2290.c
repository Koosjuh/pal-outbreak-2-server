
void FUN_001d2290(int param_1,undefined8 param_2)

{
  undefined2 uVar1;
  ushort uVar2;
  int iVar3;
  undefined4 uVar4;
  short *psVar5;
  undefined4 *puVar6;
  ushort uVar7;
  int iVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
  uint uVar11;
  undefined4 *puVar12;
  undefined1 auStack_120 [64];
  undefined1 auStack_e0 [16];
  ushort auStack_d0 [104];
  
  uVar1 = FUN_00199850(param_2);
  *(undefined2 *)(param_1 + 0x816) = uVar1;
  iVar3 = FUN_00199890(param_2);
  for (uVar11 = 0; (int)uVar11 < iVar3; uVar11 = uVar11 + 1 & 0xffff) {
    uVar2 = FUN_001998c0(param_2,uVar11);
    auStack_d0[uVar11] = uVar2;
  }
  auStack_d0[uVar11] = *(ushort *)(param_1 + 0x816);
  puVar12 = (undefined4 *)(iRam003435bc + 0x200000);
  FUN_00186320(auStack_120);
  for (uVar11 = 0; (int)uVar11 < iVar3; uVar11 = uVar11 + 1 & 0xffff) {
    thunk_FUN_00199b60(auStack_e0,puVar12,param_2,uVar11);
    uVar4 = FUN_001889b0(auStack_e0);
    *(undefined4 *)(param_1 + 0x80c) = uVar4;
    FUN_001a9a90(*(undefined4 *)(param_1 + 0x80c));
    FUN_00189bb0(puVar12,*(undefined4 *)(param_1 + 0x80c));
    FUN_00189880(puVar12,auStack_120);
    psVar5 = (short *)(uVar11 * 2 + 0x4172c4);
    *psVar5 = 0;
    uVar2 = auStack_d0[uVar11 + 1];
    puVar6 = puVar12;
    for (uVar7 = auStack_d0[uVar11]; uVar7 < uVar2; uVar7 = uVar7 + 1) {
      if (uVar7 != auStack_d0[uVar11]) {
        iVar8 = 8;
        puVar9 = (undefined4 *)(uVar11 * 0x180 + *psVar5 * 0x40 + 0x4052c0);
        puVar10 = puVar6;
        do {
          iVar8 = iVar8 + -1;
          uVar4 = puVar10[1];
          *puVar9 = *puVar10;
          puVar10 = puVar10 + 2;
          puVar9[1] = uVar4;
          puVar9 = puVar9 + 2;
        } while (0 < iVar8);
        puVar10 = puVar6 + 0x20;
        iVar8 = 8;
        puVar9 = (undefined4 *)(uVar11 * 0x180 + 0x40e2c0 + *psVar5 * 0x40);
        do {
          iVar8 = iVar8 + -1;
          uVar4 = puVar10[1];
          *puVar9 = *puVar10;
          puVar10 = puVar10 + 2;
          puVar9[1] = uVar4;
          puVar9 = puVar9 + 2;
        } while (0 < iVar8);
        *psVar5 = *psVar5 + 1;
      }
      puVar6 = puVar6 + 100;
    }
    FUN_00188ab0(*(undefined4 *)(param_1 + 0x80c));
    FUN_001a9ae0(*(undefined4 *)(param_1 + 0x80c));
    *(undefined4 *)(param_1 + 0x80c) = 0;
  }
  return;
}

