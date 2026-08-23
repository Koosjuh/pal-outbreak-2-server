FUNCTION FUN_005df0b0 @ 0x005df0b0  size=84
CALLERS (1): FUN_005df340@0x005df340
CALLEES (0): 
----------------------------------------------------------------

char * FUN_005df0b0(char *param_1,char *param_2)

{
  char *pcVar1;
  
  for (; (pcVar1 = (char *)0x0, param_1 + 2 < param_2 &&
         (((*param_1 != '/' || (param_1[1] != '.')) || (pcVar1 = param_1, param_1[2] != '/'))));
      param_1 = param_1 + 1) {
  }
  return pcVar1;
}



================================================================