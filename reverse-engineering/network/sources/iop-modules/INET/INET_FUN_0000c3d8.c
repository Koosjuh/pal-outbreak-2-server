FUNCTION FUN_0000c3d8 @ 0x0000c3d8 size=108
CALLERS (1): FUN_0000c444@0x0000c444
CALLEES (0): 

void FUN_0000c3d8(char *param_1,char *param_2)

{
  char cVar1;
  int iVar2;
  
  cVar1 = *param_2;
  while (iVar2 = (int)cVar1, 0 < iVar2) {
    for (; param_2 = param_2 + 1, 0 < iVar2; iVar2 = iVar2 + -1) {
      *param_1 = *param_2;
      param_1 = param_1 + 1;
    }
    if (*param_2 != '\0') {
      *param_1 = '.';
      param_1 = param_1 + 1;
    }
    cVar1 = *param_2;
  }
  *param_1 = '\0';
  return;
}


================================================================