
void FUN_001d1110(void)

{
  undefined8 uVar1;
  long lVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined1 auStack_100 [256];
  
  iVar3 = iRam003435bc;
  iVar6 = 0x2600;
  iVar4 = iRam003435bc + 0x100000;
  uVar1 = FUN_001cf2b0(0x24ce90);
  FUN_00109eb8(auStack_100,uVar1);
  lVar2 = FUN_001cb360(auStack_100,iVar3,1,0);
  if (lVar2 != 0) {
    FUN_001a79b0(iVar3,iVar4);
    iVar3 = 0;
    do {
      iVar5 = iVar4 + *(int *)(&DAT_0024ce80 + iVar3 * 4);
      FUN_001cb5f0(iVar6,iVar5);
      iVar3 = iVar3 + 1;
      iVar6 = iVar6 + 1;
    } while (iVar3 < 4);
    lVar2 = FUN_001cbcb0(iVar6);
    if (lVar2 == 0) {
      if (cRam00343577 == '\0') {
        FUN_00109728(auStack_100,0x24ceb8,0x24ced0,uRam0034357a);
        uVar1 = FUN_001cf2b0(auStack_100);
        FUN_00109eb8(auStack_100,uVar1);
        lVar2 = FUN_001cb360(auStack_100,iVar5,1,0);
        if (lVar2 != 0) {
          FUN_001cb5f0(iVar6,iVar5);
        }
      }
      else {
        FUN_00109728(auStack_100,0x24cef0,uRam0034357a);
        uVar1 = FUN_001cf2b0(auStack_100);
        FUN_00109eb8(auStack_100,uVar1);
        lVar2 = FUN_001cb360(auStack_100,iVar5,0x10001,0);
        FUN_001a79b0(iVar5,iVar4);
        if (lVar2 != 0) {
          FUN_001cb5f0(iVar6,iVar4);
        }
      }
    }
  }
  return;
}

