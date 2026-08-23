FUNCTION FUN_00000238 @ 0x00000238 size=100
CALLERS (2): FUN_00000344@0x00000344, FUN_0000029c@0x0000029c
CALLEES (0): 

void FUN_00000238(int *param_1)

{
  int iVar1;
  int *piVar2;
  
  piVar2 = (int *)param_1[1];
  if (*param_1 != 0) {
    *(int **)(*param_1 + 4) = (int *)param_1[1];
    piVar2 = DAT_0001b954;
  }
  DAT_0001b954 = piVar2;
  iVar1 = *param_1;
  if ((int *)param_1[1] != (int *)0x0) {
    *(int *)param_1[1] = *param_1;
    iVar1 = (int)DAT_0001b950;
  }
  DAT_0001b950 = (int *)iVar1;
  *param_1 = (int)DAT_0001b950;
  piVar2 = param_1;
  if (DAT_0001b950 != (int *)0x0) {
    *(int **)((int)DAT_0001b950 + 4) = param_1;
    piVar2 = DAT_0001b954;
  }
  DAT_0001b954 = piVar2;
  param_1[1] = 0;
  DAT_0001b950 = param_1;
  return;
}


================================================================