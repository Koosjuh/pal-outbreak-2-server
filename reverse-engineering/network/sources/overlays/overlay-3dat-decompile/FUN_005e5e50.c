FUNCTION FUN_005e5e50 @ 0x005e5e50  size=300
CALLERS (2): FUN_005e60c0@0x005e60c0, FUN_005e67a0@0x005e67a0
CALLEES (0): 
----------------------------------------------------------------

undefined4 FUN_005e5e50(char *param_1,int param_2)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  char *pcVar6;
  
  iVar5 = 1;
  iVar4 = 0;
  pcVar6 = *(char **)(iRam007012a0 + 0xd964);
  do {
    while( true ) {
      cVar1 = *pcVar6;
      if (cVar1 == '\0') {
        return 0xffffffff;
      }
      if (iVar5 != 3) break;
      if (cVar1 == '\"') {
        *(char **)(iRam007012a0 + 0xd964) = pcVar6 + 1;
        return 0;
      }
LAB_005e5f60:
      pcVar6 = pcVar6 + 1;
    }
    if (iVar5 == 2) {
      if (cVar1 == '\"') {
        *param_1 = '\0';
        *(char **)(iRam007012a0 + 0xd964) = pcVar6 + 1;
        return 0;
      }
      if (cVar1 == '\r') {
        pcVar6 = pcVar6 + 1;
      }
      if (*pcVar6 == '\n') {
        pcVar6 = pcVar6 + 1;
      }
      iVar3 = iVar4 + 1;
      iVar2 = iVar4 + 2;
      *param_1 = *pcVar6;
      param_1 = param_1 + 1;
      iVar4 = iVar3;
      if (param_2 < iVar2) {
        *param_1 = '\0';
        iVar5 = 3;
      }
      goto LAB_005e5f60;
    }
    if (iVar5 == 1) {
      if (cVar1 == '\"') {
        iVar5 = 2;
      }
      else if (cVar1 == '<') {
        return 1;
      }
      goto LAB_005e5f60;
    }
    pcVar6 = pcVar6 + 1;
  } while( true );
}



================================================================