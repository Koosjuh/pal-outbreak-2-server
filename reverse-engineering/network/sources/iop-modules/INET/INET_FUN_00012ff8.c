FUNCTION FUN_00012ff8 @ 0x00012ff8 size=116
CALLERS (1): FUN_0001306c@0x0001306c
CALLEES (0): 

int FUN_00012ff8(int param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  
  if (param_2 == 0) {
    iVar3 = 0;
    if (DAT_0001b348 != 0) {
      piVar2 = &DAT_0001b348;
      iVar1 = DAT_0001b348;
      do {
        piVar2 = piVar2 + 1;
        if (iVar1 < param_1) break;
        iVar1 = *piVar2;
        iVar3 = iVar3 + 1;
      } while (iVar1 != 0);
    }
    param_2 = (&DAT_0001b348)[iVar3];
  }
  iVar3 = 0x44;
  if (0x43 < param_2) {
    iVar3 = param_2;
  }
  return iVar3;
}


================================================================