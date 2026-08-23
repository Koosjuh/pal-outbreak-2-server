FUNCTION FUN_005d6a70 @ 0x005d6a70  size=196
CALLERS (2): FUN_005d78d0@0x005d78d0, FUN_005d7760@0x005d7760
CALLEES (1): FUN_005dedb0@0x005dedb0
----------------------------------------------------------------

int * FUN_005d6a70(int *param_1,undefined8 param_2)

{
  int *piVar1;
  long lVar2;
  int *piVar3;
  int *piVar4;
  int *piVar5;
  
  piVar1 = param_1;
  do {
    piVar5 = piVar1;
    piVar1 = (int *)*piVar5;
    piVar4 = (int *)0x0;
    piVar3 = (int *)0x0;
    if (piVar1 == (int *)0x0) break;
  } while ((piVar1[0x41] == 0) ||
          (lVar2 = FUN_005dedb0(piVar1 + 1,param_2), piVar4 = piVar1, piVar3 = piVar5, lVar2 != 0));
  piVar1 = (int *)0x0;
  if ((piVar4 != (int *)0x0) && (piVar1 = piVar4, piVar4 != (int *)*param_1)) {
    *piVar3 = *piVar4;
    *piVar4 = *param_1;
    *param_1 = (int)piVar4;
  }
  return piVar1;
}



================================================================