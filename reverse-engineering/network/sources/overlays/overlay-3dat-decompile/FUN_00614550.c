FUNCTION FUN_00614550 @ 0x00614550  size=168
CALLERS (1): FUN_006140d0@0x006140d0
CALLEES (0): 
----------------------------------------------------------------

void FUN_00614550(char *param_1,char *param_2)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  char acStack_4 [4];
  
  iVar4 = 0;
  do {
    iVar3 = 0;
    for (; (cVar1 = *param_2, iVar2 = iVar3, cVar1 != '.' && (cVar1 != '\0')); param_2 = param_2 + 1
        ) {
      acStack_4[iVar3] = cVar1;
      iVar3 = iVar3 + 1;
    }
    for (; iVar2 < 3; iVar2 = iVar2 + 1) {
      *param_1 = ' ';
      param_1 = param_1 + 1;
    }
    for (iVar2 = 0; iVar2 < iVar3; iVar2 = iVar2 + 1) {
      *param_1 = acStack_4[iVar2];
      param_1 = param_1 + 1;
    }
    iVar4 = iVar4 + 1;
    *param_1 = *param_2;
    param_2 = param_2 + 1;
    param_1 = param_1 + 1;
  } while (iVar4 < 4);
  *param_1 = '\0';
  return;
}



================================================================