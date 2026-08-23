FUNCTION FUN_005affb0 @ 0x005affb0  size=596
CALLERS (0): 
CALLEES (6): FUN_005af2e0@0x005af2e0, FUN_0062fea0@0x0062fea0, FUN_005bb060@0x005bb060, FUN_005af2c0@0x005af2c0, FUN_005af1e0@0x005af1e0, FUN_005b0950@0x005b0950
----------------------------------------------------------------

void FUN_005affb0(int param_1)

{
  undefined8 uVar1;
  undefined4 uVar2;
  undefined *puVar3;
  undefined4 uVar4;
  undefined *puVar5;
  int iVar6;
  undefined8 *puVar7;
  undefined8 *puVar8;
  undefined **ppuVar9;
  undefined8 *puVar10;
  uint uVar11;
  undefined1 auStack_b0 [32];
  undefined8 uStack_90;
  undefined4 auStack_88 [2];
  undefined8 auStack_80 [4];
  undefined8 uStack_60;
  undefined8 uStack_30;
  undefined4 auStack_28 [2];
  undefined8 auStack_20 [3];
  ushort uStack_4;
  ushort uStack_2;
  
  puVar7 = (undefined8 *)&DAT_00638960;
  puVar8 = &uStack_30;
  iVar6 = 2;
  do {
    uVar1 = *puVar7;
    uVar2 = *(undefined4 *)(puVar7 + 1);
    uVar4 = *(undefined4 *)((int)puVar7 + 0xc);
    iVar6 = iVar6 + -1;
    *(int *)puVar8 = (int)uVar1;
    *(int *)((int)puVar8 + 4) = (int)((ulong)uVar1 >> 0x20);
    *(undefined4 *)(puVar8 + 1) = uVar2;
    *(undefined4 *)((int)puVar8 + 0xc) = uVar4;
    puVar7 = puVar7 + 2;
    puVar8 = puVar8 + 2;
  } while (0 < iVar6);
  puVar10 = &uStack_60;
  iVar6 = 2;
  *puVar8 = *puVar7;
  puVar7 = (undefined8 *)&DAT_00638990;
  do {
    uVar1 = *puVar7;
    uVar2 = *(undefined4 *)(puVar7 + 1);
    uVar4 = *(undefined4 *)((int)puVar7 + 0xc);
    iVar6 = iVar6 + -1;
    *(int *)puVar10 = (int)uVar1;
    *(int *)((int)puVar10 + 4) = (int)((ulong)uVar1 >> 0x20);
    *(undefined4 *)(puVar10 + 1) = uVar2;
    *(undefined4 *)((int)puVar10 + 0xc) = uVar4;
    puVar7 = puVar7 + 2;
    puVar10 = puVar10 + 2;
  } while (0 < iVar6);
  ppuVar9 = &PTR_s_ses_Titels__006389c0;
  iVar6 = 2;
  puVar8 = &uStack_90;
  *puVar10 = *puVar7;
  do {
    uVar1 = *(undefined8 *)ppuVar9;
    puVar3 = ppuVar9[2];
    puVar5 = ppuVar9[3];
    iVar6 = iVar6 + -1;
    *(int *)puVar8 = (int)uVar1;
    *(int *)((int)puVar8 + 4) = (int)((ulong)uVar1 >> 0x20);
    *(undefined **)(puVar8 + 1) = puVar3;
    *(undefined **)((int)puVar8 + 0xc) = puVar5;
    ppuVar9 = ppuVar9 + 4;
    puVar8 = puVar8 + 2;
  } while (0 < iVar6);
  *puVar8 = *(undefined8 *)ppuVar9;
  if (*(char *)(param_1 + 4) != '\x01') {
    if (*(char *)(param_1 + 4) != '\0') {
      return;
    }
    *(undefined2 *)(param_1 + 0x26) = *(undefined2 *)(auStack_28 + *(char *)(param_1 + 3) + -2);
    *(undefined2 *)(param_1 + 0x28) =
         *(undefined2 *)((int)auStack_28 + *(char *)(param_1 + 3) * 4 + -6);
    *(char *)(param_1 + 4) = *(char *)(param_1 + 4) + '\x01';
  }
  if (*(char *)(*(char *)(param_1 + 3) * 0x15c + 0x6c386e) == '\x03') {
    FUN_005af2c0(0);
  }
  else {
    FUN_005af2c0(0xb);
  }
  FUN_005af2e0(0x10);
  iVar6 = *(char *)(param_1 + 3) * 4;
  FUN_005af1e0(*(undefined2 *)((int)&uStack_60 + iVar6),*(undefined2 *)((int)&uStack_60 + iVar6 + 2)
               ,0,*(char *)(param_1 + 3) * 0x15c + 0x6c3878);
  iVar6 = *(char *)(param_1 + 3) * 4;
  uVar1 = FUN_005bb060();
  FUN_005af1e0(*(undefined2 *)((int)&uStack_60 + iVar6),
               *(ushort *)((int)&uStack_60 + iVar6 + 2) + 0xe,0,uVar1);
  FUN_005af2e0(0xe);
  FUN_005b0950(*(char *)(param_1 + 3) + '\x01',&uStack_4);
  uVar11 = (uint)uStack_4 + (uint)uStack_2;
  if (9999 < uVar11) {
    uVar11 = 9999;
  }
  uVar1 = FUN_0062fea0(7);
  func_0x00109728(auStack_b0,0x6389e8,uVar11,uVar1);
  FUN_005af1e0(*(undefined2 *)(auStack_88 + *(char *)(param_1 + 3) + -2),
               *(undefined2 *)((int)auStack_88 + *(char *)(param_1 + 3) * 4 + -6),0,auStack_b0);
  FUN_005af2c0(0);
  return;
}



================================================================