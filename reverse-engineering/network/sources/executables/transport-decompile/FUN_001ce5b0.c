
char * FUN_001ce5b0(void)

{
  char *pcVar1;
  int iVar2;
  
  iVar2 = 0;
  pcVar1 = (char *)0x36c310;
  while( true ) {
    if (3 < iVar2) {
      return (char *)0x0;
    }
    if (*pcVar1 == '\0') break;
    iVar2 = iVar2 + 1;
    pcVar1 = pcVar1 + 0x10;
  }
  return pcVar1;
}

