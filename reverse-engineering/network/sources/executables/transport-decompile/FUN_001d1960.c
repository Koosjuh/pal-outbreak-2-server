
void FUN_001d1960(int param_1,undefined8 param_2,uint param_3)

{
  ushort uVar1;
  undefined2 uVar2;
  undefined4 uVar3;
  long lVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  undefined1 auStack_80 [80];
  undefined1 auStack_30 [40];
  undefined1 auStack_8 [8];
  
  uVar2 = FUN_00199f10(param_2);
  *(undefined2 *)(param_1 + 0x812) = uVar2;
  iVar8 = 0;
  do {
    if ((int)(uint)*(ushort *)(param_1 + 0x812) <= iVar8) {
      return;
    }
    iVar6 = iVar8 * 0x98;
    uVar3 = FUN_0019a210(param_2,iVar8);
    *(undefined4 *)(*(int *)(param_1 + 0x808) + iVar6 + 4) = uVar3;
    FUN_0019a260(param_2,iVar8,*(int *)(param_1 + 0x808) + iVar6 + 8);
    iVar7 = 0;
    while( true ) {
      iVar5 = iVar6 + *(int *)(param_1 + 0x808);
      if (*(int *)(iVar5 + 4) <= iVar7) break;
      uVar1 = *(ushort *)(param_1 + *(int *)(iVar5 + iVar7 * 4 + 8) * 2 + 8);
      FUN_001a7b70(iVar7 + 0x3aU & 0xff,((uint)uVar1 * 0x12 + (uint)uVar1) * 4 + 0x52d620);
      iVar7 = iVar7 + 1;
    }
    lVar4 = FUN_00199df0(auStack_80,param_2,iVar8);
    if (lVar4 < 0) {
      *(undefined1 *)(*(int *)(param_1 + 0x808) + iVar6 + 0x88) = 0;
    }
    else {
      FUN_001d1b80(auStack_80,*(int *)(param_1 + 0x808) + iVar6);
      *(undefined1 *)(*(int *)(param_1 + 0x808) + iVar6 + 0x88) = 1;
    }
    FUN_00184120(auStack_8);
    lVar4 = FUN_0019aaf0(auStack_30,param_2,iVar8);
    if (lVar4 == 0) {
      *(undefined4 *)(*(int *)(param_1 + 0x808) + iVar6) = 0xffffffff;
LAB_001d1b10:
      iVar6 = *(int *)(param_1 + 0x818);
    }
    else {
      uVar3 = FUN_001801b0(auStack_30,*(undefined4 *)(&DAT_0024cb70 + (param_3 & 0xff) * 4));
      *(undefined4 *)(*(int *)(param_1 + 0x808) + iVar6) = uVar3;
      if (*(int *)(*(int *)(param_1 + 0x808) + iVar6) == 0) goto LAB_001d1b10;
      FUN_001a99c0();
      iVar6 = *(int *)(param_1 + 0x818);
    }
    if (iVar6 != 0) {
      FUN_00199d50(iVar6 + iVar8 * 0x42,param_2,iVar8);
    }
    FUN_00184140(auStack_8);
    iVar8 = iVar8 + 1;
  } while( true );
}

