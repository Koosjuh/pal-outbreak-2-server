
void FUN_001d2170(int param_1,undefined8 param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  int iVar7;
  undefined4 *puVar8;
  undefined1 auStack_50 [64];
  undefined1 auStack_10 [16];
  
  iVar1 = iRam003435d8;
  iVar2 = FUN_00199850(param_2);
  puVar8 = (undefined4 *)(iRam003435bc + 0x200000);
  FUN_00186320(auStack_50);
  thunk_FUN_00199b60(auStack_10,puVar8,param_2,0);
  uVar3 = FUN_001889b0(auStack_10);
  *(undefined4 *)(param_1 + 0x80c) = uVar3;
  FUN_001a9a90(*(undefined4 *)(param_1 + 0x80c));
  FUN_00189bb0(puVar8,*(undefined4 *)(param_1 + 0x80c));
  FUN_00189880(puVar8,auStack_50);
  for (iVar7 = 0; iVar7 < iVar2; iVar7 = iVar7 + 1) {
    if (-1 < (int)puVar8[0x5d]) {
      iVar4 = 8;
      puVar6 = (undefined4 *)(iVar1 + puVar8[0x5d] * 0x40);
      puVar5 = puVar8;
      do {
        iVar4 = iVar4 + -1;
        uVar3 = puVar5[1];
        *puVar6 = *puVar5;
        puVar5 = puVar5 + 2;
        puVar6[1] = uVar3;
        puVar6 = puVar6 + 2;
      } while (0 < iVar4);
    }
    puVar8 = puVar8 + 100;
  }
  FUN_00188ab0(*(undefined4 *)(param_1 + 0x80c));
  FUN_001a9ae0(*(undefined4 *)(param_1 + 0x80c));
  *(undefined4 *)(param_1 + 0x80c) = 0;
  return;
}

