
void FUN_001cd7c0(short *param_1)

{
  int iVar1;
  
  iVar1 = 0;
  for (; (iVar1 < 6 && (*param_1 != -1)); param_1 = param_1 + 1) {
    FUN_001cbae0(*param_1,1);
    iVar1 = iVar1 + 1;
  }
  return;
}

