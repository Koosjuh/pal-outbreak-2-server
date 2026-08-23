FUNCTION FUN_0000bca0 @ 0x0000bca0 size=144
CALLERS (1): FUN_0000bd30@0x0000bd30
CALLEES (0): 

char * FUN_0000bca0(char *param_1,int param_2)

{
  int iVar1;
  char *pcVar2;
  char local_10 [16];
  
  pcVar2 = local_10;
  if (param_2 < 0) {
    *param_1 = '-';
    param_1 = param_1 + 1;
    param_2 = -param_2;
    pcVar2 = local_10;
  }
  do {
    iVar1 = param_2 / 10;
    *pcVar2 = (char)param_2 + (char)iVar1 * -10 + '0';
    pcVar2 = pcVar2 + 1;
    param_2 = iVar1;
  } while (0 < iVar1);
  if (local_10 < pcVar2) {
    do {
      pcVar2 = pcVar2 + -1;
      *param_1 = *pcVar2;
      param_1 = param_1 + 1;
    } while (local_10 < pcVar2);
  }
  return param_1;
}


================================================================