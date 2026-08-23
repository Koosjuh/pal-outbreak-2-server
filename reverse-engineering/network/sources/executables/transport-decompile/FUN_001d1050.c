
void FUN_001d1050(void)

{
  int *piVar1;
  long lVar2;
  undefined8 uVar3;
  int iVar4;
  int *piVar5;
  int *piVar6;
  undefined1 auStack_100 [256];
  
  lVar2 = FUN_001cbcb0(0);
  piVar1 = piRam003435bc;
  if (lVar2 == 0) {
    piVar6 = piRam003435bc + 0x40000;
    uVar3 = FUN_001cf2b0(0x24ce50);
    FUN_00109eb8(auStack_100,uVar3);
    lVar2 = FUN_001cb360(auStack_100,piVar1,1,0);
    if (lVar2 != 0) {
      piVar5 = piVar1;
      for (iVar4 = 0; piVar5 = piVar5 + 2, iVar4 < piVar1[1] + -1; iVar4 = iVar4 + 1) {
      }
      FUN_001a79b0((int)piVar1 + *piVar5,piVar6);
      FUN_001cb5f0(0,piVar6);
    }
  }
  return;
}

