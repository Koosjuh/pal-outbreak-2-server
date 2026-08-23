
undefined8 FUN_001ca610(int param_1,int param_2,int param_3)

{
  int iVar1;
  char *pcVar2;
  int iVar3;
  
  pcVar2 = (char *)(param_1 + param_3 + -1);
  for (iVar3 = 0; iVar3 < param_3; iVar3 = iVar3 + 1) {
    iVar1 = param_2 % 10;
    param_2 = param_2 / 10;
    *pcVar2 = (char)iVar1 + '0';
    pcVar2 = pcVar2 + -1;
  }
  return 0;
}

