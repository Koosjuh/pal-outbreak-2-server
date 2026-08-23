
int FUN_001caf60(undefined8 param_1)

{
  int iVar1;
  long lVar2;
  undefined8 uVar3;
  
  iVar1 = FUN_001caed0(0,0x35a690);
  if ((-1 < iVar1) && (lVar2 = FUN_001bf140(0x35a690), lVar2 != 0)) {
    iVar1 = 0;
    while (lVar2 = FUN_001bf140(0x35a690), lVar2 != 0) {
      uVar3 = FUN_001bf170(0x35a690);
      FUN_001069a8(param_1,uVar3,lVar2);
      FUN_001bf230(0x35a690,lVar2);
      iVar1 = iVar1 + (int)lVar2;
    }
  }
  return iVar1;
}

