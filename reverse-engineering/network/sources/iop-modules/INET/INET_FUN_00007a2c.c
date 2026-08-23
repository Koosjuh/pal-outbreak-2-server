FUNCTION FUN_00007a2c @ 0x00007a2c size=144
CALLERS (2): FUN_00007e28@0x00007e28, FUN_00007abc@0x00007abc
CALLEES (0): 

int * FUN_00007a2c(int param_1)

{
  int *piVar1;
  
  if (DAT_0001b960 != (int *)0x0) {
    piVar1 = DAT_0001b960;
    do {
      if ((((*(char *)((int)piVar1 + 0x11) == *(char *)(param_1 + 9)) &&
           ((short)piVar1[3] == *(short *)(param_1 + 4))) && (piVar1[5] == *(int *)(param_1 + 0xc)))
         && (piVar1[6] == *(int *)(param_1 + 0x10))) {
        return piVar1;
      }
      piVar1 = (int *)*piVar1;
    } while (piVar1 != (int *)0x0);
  }
  return (int *)0x0;
}


================================================================