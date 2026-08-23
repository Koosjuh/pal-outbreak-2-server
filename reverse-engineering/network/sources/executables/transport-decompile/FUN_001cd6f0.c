
void FUN_001cd6f0(byte param_1,uint param_2)

{
  int iVar1;
  char *pcVar2;
  
  pcVar2 = (char *)0x36c420;
  iVar1 = 0;
  do {
    if ((*pcVar2 != '\0') && ((param_2 == 0xffffffff || ((byte)pcVar2[0x10] == param_2)))) {
      pcVar2[0xf] = pcVar2[0xf] & ~param_1;
      if (pcVar2[0xf] == '\0') {
        *pcVar2 = '\x01';
        FUN_001cd4c0(pcVar2);
      }
      else {
        *pcVar2 = *pcVar2 + -1;
        if (*pcVar2 == '\0') {
          *pcVar2 = '\x01';
        }
      }
    }
    iVar1 = iVar1 + 1;
    pcVar2 = pcVar2 + 0x14;
  } while (iVar1 < 0x10);
  return;
}

