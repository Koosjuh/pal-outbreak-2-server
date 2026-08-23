FUNCTION FUN_005d6b40 @ 0x005d6b40  size=64
CALLERS (4): FUN_005d78d0@0x005d78d0, FUN_005d79e0@0x005d79e0, FUN_005d7760@0x005d7760, FUN_005d7a30@0x005d7a30
CALLEES (0): 
----------------------------------------------------------------

int * FUN_005d6b40(int *param_1)

{
  int *piVar1;
  
  piVar1 = (int *)0x0;
  if (*(int *)(*param_1 + 0x104) != 0) {
    while (param_1 = (int *)*param_1, param_1 != (int *)0x0) {
      if (param_1[0x41] != 0) {
        piVar1 = param_1;
      }
    }
  }
  return piVar1;
}



================================================================