
void FUN_001d26f0(int param_1,undefined8 param_2,long param_3)

{
  undefined2 uVar1;
  ushort uVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  ulong uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  undefined1 auStack_420 [16];
  ushort auStack_410 [520];
  
  if (param_3 == 0) {
    iVar8 = 0x3f41a0;
  }
  else {
    iVar8 = iRam003435bc + 0x2ff000;
  }
  uVar1 = FUN_00199850(param_2);
  *(undefined2 *)(param_1 + 0x816) = uVar1;
  uVar1 = FUN_00199890(param_2);
  *(undefined2 *)(iVar8 + 0x820) = uVar1;
  uVar6 = 0;
  while (iVar9 = (int)uVar6, (long)uVar6 < (long)*(short *)(iVar8 + 0x820)) {
    uVar2 = FUN_001998c0(param_2,uVar6);
    auStack_410[iVar9] = uVar2;
    uVar6 = (long)(iVar9 + 1) & 0xffff;
  }
  auStack_410[iVar9] = *(ushort *)(param_1 + 0x816);
  iVar9 = iRam003435bc + 0x200000;
  uVar6 = 0;
  while ((long)uVar6 < (long)*(short *)(iVar8 + 0x820)) {
    thunk_FUN_00199b60(auStack_420,iVar9,param_2,uVar6);
    uVar3 = FUN_001889b0(auStack_420);
    *(undefined4 *)(param_1 + 0x80c) = uVar3;
    FUN_001a9a90(*(undefined4 *)(param_1 + 0x80c));
    FUN_00189bb0(iVar9,*(undefined4 *)(param_1 + 0x80c));
    iVar7 = (int)uVar6;
    iVar4 = iVar8 + iVar7 * 2;
    *(undefined2 *)(iVar4 + 0xc24) = 0;
    iVar5 = iVar9;
    for (uVar2 = auStack_410[iVar7]; uVar2 < auStack_410[iVar7 + 1]; uVar2 = uVar2 + 1) {
      if (uVar2 == auStack_410[iVar7]) {
        *(undefined2 *)(iVar4 + 0x824) = *(undefined2 *)(iVar5 + 0xc6);
      }
      else if (-1 < *(int *)(iVar5 + 0x174)) {
        *(short *)(iVar8 + iVar7 * 0x20 + *(short *)(iVar4 + 0xc24) * 2 + 0x1024) =
             (short)*(int *)(iVar5 + 0x174);
        *(short *)(iVar4 + 0xc24) = *(short *)(iVar4 + 0xc24) + 1;
      }
      iVar5 = iVar5 + 400;
    }
    FUN_00188ab0(*(undefined4 *)(param_1 + 0x80c));
    FUN_001a9ae0(*(undefined4 *)(param_1 + 0x80c));
    *(undefined4 *)(param_1 + 0x80c) = 0;
    uVar6 = (long)(iVar7 + 1) & 0xffff;
  }
  return;
}

