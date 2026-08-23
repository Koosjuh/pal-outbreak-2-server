FUNCTION FUN_0000ba80 @ 0x0000ba80 size=496
CALLERS (2): FUN_0000fddc@0x0000fddc, FUN_0000feb4@0x0000feb4
CALLEES (2): FUN_00009eec@0x00009eec, FUN_0000b9bc@0x0000b9bc

int FUN_0000ba80(int param_1,int param_2,int *param_3,uint param_4)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  
  if (param_2 == 0xe) {
    if (param_4 != 4) {
      return -0x200;
    }
    *param_3 = *(int *)(param_1 + 0x18);
    return 0;
  }
  if (param_2 == 0xc) {
    if (param_4 != 4) {
      return -0x200;
    }
    *param_3 = 0;
  }
  else if (param_2 == 0xf) {
    iVar4 = *param_3;
    if (iVar4 < 0) {
      return -0x200;
    }
    if (iVar4 < *(int *)(param_1 + 0x18)) {
      while ((iVar4 < *(int *)(param_1 + 0x1c) &&
             (puVar3 = *(undefined4 **)(param_1 + 0x24), puVar3 != (undefined4 *)0x0))) {
        iVar1 = puVar3[1];
        *(int *)(param_1 + 0x24) = iVar1;
        if (iVar1 == 0) {
          *(undefined4 *)(param_1 + 0x20) = 0;
        }
        else {
          *(undefined4 *)puVar3[1] = 0;
        }
        puVar3[1] = 0;
        *puVar3 = 0;
        *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) - (puVar3[5] - puVar3[4]);
        FUN_00009eec();
      }
    }
    *(int *)(param_1 + 0x18) = iVar4;
  }
  else {
    if (param_2 != 0xd) {
      if (param_2 == 0x11) {
        if (param_4 < 0x10) {
          return 0;
        }
        *param_3 = 3;
        param_3[1] = 0x8000;
        param_3[2] = 0;
        param_3[3] = 0;
        return 1;
      }
      if (param_2 != 1) {
        return -0x200;
      }
      if (param_1 != 0) {
        if (param_4 < 0x4c) {
          return 0;
        }
        iVar4 = FUN_0000b9bc(param_1,param_3);
        return iVar4;
      }
      iVar4 = 0;
      iVar1 = DAT_0001b984;
      while( true ) {
        if (iVar1 == 0) {
          return iVar4;
        }
        if (param_4 < 0x4c) break;
        iVar2 = FUN_0000b9bc(iVar1,param_3);
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
    if (*param_3 != 0) {
      return -0x200;
    }
    *(undefined4 *)(param_1 + 0x18) = 0;
  }
  return 0;
}


================================================================