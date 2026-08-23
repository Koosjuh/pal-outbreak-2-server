
char * FUN_001cdb60(void)

{
  char *pcVar1;
  int iVar2;
  
  iVar2 = 0;
  pcVar1 = (char *)0x36c350;
  while( true ) {
    if (0xf < iVar2) {
      return (char *)0x0;
    }
    if (*pcVar1 == '\0') break;
    iVar2 = iVar2 + 1;
    pcVar1 = pcVar1 + 0xc;
  }
  return pcVar1;
}

