FUNCTION FUN_00013a88 @ 0x00013a88 size=236
CALLERS (1): FUN_00013e24@0x00013e24
CALLEES (1): FUN_0001283c@0x0001283c

undefined4 FUN_00013a88(char *param_1,int param_2)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  char *pcVar4;
  undefined4 uVar5;
  short sVar6;
  
  iVar3 = FUN_0001283c(param_2);
  pcVar4 = (char *)(param_2 + (short)iVar3);
  if ((short)iVar3 < 1) {
    uVar5 = 0xffffffff;
  }
  else {
    sVar6 = 0;
    do {
      pcVar4 = pcVar4 + -1;
      pcVar2 = pcVar4;
      if (*pcVar4 == '.') {
        for (; sVar6 != 0; sVar6 = sVar6 + -1) {
          *param_1 = pcVar2[1];
          param_1 = param_1 + 1;
          pcVar2 = pcVar2 + 1;
        }
        *param_1 = '.';
        param_1 = param_1 + 1;
      }
      else {
        sVar6 = sVar6 + 1;
      }
      iVar3 = iVar3 + -1;
    } while (0 < iVar3 * 0x10000);
    for (; sVar6 != 0; sVar6 = sVar6 + -1) {
      cVar1 = *pcVar4;
      pcVar4 = pcVar4 + 1;
      *param_1 = cVar1;
      param_1 = param_1 + 1;
    }
    *param_1 = '\0';
    uVar5 = 0;
  }
  return uVar5;
}


================================================================