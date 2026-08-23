FUNCTION FUN_005deee0 @ 0x005deee0  size=76
CALLERS (2): FUN_005df7b0@0x005df7b0, FUN_005df170@0x005df170
CALLEES (0): 
----------------------------------------------------------------

char * FUN_005deee0(char *param_1,char *param_2)

{
  while( true ) {
    param_2 = param_2 + -1;
    if (*param_2 == '/') {
      return (char *)0x0;
    }
    if (param_2 <= param_1) break;
    if (*param_2 == '.') {
      return param_2;
    }
  }
  return (char *)0x0;
}



================================================================