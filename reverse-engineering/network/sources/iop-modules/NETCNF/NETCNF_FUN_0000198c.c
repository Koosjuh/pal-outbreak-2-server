FUNCTION FUN_0000198c @ 0x0000198c size=156
CALLERS (2): FUN_00001cdc@0x00001cdc, FUN_00001a28@0x00001a28
CALLEES (2): FUN_00009650@0x00009650, FUN_000013a0@0x000013a0

int FUN_0000198c(int param_1)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  
  FUN_000013a0();
  iVar2 = FUN_00009650(param_1);
  pcVar3 = (char *)(param_1 + iVar2);
  cVar1 = *pcVar3;
  while (cVar1 != '/') {
    pcVar3 = pcVar3 + -1;
    cVar1 = *pcVar3;
  }
  do {
    pcVar4 = pcVar3;
    pcVar3 = pcVar4 + -1;
  } while (*pcVar3 == '/');
  if (*pcVar3 == ':') {
    param_1 = 0;
  }
  else {
    *pcVar4 = '\0';
  }
  return param_1;
}


================================================================