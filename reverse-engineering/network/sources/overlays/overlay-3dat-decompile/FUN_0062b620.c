FUNCTION FUN_0062b620 @ 0x0062b620  size=68
CALLERS (1): FUN_0062b500@0x0062b500
CALLEES (0): 
----------------------------------------------------------------

char * FUN_0062b620(char *param_1)

{
  bool bVar1;
  char *pcVar2;
  
  bVar1 = false;
  pcVar2 = (char *)0x715480;
  do {
    if (*param_1 == '>') {
      bVar1 = true;
    }
    *pcVar2 = *param_1;
    param_1 = param_1 + 1;
    pcVar2 = pcVar2 + 1;
  } while (!bVar1);
  return param_1;
}



================================================================