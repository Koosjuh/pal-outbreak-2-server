FUNCTION FUN_00012e20 @ 0x00012e20 size=144
CALLERS (2): FUN_00015a28@0x00015a28, FUN_0001748c@0x0001748c
CALLEES (1): FUN_0000a7e0@0x0000a7e0

void FUN_00012e20(int *param_1)

{
  int iVar1;
  
  iVar1 = DAT_0001b9a0;
  if (param_1 != (int *)0x0) {
    for (; iVar1 != 0; iVar1 = *(int *)(iVar1 + 4)) {
      if (param_1 == *(int **)(iVar1 + 0xdc)) {
        *(undefined4 *)(iVar1 + 0xdc) = 0;
      }
    }
    iVar1 = param_1[1];
    if (*param_1 != 0) {
      *(int *)(*param_1 + 4) = param_1[1];
      iVar1 = DAT_0001b9b4;
    }
    DAT_0001b9b4 = iVar1;
    iVar1 = *param_1;
    if ((int *)param_1[1] != (int *)0x0) {
      *(int *)param_1[1] = *param_1;
      iVar1 = DAT_0001b9b0;
    }
    DAT_0001b9b0 = iVar1;
    FUN_0000a7e0();
  }
  return;
}


================================================================