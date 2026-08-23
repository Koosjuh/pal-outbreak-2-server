
undefined4 FUN_00199d50(undefined2 *param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined8 uVar3;
  long lVar4;
  int iVar5;
  undefined4 *puVar6;
  
  uVar3 = FUN_00199f70(param_2,param_3);
  if (*(int *)uVar3 == 4) {
    lVar4 = FUN_0019a350(uVar3,0x100000,0);
    if (lVar4 == 0) {
      uVar2 = 0xffffffff;
    }
    else {
      iVar1 = *(int *)((int)lVar4 + 4);
      puVar6 = (undefined4 *)((int)lVar4 + 0xc);
      *param_1 = (short)iVar1;
      for (iVar5 = 0; uVar2 = 0, iVar5 < iVar1; iVar5 = iVar5 + 1) {
        param_1[iVar5 + 1] = (short)*puVar6;
        puVar6 = puVar6 + 1;
      }
    }
  }
  else {
    uVar2 = 0xffffffff;
  }
  return uVar2;
}

