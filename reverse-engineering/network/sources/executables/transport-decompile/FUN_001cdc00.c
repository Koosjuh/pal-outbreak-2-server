
char * FUN_001cdc00(char param_1,short param_2)

{
  char *pcVar1;
  int iVar2;
  
  pcVar1 = (char *)0x36c350;
  iVar2 = 0;
  while( true ) {
    if (0xf < iVar2) {
      return (char *)0x0;
    }
    if (((*pcVar1 != '\0') && (pcVar1[8] == param_1)) && (*(short *)(pcVar1 + 10) == param_2))
    break;
    iVar2 = iVar2 + 1;
    pcVar1 = pcVar1 + 0xc;
  }
  return pcVar1;
}

