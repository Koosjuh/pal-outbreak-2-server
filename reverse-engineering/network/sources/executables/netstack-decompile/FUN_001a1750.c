
void FUN_001a1750(long param_1,undefined8 param_2,int param_3,ulong param_4)

{
  int iVar1;
  int iVar2;
  long lVar3;
  long lVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  undefined1 auStack_130 [16];
  undefined1 uStack_120;
  undefined1 auStack_30 [4];
  int iStack_2c;
  int iStack_24;
  int iStack_1c;
  int iStack_c;
  
  iVar2 = iRam003435bc;
  if (param_1 == 0) {
    iVar5 = FUN_001cbc30();
    if (iVar5 == -1) {
      return;
    }
    lVar4 = FUN_001cc170(iVar5,param_3,0,0);
    if (lVar4 == 0) {
      return;
    }
    lVar3 = FUN_0010a050(lVar4);
    if (lVar3 == 0) {
      return;
    }
    lVar4 = FUN_0010a6b0(lVar4,0x5c);
    if (lVar4 == 0) {
      return;
    }
    FUN_00109eb8(auStack_130,(int)lVar4 + 1);
    lVar4 = FUN_0010a6b0(auStack_130,0x2e);
    if (lVar4 != 0) {
      *(undefined1 *)lVar4 = 0;
    }
    FUN_00109ab0(auStack_130,0x23ae78);
    uStack_120 = 0;
    lVar4 = FUN_001a0df0(auStack_130,iVar2);
    param_3 = iVar5;
  }
  else {
    if (param_3 == -1) {
      return;
    }
    if ((param_4 & 0x10000) == 0) {
      FUN_00109728(auStack_130,0x23ae88,0x23ae10,param_1);
      lVar4 = FUN_001a0e90(auStack_130,iVar2);
    }
    else {
      FUN_00109728(auStack_130,0x23ae80,param_1,param_1);
      lVar4 = FUN_001a0df0(auStack_130,iVar2);
    }
  }
  if (0 < lVar4) {
    FUN_001069a8(auStack_30,iVar2,0x30);
    FUN_001cbc20(param_3);
    if (iStack_2c != 0) {
      piVar6 = (int *)(iVar2 + iStack_2c);
      iVar7 = iRam003435bc + 0x180000;
      for (iVar5 = 0; iVar5 < iStack_24; iVar5 = iVar5 + 1) {
        iVar1 = *piVar6;
        FUN_001a79b0(piVar6 + 1,iVar7);
        FUN_001cba30(iVar7,param_3);
        param_3 = param_3 + 1;
        piVar6 = (int *)((int)piVar6 + iVar1 + 4);
      }
      FUN_001841d0();
      if ((iStack_1c != 0) && (iStack_c != 0)) {
        FUN_001ce2d0(param_2,param_4 & 0x7fffffff,iVar2 + iStack_1c,iVar2 + iStack_c,0);
        FUN_001841d0();
      }
    }
  }
  return;
}

