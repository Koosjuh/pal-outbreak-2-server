FUNCTION FUN_00000000 @ 0x00000000 size=196
CALLERS (3): FUN_000014dc@0x000014dc, FUN_000000c4@0x000000c4, FUN_00000160@0x00000160
CALLEES (3): FUN_0000a7e0@0x0000a7e0, FUN_00017bf4@0x00017bf4, FUN_00009eec@0x00009eec

void FUN_00000000(int *param_1)

{
  int *piVar1;
  int iVar2;
  
  if (param_1 != (int *)0x0) {
    iVar2 = FUN_00017bf4(param_1[7]);
    param_1[7] = iVar2;
    piVar1 = (int *)param_1[9];
    while (piVar1 != (int *)0x0) {
      iVar2 = *piVar1;
      FUN_00009eec(piVar1[2]);
      FUN_0000a7e0(piVar1);
      piVar1 = (int *)iVar2;
    }
    iVar2 = param_1[1];
    if (*param_1 != 0) {
      *(int *)(*param_1 + 4) = param_1[1];
      iVar2 = DAT_0001b954;
    }
    DAT_0001b954 = iVar2;
    iVar2 = *param_1;
    if ((int *)param_1[1] != (int *)0x0) {
      *(int *)param_1[1] = *param_1;
      iVar2 = DAT_0001b950;
    }
    DAT_0001b950 = iVar2;
    FUN_0000a7e0(param_1);
    DAT_0001b958 = DAT_0001b958 + -1;
  }
  return;
}


================================================================