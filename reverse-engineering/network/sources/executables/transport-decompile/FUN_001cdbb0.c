
void FUN_001cdbb0(char *param_1)

{
  char cVar1;
  
  cVar1 = *param_1;
  *param_1 = cVar1 + -1;
  if ((char)(cVar1 + -1) == '\0') {
    FUN_001a9e70(*(undefined4 *)(param_1 + 4));
    param_1[3] = '\0';
    param_1[8] = '\0';
  }
  return;
}

