
void FUN_001ce890(undefined2 *param_1,undefined2 *param_2,undefined2 *param_3)

{
  int iVar1;
  char *pcVar2;
  char *pcVar3;
  char *pcVar4;
  
  pcVar4 = (char *)0x36c350;
  pcVar3 = (char *)0x36c420;
  pcVar2 = (char *)0x36c310;
  iVar1 = 0;
  do {
    if (((*pcVar4 != '\0') && (pcVar4[8] == '\x01')) && ((pcVar4[3] & 4U) != 0)) {
      *param_1 = *(undefined2 *)(pcVar4 + 10);
      param_1 = param_1 + 1;
    }
    if (((*pcVar3 != '\0') && (pcVar3[0x10] == '\x01')) && ((pcVar4[3] & 4U) != 0)) {
      *param_2 = *(undefined2 *)(pcVar3 + 0x12);
      param_2 = param_2 + 1;
    }
    if (iVar1 < 4) {
      if (*pcVar2 != '\0') {
        *param_3 = *(undefined2 *)(pcVar2 + 8);
        param_3[1] = *(undefined2 *)(pcVar2 + 0xc);
        param_3 = param_3 + 2;
      }
      pcVar2 = pcVar2 + 0x10;
    }
    iVar1 = iVar1 + 1;
    pcVar4 = pcVar4 + 0xc;
    pcVar3 = pcVar3 + 0x14;
  } while (iVar1 < 0x10);
  return;
}

