FUNCTION FUN_005c39e0 @ 0x005c39e0  size=84
CALLERS (0): 
CALLEES (1): FUN_005c7d00@0x005c7d00
----------------------------------------------------------------

void FUN_005c39e0(char *param_1)

{
  FUN_005c7d00();
  if (*param_1 == '\0') {
    uRam006cba7d = 1;
  }
  else if (*param_1 == '\'') {
    uRam006cba7d = 2;
  }
  return;
}



================================================================