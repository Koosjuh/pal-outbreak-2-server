
void FUN_001ce550(void)

{
  int iVar1;
  char *pcVar2;
  
  pcVar2 = (char *)0x36c310;
  iVar1 = 0;
  do {
    if (*pcVar2 != '\0') {
      FUN_001ce4b0(*(undefined2 *)(pcVar2 + 8),*(undefined2 *)(pcVar2 + 0xc));
    }
    iVar1 = iVar1 + 1;
    pcVar2 = pcVar2 + 0x10;
  } while (iVar1 < 4);
  return;
}

