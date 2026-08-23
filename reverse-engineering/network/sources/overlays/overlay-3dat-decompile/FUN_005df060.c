FUNCTION FUN_005df060 @ 0x005df060  size=68
CALLERS (2): FUN_005df170@0x005df170, FUN_005df340@0x005df340
CALLEES (0): 
----------------------------------------------------------------

char * FUN_005df060(char *param_1,char *param_2)

{
  char *pcVar1;
  
  for (; (pcVar1 = (char *)0x0, param_1 + 1 < param_2 &&
         ((*param_1 != '/' || (pcVar1 = param_1, param_1[1] != '/')))); param_1 = param_1 + 1) {
  }
  return pcVar1;
}



================================================================