FUNCTION FUN_0000c33c @ 0x0000c33c size=156
CALLERS (1): FUN_0000c444@0x0000c444
CALLEES (1): FUN_0000c2e8@0x0000c2e8

int FUN_0000c33c(char *param_1,char *param_2)

{
  char cVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  
  do {
    iVar2 = FUN_0000c2e8((int)*param_1);
    iVar3 = FUN_0000c2e8((int)*param_2);
    if (iVar2 << 0x18 != iVar3 << 0x18) {
      uVar4 = FUN_0000c2e8((int)*param_1);
      uVar5 = FUN_0000c2e8((int)*param_2);
      return (uVar4 & 0xff) - (uVar5 & 0xff);
    }
    cVar1 = *param_1;
    param_1 = param_1 + 1;
    param_2 = param_2 + 1;
  } while (cVar1 != '\0');
  return 0;
}


================================================================