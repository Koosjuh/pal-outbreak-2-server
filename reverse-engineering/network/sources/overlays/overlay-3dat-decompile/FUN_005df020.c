FUNCTION FUN_005df020 @ 0x005df020  size=52
CALLERS (1): FUN_005df170@0x005df170
CALLEES (0): 
----------------------------------------------------------------

char * FUN_005df020(char *param_1,char *param_2)

{
  char *pcVar1;
  
  for (; (pcVar1 = (char *)0x0, param_1 < param_2 && (pcVar1 = param_1, *param_1 != '/'));
      param_1 = param_1 + 1) {
  }
  return pcVar1;
}



================================================================