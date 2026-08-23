
void FUN_001d1530(undefined8 param_1,undefined4 *param_2)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  undefined8 uVar4;
  long lVar5;
  int *piVar6;
  int *piVar7;
  int iVar8;
  
  FUN_001cbc20(0x4200);
  piVar2 = piRam003435bc;
  piVar7 = piRam003435bc + 0x40000;
  uVar4 = FUN_001cf2b0(0x24cf40);
  lVar5 = FUN_001cb360(uVar4,piVar2,1,0);
  if (lVar5 != 0) {
    iVar1 = piVar2[1];
    piVar6 = piVar2;
    for (iVar8 = 0; piVar6 = piVar6 + 2, iVar8 < iVar1; iVar8 = iVar8 + 1) {
      FUN_001a79b0((int)piVar2 + *piVar6,piVar7);
      FUN_001cb5f0(iVar8 + 0x4200,piVar7);
      uVar3 = FUN_001cbcb0(iVar8 + 0x4200);
      *param_2 = uVar3;
      param_2 = param_2 + 1;
    }
  }
  return;
}

