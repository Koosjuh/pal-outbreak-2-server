FUNCTION FUN_00019520 @ 0x00019520 size=560
CALLERS (2): FUN_0000feb4@0x0000feb4, FUN_0000fddc@0x0000fddc
CALLEES (4): FUN_0000a7e0@0x0000a7e0, FUN_00019444@0x00019444, FUN_00008d64@0x00008d64, FUN_00009eec@0x00009eec

int FUN_00019520(int param_1,int param_2,int *param_3,uint param_4)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  
  if (param_2 == 0xe) {
    if (param_4 != 4) {
      return -0x200;
    }
    *param_3 = *(int *)(param_1 + 0x20);
    return 0;
  }
  if (param_2 == 0xc) {
    if (param_4 != 4) {
      return -0x200;
    }
    *param_3 = 0;
  }
  else {
    if (param_2 != 0xf) {
      if (param_2 == 0xd) {
        if (*param_3 != 0) {
          return -0x200;
        }
        return 0;
      }
      if (param_2 == 0x11) {
        if (param_4 < 0x10) {
          return 0;
        }
        *param_3 = 2;
        param_3[1] = 0x800000;
        param_3[2] = 0;
        param_3[3] = 0;
        return 1;
      }
      if (param_2 != 1) {
        if (param_1 == 0) {
          return -0x200;
        }
        iVar4 = FUN_00008d64(param_1 + 0x50,param_1 + 0x3c,param_2,param_3,param_4);
        return iVar4;
      }
      if (param_1 == 0) {
        iVar4 = 0;
        iVar1 = DAT_0001b9b8;
        while( true ) {
          if (iVar1 == 0) {
            return iVar4;
          }
          if (param_4 < 0x4c) break;
          iVar2 = FUN_00019444(iVar1,param_3);
          iVar4 = iVar4 + 1;
          if (iVar2 < 0) {
            return iVar2;
          }
          param_3 = param_3 + 0x13;
          iVar1 = *(int *)(iVar1 + 4);
          param_4 = param_4 - 0x4c;
        }
        return iVar4;
      }
      if (param_4 < 0x4c) {
        return 0;
      }
      iVar4 = FUN_00019444(param_1,param_3);
      return iVar4;
    }
    iVar4 = *param_3;
    if (iVar4 < 0) {
      return -0x200;
    }
    if (iVar4 < *(int *)(param_1 + 0x20)) {
      while ((iVar4 < *(int *)(param_1 + 0x24) &&
             (piVar3 = *(int **)(param_1 + 0x28), piVar3 != (int *)0x0))) {
        iVar1 = *piVar3;
        *(int *)(param_1 + 0x28) = iVar1;
        if (iVar1 == 0) {
          *(undefined4 *)(param_1 + 0x2c) = 0;
        }
        else {
          *(undefined4 *)(*piVar3 + 4) = 0;
        }
        *(int *)(param_1 + 0x24) =
             *(int *)(param_1 + 0x24) - (*(int *)(piVar3[5] + 0x14) - *(int *)(piVar3[5] + 0x10));
        FUN_00009eec(piVar3[5]);
        FUN_0000a7e0(piVar3);
      }
    }
    *(int *)(param_1 + 0x20) = iVar4;
  }
  return 0;
}


================================================================