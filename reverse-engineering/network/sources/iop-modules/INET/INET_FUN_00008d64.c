FUNCTION FUN_00008d64 @ 0x00008d64 size=868
CALLERS (1): FUN_00019520@0x00019520
CALLEES (8): FUN_0000ae24@0x0000ae24, FUN_0000e180@0x0000e180, FUN_00008a8c@0x00008a8c, FUN_00008bb8@0x00008bb8, FUN_0000a7e0@0x0000a7e0, FUN_0000a60c@0x0000a60c, FUN_00006e70@0x00006e70, FUN_0000a9c0@0x0000a9c0

int FUN_00008d64(int *param_1,undefined4 *param_2,undefined4 param_3,undefined4 *param_4,int param_5
                )

{
  int iVar1;
  undefined4 *puVar2;
  int *piVar3;
  int local_20;
  int local_1c;
  
  if (param_4 == (undefined4 *)0x0) {
    return -0x200;
  }
  if (((uint)param_4 & 3) != 0) {
    return -0x200;
  }
  switch(param_3) {
  case 4:
    if (param_5 != 0x10) {
      return -0x200;
    }
    iVar1 = FUN_0000e180(param_4);
    if (iVar1 != 0) {
      return -0x200;
    }
    puVar2 = param_4 + 1;
    goto LAB_00008e10;
  case 5:
    if (param_5 != 0x10) {
      return -0x200;
    }
    FUN_0000ae24(param_4,0x10);
    puVar2 = param_2;
    param_2 = param_4 + 1;
LAB_00008e10:
    FUN_0000a9c0(puVar2,param_2,4);
    return 0;
  case 6:
    if (param_5 == 4) {
      param_2[1] = *param_4;
      return 0;
    }
    break;
  case 7:
    if (param_5 == 4) {
      *param_4 = param_2[1];
      return 0;
    }
    return -0x200;
  case 8:
    if (param_5 == 4) {
      param_2[2] = *param_4;
      return 0;
    }
    return -0x200;
  case 9:
    if (param_5 == 4) {
      *param_4 = param_2[2];
      return 0;
    }
    return -0x200;
  case 10:
    if (param_5 != 0x20) {
      return -0x200;
    }
    iVar1 = FUN_0000e180(param_4);
    if (iVar1 != 0) {
      return -0x200;
    }
    iVar1 = FUN_0000e180(param_4 + 4);
    if (iVar1 != 0) {
      return -0x200;
    }
    FUN_0000a9c0(param_4 + 1,&local_20,4);
    iVar1 = FUN_00006e70(0,local_20);
    if (iVar1 != 0) {
      FUN_0000a9c0(param_4 + 5,&local_1c,4);
      for (piVar3 = (int *)*param_1; piVar3 != (int *)0x0; piVar3 = (int *)*piVar3) {
        if ((local_20 == piVar3[2]) && (local_1c == piVar3[3])) {
          return -0x201;
        }
      }
      piVar3 = (int *)FUN_0000a60c(0x1c);
      if (piVar3 == (int *)0x0) {
        return -0x1f8;
      }
      piVar3[2] = local_20;
      piVar3[3] = local_1c;
      iVar1 = FUN_00008a8c(piVar3);
      if (-1 < iVar1) {
        iVar1 = *param_1;
        *piVar3 = iVar1;
        if (iVar1 == 0) {
          param_1[1] = (int)piVar3;
        }
        else {
          *(int **)(iVar1 + 4) = piVar3;
        }
        piVar3[1] = 0;
        *param_1 = (int)piVar3;
        return 0;
      }
      FUN_0000a7e0(piVar3);
      return iVar1;
    }
    break;
  case 0xb:
    if (param_5 != 0x20) {
      return -0x200;
    }
    iVar1 = FUN_0000e180(param_4);
    if (iVar1 != 0) {
      return -0x200;
    }
    iVar1 = FUN_0000e180(param_4 + 4);
    if (iVar1 != 0) {
      return -0x200;
    }
    FUN_0000a9c0(param_4 + 1,&local_20,4);
    iVar1 = FUN_00006e70(0,local_20);
    if ((iVar1 != 0) && (local_20 != -0x1fffffff)) {
      FUN_0000a9c0(param_4 + 5,&local_1c,4);
      piVar3 = (int *)*param_1;
      if (piVar3 == (int *)0x0) {
        return -0x201;
      }
      do {
        if ((local_20 == piVar3[2]) && (local_1c == piVar3[3])) break;
        piVar3 = (int *)*piVar3;
      } while (piVar3 != (int *)0x0);
      if (piVar3 != (int *)0x0) {
        if (*piVar3 == 0) {
          param_1[1] = piVar3[1];
        }
        else {
          *(int *)(*piVar3 + 4) = piVar3[1];
        }
        if ((int *)piVar3[1] == (int *)0x0) {
          *param_1 = *piVar3;
        }
        else {
          *(int *)piVar3[1] = *piVar3;
        }
        FUN_00008bb8(piVar3);
        FUN_0000a7e0(piVar3);
        return 0;
      }
      return -0x201;
    }
  }
  return -0x200;
}


================================================================