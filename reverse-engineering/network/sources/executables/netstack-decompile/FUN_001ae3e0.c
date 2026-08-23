
int FUN_001ae3e0(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  long lVar3;
  undefined8 uVar4;
  undefined4 uStack_4;
  
  if (iRam002a6598 == 2) {
    iVar1 = 0;
    uStack_4 = param_1;
    while (lVar3 = FUN_001ade00(&uStack_4), lVar3 != 0) {
      if (iRam002a6628 == 0) {
        if (lVar3 < 0x10) {
          iVar1 = iVar1 + 2;
        }
        else {
          if (0x7f < lVar3) goto LAB_001ae464;
          iVar1 = iVar1 + 1;
        }
      }
      else {
LAB_001ae464:
        uVar4 = FUN_001adf30(0x2a6590,lVar3);
        lVar3 = FUN_001ae1a0(0x2a6590,uVar4);
        if (lVar3 == 0) {
          iVar2 = 2;
        }
        else {
          iVar2 = 1;
        }
        iVar1 = iVar1 + iVar2;
      }
    }
  }
  else {
    iVar1 = FUN_0010a050();
  }
  return iVar1;
}

