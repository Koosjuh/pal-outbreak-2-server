FUNCTION FUN_0000d9ac @ 0x0000d9ac size=112
CALLERS (1): FUN_0001140c@0x0001140c
CALLEES (2): FUN_00011d90@0x00011d90, FUN_00019a94@0x00019a94

int FUN_0000d9ac(int *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  for (param_1 = (int *)*param_1; param_1 != (int *)0x0; param_1 = (int *)*param_1) {
    iVar1 = FUN_00019a94(param_1[3],4);
    if (iVar1 != 0) {
      FUN_00011d90("inet: SetEventFlag (%d)\n",iVar1);
      iVar2 = iVar2 + 1;
    }
  }
  return iVar2;
}


================================================================