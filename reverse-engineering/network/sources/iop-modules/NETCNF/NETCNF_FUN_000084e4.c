FUNCTION FUN_000084e4 @ 0x000084e4 size=304
CALLERS (1): FUN_00008614@0x00008614
CALLEES (3): FUN_00008470@0x00008470, FUN_000095f8@0x000095f8, FUN_00009658@0x00009658

int FUN_000084e4(char *param_1,char *param_2)

{
  char cVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  char cVar5;
  
  for (; (param_1 < param_2 && (param_2[-1] < '!')); param_2 = param_2 + -1) {
  }
  *param_2 = '\0';
  while ((*param_1 != '\0' && (uVar4 = FUN_000095f8((int)*param_1), (uVar4 & 8) != 0))) {
    param_1 = param_1 + 1;
  }
  iVar2 = FUN_00009658(param_1,"auth_name",9);
  iVar3 = 0;
  if (iVar2 == 0) {
    cVar5 = *param_1;
    if (*param_1 != '\0') {
      do {
        uVar4 = FUN_000095f8((int)cVar5);
        if ((uVar4 & 8) != 0) goto LAB_000085c8;
        param_1 = param_1 + 1;
        cVar5 = *param_1;
        cVar1 = '\0';
      } while (*param_1 != '\0');
      while ((cVar1 != '\0' && (uVar4 = FUN_000095f8((int)cVar5), (uVar4 & 8) != 0))) {
        param_1 = param_1 + 1;
LAB_000085c8:
        cVar1 = *param_1;
        cVar5 = *param_1;
      }
    }
    if (*param_1 == '\"') {
      param_1 = param_1 + 1;
    }
    iVar3 = FUN_00008470(param_1);
    if (-1 < iVar3) {
      iVar3 = 0;
    }
  }
  return iVar3;
}


================================================================