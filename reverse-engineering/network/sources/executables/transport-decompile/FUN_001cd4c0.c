
void FUN_001cd4c0(char *param_1)

{
  char cVar1;
  
  cVar1 = *param_1;
  *param_1 = cVar1 + -1;
  if ((char)(cVar1 + -1) == '\0') {
    param_1[0x10] = '\0';
    param_1[0xf] = '\0';
    FUN_001cd7c0(param_1 + 2);
  }
  return;
}

