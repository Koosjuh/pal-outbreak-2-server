
long FUN_001cb750(int param_1,undefined2 param_2,undefined2 param_3)

{
  int iVar1;
  long lVar2;
  int *piVar3;
  
  lVar2 = FUN_001cb4e0();
  if (lVar2 == 0) {
    lVar2 = 0;
  }
  else {
    iVar1 = func_0x003ad230(0);
    piVar3 = (int *)lVar2;
    *piVar3 = iVar1;
    if (*piVar3 == 0) {
      FUN_001cb530(lVar2);
      lVar2 = 0;
    }
    else {
      piVar3[1] = param_1;
      *(undefined2 *)(piVar3 + 2) = param_2;
      *(undefined2 *)((int)piVar3 + 10) = param_3;
      *(undefined2 *)(piVar3 + 3) = 4;
      *(undefined2 *)((int)piVar3 + 0xe) = 1;
    }
  }
  return lVar2;
}

