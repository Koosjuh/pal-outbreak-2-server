FUNCTION FUN_005ec430 @ 0x005ec430  size=184
CALLERS (1): FUN_005e9ef0@0x005e9ef0
CALLEES (0): 
----------------------------------------------------------------

void FUN_005ec430(undefined4 *param_1,char *param_2,int param_3)

{
  char cVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  
  pcVar4 = (char *)*param_1;
  iVar3 = 0;
  iVar2 = 0;
LAB_005ec4cc:
  do {
    cVar1 = *pcVar4;
LAB_005ec4d0:
    if ((cVar1 == '\0') || (param_3 + -2 < iVar2)) {
LAB_005ec4d8:
      *param_2 = '\0';
      *param_1 = pcVar4;
      return;
    }
    if (iVar3 != 2) {
      if (iVar3 != 1) {
        if (iVar3 != 0) {
          pcVar4 = pcVar4 + 1;
          goto LAB_005ec4cc;
        }
        iVar3 = 1;
        if (cVar1 != '=') goto LAB_005ec4d8;
        goto LAB_005ec4c8;
      }
      iVar3 = 2;
      if (cVar1 == '\"') goto LAB_005ec4c8;
      cVar1 = *pcVar4;
      goto LAB_005ec4d0;
    }
    if ((cVar1 == '\"') || (cVar1 == ';')) {
      *param_2 = '\0';
      *param_1 = pcVar4;
      return;
    }
    *param_2 = cVar1;
    iVar2 = iVar2 + 1;
    param_2 = param_2 + 1;
LAB_005ec4c8:
    pcVar4 = pcVar4 + 1;
  } while( true );
}



================================================================