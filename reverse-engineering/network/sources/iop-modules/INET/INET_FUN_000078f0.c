FUNCTION FUN_000078f0 @ 0x000078f0 size=140
CALLERS (3): FUN_00007a0c@0x00007a0c, FUN_00007e28@0x00007e28, FUN_00007abc@0x00007abc
CALLEES (3): FUN_00017bf4@0x00017bf4, FUN_00009eec@0x00009eec, FUN_0000a7e0@0x0000a7e0

void FUN_000078f0(int *param_1)

{
  int iVar1;
  
  if (param_1 != (int *)0x0) {
    iVar1 = *param_1;
    if ((int *)param_1[1] != (int *)0x0) {
      *(int *)param_1[1] = *param_1;
      iVar1 = DAT_0001b960;
    }
    DAT_0001b960 = iVar1;
    iVar1 = param_1[1];
    if (*param_1 != 0) {
      *(int *)(*param_1 + 4) = param_1[1];
      iVar1 = DAT_0001b964;
    }
    DAT_0001b964 = iVar1;
    FUN_00017bf4(param_1[9]);
    DAT_0001b710 = DAT_0001b710 - param_1[0xc];
    FUN_00009eec(param_1[10]);
    FUN_0000a7e0(param_1);
  }
  return;
}


================================================================