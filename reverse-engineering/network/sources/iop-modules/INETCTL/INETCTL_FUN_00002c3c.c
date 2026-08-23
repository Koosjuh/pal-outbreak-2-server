FUNCTION FUN_00002c3c @ 0x00002c3c size=252
CALLERS (1): FUN_00002d38@0x00002d38
CALLEES (4): FUN_0000018c@0x0000018c, FUN_00000530@0x00000530, FUN_0000059c@0x0000059c, FUN_00003df0@0x00003df0

void FUN_00002c3c(int *param_1,undefined4 param_2)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 != (int *)0x0) {
    for (param_1 = (int *)*param_1; param_1 != (int *)0x0; param_1 = (int *)*param_1) {
      if ((((param_1[9] != 0) && (piVar2 = *(int **)(param_1[9] + 4), *piVar2 == 2)) &&
          (iVar1 = FUN_00000530(piVar2[1],param_2,2), iVar1 == 0)) &&
         (((iVar1 = FUN_00000530(piVar2[2],param_2,3), iVar1 == 0 &&
           (iVar1 = FUN_0000059c(piVar2[3],param_2), iVar1 == 0)) &&
          (*(char *)((int)piVar2 + 0x12e) != '\0')))) {
        return;
      }
    }
  }
  FUN_0000018c(param_2,0x20001,0,0);
  FUN_00003df0(1000000);
  return;
}


================================================================