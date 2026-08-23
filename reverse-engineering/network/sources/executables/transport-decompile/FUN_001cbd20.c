
int FUN_001cbd20(int param_1,long param_2)

{
  int iVar1;
  long lVar2;
  int iVar3;
  int *piVar4;
  
  if (param_2 < 6) {
    lVar2 = (long)*(short *)(param_1 + (int)param_2 * 2);
    if (lVar2 == -1) {
      iVar1 = 0;
    }
    else {
      iVar3 = 0;
      for (piVar4 = (int *)0x36c560;
          (iVar1 = 0, iVar3 < 0x100 && ((iVar1 = *piVar4, iVar1 == 0 || (piVar4[1] != lVar2))));
          piVar4 = piVar4 + 4) {
        iVar3 = iVar3 + 1;
      }
    }
  }
  else {
    iVar1 = 0;
  }
  return iVar1;
}

