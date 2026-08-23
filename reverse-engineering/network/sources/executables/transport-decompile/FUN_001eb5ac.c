
int FUN_001eb5ac(int param_1,int *param_2,int *param_3)

{
  int iVar1;
  
  iVar1 = FUN_001ebe64(param_1,1);
  if (iVar1 == 0) {
    *param_3 = *param_2;
    param_3[1] = (int)param_2;
    *param_2 = (int)param_3;
    *(int **)(*param_3 + 4) = param_3;
    *(short *)(param_1 + 0xc) = *(short *)(param_1 + 0xc) + 1;
    iVar1 = FUN_001ebe64(param_1,2);
  }
  return iVar1;
}

