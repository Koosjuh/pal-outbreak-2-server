
int FUN_001eb4dc(int param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = FUN_001ebe64(param_1,1);
  if (iVar1 == 0) {
    *(int *)param_2[1] = *param_2;
    *(int *)(*param_2 + 4) = param_2[1];
    *(short *)(param_1 + 0xc) = *(short *)(param_1 + 0xc) + -1;
    iVar1 = FUN_001ebe64(param_1,2);
  }
  return iVar1;
}

