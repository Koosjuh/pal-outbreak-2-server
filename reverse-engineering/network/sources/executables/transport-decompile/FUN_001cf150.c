
int FUN_001cf150(uint param_1)

{
  int *piVar1;
  undefined8 uVar2;
  long lVar3;
  int iVar4;
  int *piVar5;
  int *piVar6;
  int iVar7;
  undefined1 auStack_100 [256];
  
  piVar1 = piRam003435bc;
  iVar7 = 0;
  uRam0034362c = param_1;
  uVar2 = FUN_001cf2b0(0x24cb10);
  lVar3 = FUN_001cb360(uVar2,piVar1,1,0);
  if (lVar3 != 0) {
    piVar6 = piVar1;
    for (iVar7 = 0; iVar7 < piVar1[1] + -1; iVar7 = iVar7 + 1) {
      piVar6 = piVar6 + 2;
    }
    iVar7 = piVar6[3];
    FUN_001069a8(param_1,(int)piVar1 + piVar6[2],iVar7);
    param_1 = iVar7 + param_1 + 0x3f & 0xffffffc0;
  }
  uRam00343628 = param_1;
  FUN_00109728(auStack_100,0x24cb40,uRam0034357a);
  uVar2 = FUN_001cf2b0(auStack_100);
  lVar3 = FUN_001cb360(uVar2,piVar1,0x10001,0);
  if (lVar3 != 0) {
    iVar4 = 0;
    piVar6 = piVar1 + 2;
    do {
      piVar5 = piVar6;
      iVar4 = iVar4 + 1;
      piVar6 = piVar5 + 2;
    } while (iVar4 < 3);
    iVar7 = iVar7 + piVar5[3];
    FUN_001069a8(param_1,(int)piVar1 + *piVar6);
  }
  return iVar7;
}

