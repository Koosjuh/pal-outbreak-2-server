FUNCTION FUN_000081fc @ 0x000081fc size=620
CALLERS (1): FUN_00000b24@0x00000b24
CALLEES (0): 

undefined4 FUN_000081fc(char *param_1,char *param_2,int param_3)

{
  char cVar1;
  char *pcVar2;
  char *pcVar3;
  int iVar4;
  
  iVar4 = 0;
  do {
    do {
      pcVar2 = param_1;
      param_1 = pcVar2 + 1;
    } while (*pcVar2 == ' ');
    param_1 = pcVar2 + 1;
  } while (*pcVar2 == '\t');
  if (((*pcVar2 == '\"') && (pcVar2[1] == '\"')) && ((pcVar2[2] == ' ' || (pcVar2[2] == '\t')))) {
    pcVar2 = pcVar2 + 3;
    while( true ) {
      do {
        do {
          pcVar3 = pcVar2;
          pcVar2 = pcVar3 + 1;
        } while (*pcVar3 == ' ');
        pcVar2 = pcVar3 + 1;
      } while (*pcVar3 == '\t');
      cVar1 = *pcVar3;
      if (cVar1 == '\0') {
        return 0;
      }
      if (cVar1 == '\\') break;
      if ((cVar1 != 'A') && (cVar1 != 'a')) {
        return 0;
      }
      if ((pcVar3[1] != 'T') && (pcVar3[1] != 't')) {
        return 0;
      }
      if (0 < iVar4) {
        param_3 = param_3 + -1;
        if (param_3 < 1) {
          return 0xffffffed;
        }
        *param_2 = ' ';
        param_2 = param_2 + 1;
      }
      cVar1 = *pcVar3;
      pcVar2 = pcVar3;
      if ((*pcVar3 != '\0') && (pcVar2 = pcVar3 + 1, *pcVar3 != ' ')) {
        while (pcVar2 = pcVar3, cVar1 != '\t') {
          param_3 = param_3 + -1;
          if (param_3 < 1) {
            return 0xffffffed;
          }
          if (cVar1 == '\\') {
            cVar1 = pcVar3[1];
            if ((((cVar1 != '-') && (cVar1 != '\\')) && (cVar1 != '\"')) && (cVar1 != '^')) {
              return 0;
            }
            pcVar3 = pcVar3 + 1;
          }
          cVar1 = *pcVar3;
          pcVar3 = pcVar3 + 1;
          *param_2 = cVar1;
          cVar1 = *pcVar3;
          param_2 = param_2 + 1;
          pcVar2 = pcVar3;
          if ((*pcVar3 == '\0') || (*pcVar3 == ' ')) break;
        }
      }
      do {
        do {
          pcVar3 = pcVar2;
          pcVar2 = pcVar3 + 1;
        } while (*pcVar3 == ' ');
        pcVar2 = pcVar3 + 1;
      } while (*pcVar3 == '\t');
      if (*pcVar3 != 'O') {
        return 0;
      }
      if (pcVar3[1] != 'K') {
        return 0;
      }
      if ((pcVar3[2] != ' ') && (pcVar3[2] != '\t')) {
        return 0;
      }
      iVar4 = iVar4 + 1;
      pcVar2 = pcVar3 + 3;
    }
    pcVar2 = pcVar3 + 2;
    if (pcVar3[1] == 'c') {
      do {
        do {
          pcVar3 = pcVar2;
          pcVar2 = pcVar3 + 1;
        } while (*pcVar3 == ' ');
        pcVar2 = pcVar3 + 1;
      } while (*pcVar3 == '\t');
      if (*pcVar3 != '\0') {
        return 0xffffffed;
      }
      if (0 < iVar4) {
        if (param_3 + -1 < 0) {
          return 0xffffffed;
        }
        *param_2 = '\0';
        return 1;
      }
    }
  }
  return 0;
}


================================================================