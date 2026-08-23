
void FUN_001d12c0(void)

{
  int *piVar1;
  int *piVar2;
  long lVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int *piVar8;
  int *piVar9;
  undefined1 auStack_100 [256];
  
  piVar1 = piRam003435bc;
  piVar9 = piRam003435bc + 0x40000;
  FUN_00109eb8(auStack_100,0x24cf00);
  lVar3 = FUN_001cb360(auStack_100,piVar1,1,0);
  if (lVar3 != 0) {
    iVar7 = piVar1[1];
    iVar6 = 1;
    if (4 < iVar7) {
      iVar7 = 4;
    }
    iVar5 = 0;
    piVar8 = piVar1;
    while( true ) {
      piVar2 = piRam003435bc;
      piVar8 = piVar8 + 2;
      if (iVar7 <= iVar5) break;
      FUN_001a79b0((int)piVar1 + *piVar8,piVar9);
      iVar4 = iVar6;
      if (iVar5 == iVar7 + -1) {
        iVar4 = 10;
      }
      iVar6 = iVar4 + 1;
      FUN_001cb5f0(iVar4,piVar9);
      iVar5 = iVar5 + 1;
    }
    lVar3 = FUN_001cb360(0x24cf20,piRam003435bc,1,0);
    if (lVar3 != 0) {
      FUN_001cb5f0(5,piVar2);
    }
  }
  return;
}

