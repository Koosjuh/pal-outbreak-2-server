FUNCTION FUN_000019b4 @ 0x000019b4 size=68
CALLERS (0): 
CALLEES (1): FUN_00001850@0x00001850

void FUN_000019b4(char *param_1)

{
  for (; *param_1 != '\0'; param_1 = param_1 + 1) {
    FUN_00001850((int)*param_1);
  }
  return;
}


================================================================