FUNCTION FUN_00001e2c @ 0x00001e2c size=168
CALLERS (1): FUN_0000203c@0x0000203c
CALLEES (0): 

undefined4 FUN_00001e2c(int param_1)

{
  int *piVar1;
  int iVar2;
  
  if (*(int **)(PTR_DAT_000045e0 + 0x18) == (int *)0x0) {
    return 0;
  }
  piVar1 = (int *)**(int **)(PTR_DAT_000045e0 + 0x18);
  while( true ) {
    if (piVar1 == (int *)0x0) {
      if (((DAT_000045ec != 0) && (iVar2 = *(int *)(DAT_000045ec + 0x24), iVar2 != 0)) &&
         (param_1 == *(int *)(iVar2 + 8))) {
        *(undefined4 *)(iVar2 + 8) = 0;
      }
      return 0;
    }
    iVar2 = piVar1[9];
    if ((iVar2 != 0) && (param_1 == *(int *)(iVar2 + 8))) break;
    piVar1 = (int *)*piVar1;
  }
  *(undefined4 *)(iVar2 + 8) = 0;
  return 0;
}


================================================================