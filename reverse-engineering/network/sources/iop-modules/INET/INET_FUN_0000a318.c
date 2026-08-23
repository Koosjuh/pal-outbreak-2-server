FUNCTION FUN_0000a318 @ 0x0000a318 size=380
CALLERS (2): FUN_00007abc@0x00007abc, FUN_0001442c@0x0001442c
CALLEES (0): 

undefined4 FUN_0000a318(int *param_1,int *param_2)

{
  undefined4 *puVar1;
  int *piVar2;
  int iVar3;
  
  piVar2 = (int *)*param_1;
  if (piVar2 != (int *)0x0) {
    do {
      if (param_2[2] - piVar2[2] < 0) break;
      piVar2 = (int *)*piVar2;
    } while (piVar2 != (int *)0x0);
    if (piVar2 != (int *)0x0) {
      puVar1 = (undefined4 *)piVar2[1];
      param_2[1] = (int)puVar1;
      if (puVar1 == (undefined4 *)0x0) {
        *param_1 = (int)param_2;
      }
      else {
        *puVar1 = param_2;
      }
      *param_2 = (int)piVar2;
      piVar2[1] = (int)param_2;
      goto LAB_0000a3a4;
    }
  }
  puVar1 = (undefined4 *)param_1[1];
  param_2[1] = (int)puVar1;
  if (puVar1 == (undefined4 *)0x0) {
    *param_1 = (int)param_2;
  }
  else {
    *puVar1 = param_2;
  }
  param_1[1] = (int)param_2;
LAB_0000a3a4:
  iVar3 = param_2[1];
  if ((iVar3 != 0) &&
     (iVar3 = (*(int *)(iVar3 + 8) + (*(int *)(iVar3 + 0x14) - *(int *)(iVar3 + 0x10))) - param_2[2]
     , 0 < iVar3)) {
    param_2[4] = param_2[4] + iVar3;
    param_2[2] = param_2[2] + iVar3;
  }
  if ((*param_2 != 0) &&
     (iVar3 = (param_2[2] + (param_2[5] - param_2[4])) - *(int *)(*param_2 + 8), 0 < iVar3)) {
    param_2[5] = param_2[5] - iVar3;
  }
  if (param_2[5] - param_2[4] < 0) {
    if ((int *)param_2[1] == (int *)0x0) {
      *param_1 = *param_2;
    }
    else {
      *(int *)param_2[1] = *param_2;
    }
    if (*param_2 == 0) {
      param_1[1] = param_2[1];
    }
    else {
      *(int *)(*param_2 + 4) = param_2[1];
    }
    param_2[1] = 0;
    *param_2 = 0;
    return 1;
  }
  return 0;
}


================================================================