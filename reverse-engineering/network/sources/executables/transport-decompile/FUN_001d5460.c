
undefined4 FUN_001d5460(int param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  long lVar6;
  int iStack_38;
  
  lVar6 = FUN_001eb2d4(*(int *)(param_1 + 0x58) + 8);
  if (lVar6 == 0) {
    uVar5 = 0;
  }
  else {
    iVar1 = FUN_001ebd54(*(int *)(param_1 + 0x58) + 8);
    do {
      do {
        iStack_38 = iVar1;
        if (*(int *)(param_1 + 0x58) + 8 == iStack_38) {
          return 0;
        }
        iVar1 = FUN_001ebd7c(iStack_38);
        iVar2 = FUN_001ed4a4(iStack_38);
        iVar3 = FUN_001ed44c(iStack_38);
        iVar4 = FUN_001ed4fc(iStack_38);
      } while (param_2 < (uint)(iVar2 + iVar3 + iVar4));
      iVar2 = FUN_001ed5dc(iStack_38);
      if (*(int *)(param_1 + 0x518) < iVar2) {
        *(undefined4 *)(param_1 + 0x50c) = 300;
        return 0xffffffff;
      }
      iVar2 = FUN_001eb4dc(*(int *)(param_1 + 0x58) + 8,iStack_38);
      if (iVar2 != 0) {
        *(undefined4 *)(param_1 + 0x50c) = 200;
        return 0xffffffff;
      }
      FUN_001ebbd0(iStack_38,0x400);
      iVar2 = FUN_001ed4fc(iStack_38);
      FUN_001ed524(iStack_38,iVar2 + 200);
      FUN_001ebc10(iStack_38,0x1000);
      FUN_001ed634(iStack_38,0);
      iVar2 = FUN_001eb3b8(*(int *)(param_1 + 0x60) + 8,iStack_38);
    } while (iVar2 == 0);
    *(undefined4 *)(param_1 + 0x50c) = 200;
    uVar5 = 0xffffffff;
  }
  return uVar5;
}

