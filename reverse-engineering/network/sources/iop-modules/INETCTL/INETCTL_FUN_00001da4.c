FUNCTION FUN_00001da4 @ 0x00001da4 size=136
CALLERS (1): FUN_0000203c@0x0000203c
CALLEES (1): FUN_00001c6c@0x00001c6c

int FUN_00001da4(undefined4 param_1)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  
  piVar3 = *(int **)(PTR_DAT_000045e0 + 0x18);
  if (piVar3 == (int *)0x0) {
    iVar1 = 0;
  }
  else {
    for (piVar2 = (int *)*piVar3; piVar2 != (int *)0x0; piVar2 = (int *)*piVar2) {
      iVar1 = FUN_00001c6c(piVar3,piVar2,param_1);
      if (iVar1 != 0) {
        return (int)piVar2;
      }
    }
    iVar1 = FUN_00001c6c(piVar3,DAT_000045ec,param_1);
  }
  return iVar1;
}


================================================================