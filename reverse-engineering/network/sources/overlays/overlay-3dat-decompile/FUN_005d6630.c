FUNCTION FUN_005d6630 @ 0x005d6630  size=80
CALLERS (6): FUN_005d7320@0x005d7320, FUN_005d71e0@0x005d71e0, FUN_005d70b0@0x005d70b0, FUN_005d7420@0x005d7420, FUN_005d76b0@0x005d76b0, FUN_005d74a0@0x005d74a0
CALLEES (1): FUN_005dedc0@0x005dedc0
----------------------------------------------------------------

int FUN_005d6630(int *param_1)

{
  do {
    param_1 = (int *)*param_1;
    if (param_1 == (int *)0x0) {
      return 0;
    }
  } while (param_1[0x41] != 0);
  FUN_005dedc0(param_1 + 1);
  param_1[0x41] = 1;
  return (int)param_1;
}



================================================================