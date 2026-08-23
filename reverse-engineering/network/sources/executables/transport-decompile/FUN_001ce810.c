
undefined4 FUN_001ce810(short param_1)

{
  short sVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  char *pcVar5;
  
  pcVar5 = (char *)0x36c310;
  iVar4 = 0;
  do {
    if (3 < iVar4) {
      return 0;
    }
    if (*pcVar5 != '\0') {
      iVar3 = 0;
      if (*(int *)(pcVar5 + 4) != 0) {
        bVar2 = true;
        while (bVar2) {
          sVar1 = *(short *)(*(int *)(pcVar5 + 4) + iVar3 * 2 + 4);
          if ((sVar1 != 0) && (sVar1 == param_1)) {
            return 1;
          }
          iVar3 = iVar3 + 1;
          bVar2 = iVar3 < 0x640;
        }
      }
    }
    iVar4 = iVar4 + 1;
    pcVar5 = pcVar5 + 0x10;
  } while( true );
}

