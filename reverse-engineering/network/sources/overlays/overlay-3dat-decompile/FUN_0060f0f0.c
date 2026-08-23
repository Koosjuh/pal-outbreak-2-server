FUNCTION FUN_0060f0f0 @ 0x0060f0f0  size=92
CALLERS (2): FUN_0060e440@0x0060e440, FUN_0060e820@0x0060e820
CALLEES (0): 
----------------------------------------------------------------

void FUN_0060f0f0(char *param_1,char *param_2)

{
  char cVar1;
  char cVar2;
  
  cVar2 = '\0';
  while( true ) {
    cVar1 = *param_1;
    if (cVar1 == '\0') break;
    if (cVar1 == '.') {
      *param_2 = cVar2;
      param_2 = param_2 + 1;
      cVar2 = '\0';
    }
    else {
      cVar2 = cVar2 * '\n' + cVar1 + -0x30;
    }
    param_1 = param_1 + 1;
  }
  *param_2 = cVar2;
  return;
}



================================================================