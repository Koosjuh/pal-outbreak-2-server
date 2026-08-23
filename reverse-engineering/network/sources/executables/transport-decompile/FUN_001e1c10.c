
int FUN_001e1c10(int param_1)

{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  long lVar5;
  undefined4 uStack_24;
  
  iVar2 = *(int *)(param_1 + 0x5c) + 4;
  do {
    lVar5 = FUN_001eb2d4(iVar2);
    if (lVar5 == 0) {
      return 0;
    }
    uVar3 = FUN_001ebd54(iVar2);
    bVar1 = false;
    while (uStack_24 = uVar3, lVar5 = FUN_001eb858(iVar2,uStack_24), lVar5 == 0) {
      uVar3 = FUN_001ebd7c(uStack_24);
      iVar4 = FUN_001ed664(uStack_24);
      if (iVar4 == **(int **)(param_1 + 0x5c)) {
        bVar1 = true;
        iVar4 = FUN_001eb4dc(iVar2,uStack_24);
        if (iVar4 != 0) {
          return iVar4;
        }
        iVar4 = FUN_001eb3b8(param_1 + 0x68,uStack_24);
        if (iVar4 != 0) {
          return iVar4;
        }
      }
    }
    if (!bVar1) {
      return 0;
    }
    **(int **)(param_1 + 0x5c) = **(int **)(param_1 + 0x5c) + 1;
  } while( true );
}

