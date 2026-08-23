
undefined4 FUN_001eb434(int *param_1,int *param_2)

{
  int *piVar1;
  undefined4 uStack_24;
  
  uStack_24 = 0;
  piVar1 = (int *)*param_1;
  if (piVar1 == param_1) {
    *param_2 = 0;
    uStack_24 = 0xffffe4aa;
  }
  else {
    *param_1 = *piVar1;
    *(int **)(*param_1 + 4) = param_1;
    *param_2 = (int)piVar1;
    *(short *)(param_1 + 3) = (short)param_1[3] + -1;
  }
  return uStack_24;
}

