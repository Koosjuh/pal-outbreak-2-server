FUNCTION FUN_00001b80 @ 0x00001b80 size=236
CALLERS (1): FUN_00001c6c@0x00001c6c
CALLEES (3): FUN_0000018c@0x0000018c, FUN_00000530@0x00000530, FUN_0000059c@0x0000059c

void FUN_00001b80(int *param_1,undefined4 param_2)

{
  int iVar1;
  int *piVar2;
  
  for (param_1 = (int *)*param_1; param_1 != (int *)0x0; param_1 = (int *)*param_1) {
    iVar1 = param_1[9];
    if ((((iVar1 != 0) && (*(int *)(iVar1 + 8) == 0)) &&
        (piVar2 = *(int **)(iVar1 + 4), *piVar2 == 2)) &&
       (((*(char *)((int)piVar2 + 0x12e) != '\0' &&
         (iVar1 = FUN_00000530(piVar2[1],param_2,2), iVar1 == 0)) &&
        ((iVar1 = FUN_00000530(piVar2[2],param_2,3), iVar1 == 0 &&
         (iVar1 = FUN_0000059c(piVar2[3],param_2), iVar1 == 0)))))) {
      FUN_0000018c(param_2,0x20000,0,0);
    }
  }
  return;
}


================================================================