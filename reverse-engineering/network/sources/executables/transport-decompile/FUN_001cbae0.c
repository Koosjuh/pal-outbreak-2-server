
void FUN_001cbae0(int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
LAB_001cbb54:
  do {
    if (param_2 <= iVar3) {
      return;
    }
    piVar1 = (int *)0x36c560;
    for (iVar2 = 0; iVar2 < 0x100; iVar2 = iVar2 + 1) {
      if ((*piVar1 != 0) && (piVar1[1] == param_1 + iVar3)) {
        FUN_001cb530();
        iVar3 = iVar3 + 1;
        goto LAB_001cbb54;
      }
      piVar1 = piVar1 + 4;
    }
    iVar3 = iVar3 + 1;
  } while( true );
}

