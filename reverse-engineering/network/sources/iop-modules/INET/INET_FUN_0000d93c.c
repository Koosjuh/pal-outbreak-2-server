FUNCTION FUN_0000d93c @ 0x0000d93c size=112
CALLERS (1): FUN_000175ac@0x000175ac
CALLEES (2): FUN_00019a9c@0x00019a9c, FUN_00011d90@0x00011d90

int FUN_0000d93c(int *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  for (param_1 = (int *)*param_1; param_1 != (int *)0x0; param_1 = (int *)*param_1) {
    iVar1 = FUN_00019a9c(param_1[3],1);
    if (iVar1 != 0) {
      FUN_00011d90("inet: iSetEventFlag (%d)\n",iVar1);
      iVar2 = iVar2 + 1;
    }
  }
  return iVar2;
}


================================================================