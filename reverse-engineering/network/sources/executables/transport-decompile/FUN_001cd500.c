
char * FUN_001cd500(char param_1,short param_2)

{
  char *pcVar1;
  int iVar2;
  
  pcVar1 = (char *)0x36c420;
  iVar2 = 0;
  while( true ) {
    if (0xf < iVar2) {
      return (char *)0x0;
    }
    if (((pcVar1[0x10] == param_1) && (*pcVar1 != '\0')) && (*(short *)(pcVar1 + 0x12) == param_2))
    break;
    iVar2 = iVar2 + 1;
    pcVar1 = pcVar1 + 0x14;
  }
  return pcVar1;
}

