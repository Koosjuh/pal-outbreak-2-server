FUNCTION FUN_0000789c @ 0x0000789c size=116
CALLERS (1): FUN_00007b40@0x00007b40
CALLEES (1): FUN_00006f00@0x00006f00

int FUN_0000789c(undefined4 param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  while ((*(int *)(param_2 + 0x38) == 0 ||
         (iVar1 = FUN_00006f00(param_1,"phone_number%d \"%S\"\n",iVar2), -1 < iVar1))) {
    iVar2 = iVar2 + 1;
    param_2 = param_2 + 4;
    if (9 < iVar2) {
      return 0;
    }
  }
  return iVar1;
}


================================================================