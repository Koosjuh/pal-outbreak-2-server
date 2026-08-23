
undefined4 FUN_001cba30(undefined8 param_1,int param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  long lVar3;
  int iVar4;
  
  iVar4 = param_2;
  if ((param_2 == -1) && (iVar4 = DAT_0024c7f8, DAT_0024c7f8 == -1)) {
    uVar2 = 0;
  }
  else {
    lVar3 = FUN_001cb590(iVar4,param_2,param_1);
    if (lVar3 == 0) {
      puVar1 = (undefined4 *)FUN_001cb5f0();
      uVar2 = *puVar1;
    }
    else {
      uVar2 = *(undefined4 *)lVar3;
    }
  }
  return uVar2;
}

