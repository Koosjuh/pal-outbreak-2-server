
void FUN_001cdd30(byte param_1,uint param_2)

{
  int iVar1;
  char *pcVar2;
  
  pcVar2 = (char *)0x36c350;
  iVar1 = 0;
  do {
    if ((*pcVar2 != '\0') && ((param_2 == 0xffffffff || ((byte)pcVar2[8] == param_2)))) {
      pcVar2[3] = pcVar2[3] & ~param_1;
      if (pcVar2[3] == '\0') {
        *pcVar2 = '\x01';
        FUN_001cdbb0(pcVar2);
      }
      else {
        *pcVar2 = *pcVar2 + -1;
        if (*pcVar2 == '\0') {
          *pcVar2 = '\x01';
        }
      }
    }
    iVar1 = iVar1 + 1;
    pcVar2 = pcVar2 + 0xc;
  } while (iVar1 < 0x10);
  return;
}

