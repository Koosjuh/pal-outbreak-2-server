FUNCTION FUN_005deea0 @ 0x005deea0  size=52
CALLERS (2): FUN_005df170@0x005df170, FUN_005df340@0x005df340
CALLEES (0): 
----------------------------------------------------------------

char * FUN_005deea0(char *param_1,char *param_2)

{
  do {
    param_2 = param_2 + -1;
    if (*param_2 == '/') {
      return param_2;
    }
  } while (param_1 < param_2);
  return (char *)0x0;
}



================================================================