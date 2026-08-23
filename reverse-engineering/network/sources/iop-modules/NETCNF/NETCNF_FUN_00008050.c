FUNCTION FUN_00008050 @ 0x00008050 size=428
CALLERS (1): FUN_00000aac@0x00000aac
CALLEES (0): 

undefined4 FUN_00008050(char *param_1,undefined1 *param_2,int param_3)

{
  char cVar1;
  char cVar2;
  char *pcVar3;
  char *pcVar4;
  int iVar5;
  int iVar6;
  
  param_3 = param_3 + -3;
  iVar6 = 0;
  if (0 < param_3) {
    *param_2 = 0x22;
    param_2[1] = 0x22;
    param_2[2] = 0x20;
    pcVar4 = param_2 + 3;
    while( true ) {
      do {
        do {
          pcVar3 = param_1;
          param_1 = pcVar3 + 1;
        } while (*pcVar3 == ' ');
        param_1 = pcVar3 + 1;
      } while (*pcVar3 == '\t');
      cVar1 = *pcVar3;
      cVar2 = *pcVar3;
      if (cVar1 == '\0') break;
      if ((cVar1 != 'A') && (cVar1 != 'a')) {
        return 0;
      }
      if ((pcVar3[1] != 'T') && (pcVar3[1] != 't')) {
        return 0;
      }
      iVar5 = param_3;
      if (cVar1 != ' ') {
        while (iVar5 = param_3, cVar2 != '\t') {
          iVar5 = param_3 + -1;
          if (iVar5 < 1) {
            return 0xffffffed;
          }
          if ((((cVar2 == '-') || (cVar2 == '\\')) || (cVar2 == '\"')) || (cVar2 == '^')) {
            iVar5 = param_3 + -2;
            if (iVar5 < 1) {
              return 0xffffffed;
            }
            *pcVar4 = '\\';
            pcVar4 = pcVar4 + 1;
          }
          cVar1 = *pcVar3;
          pcVar3 = pcVar3 + 1;
          *pcVar4 = cVar1;
          cVar2 = *pcVar3;
          pcVar4 = pcVar4 + 1;
          if ((*pcVar3 == '\0') || (param_3 = iVar5, *pcVar3 == ' ')) break;
        }
      }
      param_3 = iVar5 + -4;
      if (param_3 < 1) {
        return 0xffffffed;
      }
      builtin_strncpy(pcVar4," OK ",4);
      pcVar4 = pcVar4 + 4;
      iVar6 = iVar6 + 1;
      param_1 = pcVar3;
    }
    if (iVar6 < 1) {
      return 0;
    }
    if (0 < param_3 + -2) {
      *pcVar4 = '\\';
      pcVar4[1] = 'c';
      pcVar4[2] = '\0';
      return 1;
    }
  }
  return 0xffffffed;
}


================================================================