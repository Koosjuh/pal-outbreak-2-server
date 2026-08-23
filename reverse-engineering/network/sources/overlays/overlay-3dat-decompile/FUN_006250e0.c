FUNCTION FUN_006250e0 @ 0x006250e0  size=168
CALLERS (1): FUN_00625190@0x00625190
CALLEES (0): 
----------------------------------------------------------------

void FUN_006250e0(uint *param_1)

{
  char cVar1;
  
  cVar1 = *(char *)(iRam00715da8 + 0x49e);
  if (cVar1 == 'R') {
    *param_1 = *param_1 | 1;
  }
  else if (cVar1 == 'Q') {
    *param_1 = *param_1 | 2;
  }
  else if (cVar1 == 'O') {
    *param_1 = *param_1 | 8;
  }
  else {
    if (cVar1 == 'P') {
      *param_1 = *param_1 | 4;
    }
    if (cVar1 == '(') {
      *param_1 = *param_1 | 0x10;
    }
    if (cVar1 == ')') {
      *param_1 = *param_1 | 0x200;
    }
  }
  return;
}



================================================================