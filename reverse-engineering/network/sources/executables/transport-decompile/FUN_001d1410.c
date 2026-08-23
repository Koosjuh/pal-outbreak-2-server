
void FUN_001d1410(undefined4 *param_1)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  undefined8 uVar4;
  long lVar5;
  int *piVar6;
  int iVar7;
  int iVar8;
  int *piVar9;
  undefined1 auStack_100 [256];
  
  piVar2 = piRam003435bc;
  piVar6 = piRam003435bc + 0x40000;
  uVar4 = FUN_001cf2b0(0x24ce50);
  FUN_00109eb8(auStack_100,uVar4);
  lVar5 = FUN_001cb360(auStack_100,piVar2,1,0);
  if (lVar5 != 0) {
    iVar1 = piVar2[1];
    iVar8 = 1;
    iVar7 = 0;
    piVar9 = piVar2;
    while( true ) {
      piVar9 = piVar9 + 2;
      if (iVar1 + -1 <= iVar7) break;
      FUN_001a79b0((int)piVar2 + *piVar9,piVar6);
      FUN_001cb5f0(iVar8,piVar6);
      uVar3 = FUN_001cbcb0(iVar8);
      *param_1 = uVar3;
      iVar8 = iVar8 + 1;
      param_1 = param_1 + 1;
      iVar7 = iVar7 + 1;
    }
  }
  return;
}

