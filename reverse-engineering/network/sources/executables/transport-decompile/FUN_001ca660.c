
int FUN_001ca660(char *param_1,int param_2)

{
  char cVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = 0;
  for (iVar3 = 0; iVar3 < param_2; iVar3 = iVar3 + 1) {
    cVar1 = *param_1;
    if (('/' < cVar1) && (cVar1 < ':')) {
      iVar2 = iVar2 * 10 + cVar1 + -0x30;
    }
    param_1 = param_1 + 1;
  }
  return iVar2;
}

