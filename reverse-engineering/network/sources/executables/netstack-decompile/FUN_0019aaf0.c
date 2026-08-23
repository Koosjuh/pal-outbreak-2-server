
undefined8 FUN_0019aaf0(undefined8 param_1,undefined8 param_2,uint param_3)

{
  int iVar1;
  undefined2 uVar2;
  long lVar3;
  undefined8 uVar4;
  
  FUN_0019a2f0(param_2);
  lVar3 = FUN_0019a350();
  if (lVar3 == 0) {
    uVar4 = 0;
  }
  else if (param_3 < *(uint *)((int)lVar3 + 4)) {
    lVar3 = FUN_00199f70(param_2,param_3);
    if (lVar3 == 0) {
      uVar4 = 0;
    }
    else {
      iVar1 = *(int *)lVar3;
      if (iVar1 == 4) {
        uVar2 = FUN_0019a210(param_2,param_3);
        *(undefined2 *)((int)param_1 + 0x20) = uVar2;
        uVar4 = FUN_0019abf0(param_1,lVar3);
      }
      else if ((((iVar1 == 8) || (iVar1 == 7)) || (iVar1 == 6)) || (iVar1 == 3)) {
        uVar4 = 0;
      }
      else {
        uVar4 = 0;
      }
    }
  }
  else {
    uVar4 = 0;
  }
  return uVar4;
}

