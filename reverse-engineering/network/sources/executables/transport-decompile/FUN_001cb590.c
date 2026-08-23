
int * FUN_001cb590(int param_1)

{
  int *piVar1;
  int iVar2;
  
  iVar2 = 0;
  piVar1 = (int *)0x36c560;
  while( true ) {
    if (0xff < iVar2) {
      return (int *)0x0;
    }
    if ((*piVar1 != 0) && (piVar1[1] == param_1)) break;
    iVar2 = iVar2 + 1;
    piVar1 = piVar1 + 4;
  }
  *(short *)((int)piVar1 + 0xe) = *(short *)((int)piVar1 + 0xe) + 1;
  return piVar1;
}

