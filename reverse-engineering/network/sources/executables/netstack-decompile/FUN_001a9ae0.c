
void FUN_001a9ae0(int param_1)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = 0;
  piVar2 = (int *)0x5a9060;
  do {
    if (*piVar2 == param_1) {
      *piVar2 = -1;
    }
    iVar1 = iVar1 + 1;
    piVar2 = piVar2 + 1;
  } while (iVar1 < 0x40);
  return;
}

