FUNCTION FUN_00008cc8 @ 0x00008cc8 size=116
CALLERS (1): FUN_000091c8@0x000091c8
CALLEES (0): 

void FUN_00008cc8(int param_1,int param_2)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  
  iVar3 = 0;
  piVar2 = &DAT_0000c340;
  piVar1 = &DAT_0000c220;
  while ((*piVar1 != param_1 || (*piVar2 != param_2))) {
    piVar2 = piVar2 + 0x49;
    iVar3 = iVar3 + 1;
    piVar1 = piVar1 + 0x49;
    if (3 < iVar3) {
      return;
    }
  }
  *piVar1 = -1;
  *piVar2 = 0;
  DAT_0000c6b0 = DAT_0000c6b0 + -1;
  return;
}


================================================================