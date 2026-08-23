FUNCTION FUN_00008940 @ 0x00008940 size=420
CALLERS (4): FUN_00003f98@0x00003f98, FUN_00002220@0x00002220, FUN_00005ee4@0x00005ee4, FUN_000032bc@0x000032bc
CALLEES (0): 

char * FUN_00008940(char *param_1,char *param_2,char *param_3)

{
  char cVar1;
  char cVar2;
  char *pcVar3;
  char *pcVar4;
  
  if ((param_2 == (char *)0x0) || (pcVar4 = param_2, *param_2 == '\0')) {
    return (char *)0x0;
  }
  do {
    pcVar3 = pcVar4 + 1;
    if (*pcVar4 == ':') {
      return param_2;
    }
    pcVar4 = pcVar3;
  } while (*pcVar3 != '\0');
  if ((param_1 == (char *)0x0) || (pcVar4 = param_1, *param_1 == '\0')) {
    return param_2;
  }
  do {
    pcVar3 = pcVar4;
    pcVar4 = pcVar3 + 1;
  } while (pcVar3[1] != '\0');
  pcVar4 = param_3;
  if ((*param_2 == '/') || (*param_2 == '\\')) {
    for (; param_1 < pcVar3; pcVar3 = pcVar3 + -1) {
      if (*pcVar3 == ':') goto LAB_00008a8c;
    }
LAB_00008a6c:
    cVar1 = *pcVar3;
    if (((cVar1 != ':') && (cVar1 != '/')) && (cVar1 != '\\')) goto joined_r0x00008a98;
  }
  else {
    if (pcVar3 <= param_1) goto LAB_00008a6c;
    cVar2 = *pcVar3;
    cVar1 = *pcVar3;
    while (cVar1 != ':') {
      if (((cVar1 == '/') || (cVar2 == '\\')) || (pcVar3 = pcVar3 + -1, pcVar3 <= param_1))
      goto LAB_00008a6c;
      cVar2 = *pcVar3;
      cVar1 = *pcVar3;
    }
  }
LAB_00008a8c:
  pcVar3 = pcVar3 + 1;
joined_r0x00008a98:
  for (; param_1 < pcVar3; param_1 = param_1 + 1) {
    *pcVar4 = *param_1;
    pcVar4 = pcVar4 + 1;
  }
  while( true ) {
    cVar1 = *param_2;
    cVar2 = *param_2;
    param_2 = param_2 + 1;
    if (cVar1 == '\0') break;
    *pcVar4 = cVar2;
    pcVar4 = pcVar4 + 1;
  }
  *pcVar4 = '\0';
  return param_3;
}


================================================================