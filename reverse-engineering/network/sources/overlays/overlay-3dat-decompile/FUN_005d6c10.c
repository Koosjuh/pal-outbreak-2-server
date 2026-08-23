FUNCTION FUN_005d6c10 @ 0x005d6c10  size=116
CALLERS (2): FUN_005d78d0@0x005d78d0, FUN_005d7760@0x005d7760
CALLEES (1): FUN_005dedc0@0x005dedc0
----------------------------------------------------------------

int * FUN_005d6c10(int *param_1)

{
  int *piVar1;
  int *piVar2;
  
  piVar1 = param_1;
  do {
    piVar2 = piVar1;
    piVar1 = (int *)*piVar2;
    if (piVar1 == (int *)0x0) {
      return (int *)0x0;
    }
  } while (piVar1[0x41] != 0);
  if (piVar2 != param_1) {
    *piVar2 = *piVar1;
    *piVar1 = *param_1;
    *param_1 = (int)piVar1;
  }
  FUN_005dedc0(piVar1 + 1);
  piVar1[0x41] = 1;
  return piVar1;
}



================================================================