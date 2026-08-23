
int * FUN_001cb4e0(void)

{
  int *piVar1;
  int iVar2;
  
  iVar2 = 0;
  piVar1 = (int *)0x36c560;
  while( true ) {
    if (0xff < iVar2) {
      return (int *)0x0;
    }
    if (*piVar1 == 0) break;
    iVar2 = iVar2 + 1;
    piVar1 = piVar1 + 4;
  }
  return piVar1;
}

