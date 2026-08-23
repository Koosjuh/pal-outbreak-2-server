
void FUN_001ceda0(undefined2 *param_1,undefined2 *param_2)

{
  int iVar1;
  char *pcVar2;
  char *pcVar3;
  
  pcVar3 = (char *)0x36c350;
  pcVar2 = (char *)0x36c420;
  iVar1 = 0;
  do {
    if ((*pcVar3 != '\0') && (pcVar3[8] == '\x02')) {
      *param_1 = *(undefined2 *)(pcVar3 + 10);
      param_1 = param_1 + 1;
    }
    if ((*pcVar2 != '\0') && (pcVar2[0x10] == '\x02')) {
      *param_2 = *(undefined2 *)(pcVar2 + 0x12);
      param_2 = param_2 + 1;
    }
    iVar1 = iVar1 + 1;
    pcVar3 = pcVar3 + 0xc;
    pcVar2 = pcVar2 + 0x14;
  } while (iVar1 < 0x10);
  return;
}

