
void FUN_001ce4b0(short param_1,short param_2)

{
  int iVar1;
  char *pcVar2;
  
  iVar1 = 0;
  pcVar2 = (char *)0x36c310;
  while( true ) {
    if (3 < iVar1) {
      return;
    }
    if (((*pcVar2 != '\0') && (*(short *)(pcVar2 + 0xc) == param_2)) &&
       (*(short *)(pcVar2 + 8) == param_1)) break;
    iVar1 = iVar1 + 1;
    pcVar2 = pcVar2 + 0x10;
  }
  FUN_001aa580(*(int *)(pcVar2 + 4) + 4);
  FUN_00106b60(*(int *)(pcVar2 + 4) + 4,0,0xc80);
  *pcVar2 = '\0';
  pcVar2[10] = '\0';
  pcVar2[0xb] = '\0';
  return;
}

