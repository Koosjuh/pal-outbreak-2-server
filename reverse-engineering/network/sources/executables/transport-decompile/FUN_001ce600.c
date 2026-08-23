
char * FUN_001ce600(short param_1,short param_2)

{
  char *pcVar1;
  int iVar2;
  
  pcVar1 = (char *)0x36c310;
  iVar2 = 0;
  while( true ) {
    if (3 < iVar2) {
      return (char *)0x0;
    }
    if (((*pcVar1 != '\0') && (*(short *)(pcVar1 + 0xc) == param_2)) &&
       (*(short *)(pcVar1 + 8) == param_1)) break;
    iVar2 = iVar2 + 1;
    pcVar1 = pcVar1 + 0x10;
  }
  return pcVar1;
}

