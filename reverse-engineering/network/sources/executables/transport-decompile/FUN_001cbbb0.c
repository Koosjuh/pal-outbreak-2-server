
void FUN_001cbbb0(int param_1)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = 1;
  piVar2 = (int *)0x36c570;
  while( true ) {
    if (0xff < iVar1) {
      return;
    }
    if (*piVar2 == param_1) break;
    iVar1 = iVar1 + 1;
    piVar2 = piVar2 + 4;
  }
  FUN_001cb490(*piVar2);
  FUN_00106b60(piVar2,0,0x10);
  return;
}

