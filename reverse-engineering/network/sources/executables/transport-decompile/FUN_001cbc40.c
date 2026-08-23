
int FUN_001cbc40(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int extraout_a2_lo;
  int *piVar4;
  
  iVar1 = FUN_001cba90(DAT_0024c7f8,param_2,param_1);
  iVar3 = 0;
  for (piVar4 = (int *)0x36c560;
      (iVar2 = 0, iVar3 < 0x100 &&
      ((iVar2 = *piVar4, iVar2 == 0 || (piVar4[1] != extraout_a2_lo + iVar1)))); piVar4 = piVar4 + 4
      ) {
    iVar3 = iVar3 + 1;
  }
  return iVar2;
}

