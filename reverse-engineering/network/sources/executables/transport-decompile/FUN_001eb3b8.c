
undefined4 FUN_001eb3b8(int param_1,int *param_2)

{
  *param_2 = param_1;
  param_2[1] = *(int *)(param_1 + 4);
  *(int **)param_2[1] = param_2;
  *(int **)(param_1 + 4) = param_2;
  *(short *)(param_1 + 0xc) = *(short *)(param_1 + 0xc) + 1;
  return 0;
}

