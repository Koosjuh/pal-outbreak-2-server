
int FUN_001cbcb0(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  
  iVar1 = FUN_001cba90();
  iVar3 = 0;
  for (piVar4 = (int *)0x36c560;
      (iVar2 = 0, iVar3 < 0x100 && ((iVar2 = *piVar4, iVar2 == 0 || (piVar4[1] != iVar1))));
      piVar4 = piVar4 + 4) {
    iVar3 = iVar3 + 1;
  }
  return iVar2;
}

