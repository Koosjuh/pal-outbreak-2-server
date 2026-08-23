
void FUN_001a99c0(int param_1)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = 0;
  piVar2 = (int *)0x5a9160;
  while( true ) {
    if (699 < iVar1) {
      return;
    }
    if (*piVar2 == -1) break;
    iVar1 = iVar1 + 1;
    piVar2 = piVar2 + 1;
  }
  *piVar2 = param_1;
  return;
}

