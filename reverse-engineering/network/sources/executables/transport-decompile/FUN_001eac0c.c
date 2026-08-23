
undefined8 FUN_001eac0c(int param_1,short param_2,undefined4 param_3)

{
  int iVar1;
  short sStack_24;
  short sStack_22;
  undefined4 uStack_20;
  int iStack_1c;
  int iStack_18;
  
  iStack_1c = param_1;
  FUN_001069a8(&sStack_24,param_1,2);
  iStack_1c = iStack_1c + 2;
  for (iStack_18 = 0; iVar1 = iStack_1c, (long)iStack_18 < (long)sStack_24;
      iStack_18 = iStack_18 + 1) {
    FUN_001069a8(&sStack_22,iStack_1c,2);
    iVar1 = iStack_1c + 2;
    if (sStack_22 == param_2) break;
    iStack_1c = iStack_1c + 6;
  }
  iStack_1c = iVar1;
  if ((long)iStack_18 == (long)sStack_24) {
    sStack_24 = sStack_24 + 1;
    FUN_001069a8(param_1,&sStack_24,2);
    sStack_22 = param_2;
    FUN_001069a8(iStack_1c,&sStack_22,2);
    iStack_1c = iStack_1c + 2;
  }
  uStack_20 = param_3;
  FUN_001069a8(iStack_1c,&uStack_20,4);
  return 0;
}

