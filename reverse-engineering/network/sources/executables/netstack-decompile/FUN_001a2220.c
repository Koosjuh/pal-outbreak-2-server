
void FUN_001a2220(void)

{
  int iVar1;
  long lVar2;
  undefined8 uVar3;
  long lVar4;
  int iVar5;
  int *piVar6;
  undefined4 uStack_10;
  int iStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  FUN_00115300(0);
  FUN_00119aa8();
  FUN_001010a8(0);
  FUN_00116cb8();
  do {
    lVar2 = FUN_0011af28(0x244ed0);
  } while (lVar2 == 0);
  do {
    lVar2 = FUN_0011aed8();
  } while (lVar2 == 0);
  FUN_00115300(0);
  FUN_0011a188();
  FUN_00116cb8();
  FUN_00119aa8();
  FUN_001010a8(0);
  FUN_00101c38(2);
  do {
    lVar2 = FUN_00116cf0(0x244ef0,1);
  } while (lVar2 < 0);
  uVar3 = FUN_001170f8(lVar2,0,2);
  FUN_001170f8(lVar2,0,0);
  FUN_00117330(lVar2,0x1000000,uVar3);
  FUN_00116f78(lVar2);
  do {
    lVar2 = FUN_00119b30(uVar3);
  } while (lVar2 == 0);
  uStack_10 = 0x1000000;
  uStack_8 = (undefined4)uVar3;
  uStack_4 = 0;
  iStack_c = (int)lVar2;
  FlushCache(0);
  uVar3 = sceSifSetDma(&uStack_10,1);
  do {
    lVar4 = sceSifDmaStat(uVar3);
    iVar1 = iRam01000004;
  } while (-1 < lVar4);
  piVar6 = (int *)0x1000008;
  for (iVar5 = 0; iVar5 < iVar1; iVar5 = iVar5 + 1) {
    *piVar6 = *piVar6 + (int)lVar2;
    piVar6 = piVar6 + 2;
  }
  for (piVar6 = &DAT_00244e30; *piVar6 != -1; piVar6 = piVar6 + 3) {
    if (*piVar6 == 10) {
      FUN_0012a748(1,2);
    }
    FUN_001a21c0(0x1000000,*piVar6,piVar6[1],piVar6[2]);
  }
  FUN_00119c98(lVar2);
  FUN_001b4930();
  FUN_00183c90(0x244f10,0x10,0x244f30,0);
  return;
}

