FUNCTION FUN_00016f74 @ 0x00016f74 size=956
CALLERS (2): FUN_0000feb4@0x0000feb4, FUN_0000fddc@0x0000fddc
CALLEES (5): FUN_00013b50@0x00013b50, FUN_00016e2c@0x00016e2c, FUN_000160a0@0x000160a0, FUN_0000d8cc@0x0000d8cc, FUN_00009eec@0x00009eec

int FUN_00016f74(int param_1,int param_2,uint *param_3,uint param_4)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  uint local_18 [2];
  
  if (param_2 == 2) {
    if (param_4 == 4) {
      *param_3 = *(uint *)(param_1 + 0x2c) >> 0x12 & 1;
      return 0;
    }
    return -0x200;
  }
  if (param_2 == 3) {
    if (param_4 != 4) {
      return -0x200;
    }
    if ((*param_3 & 1) == 0) {
      uVar1 = *(uint *)(param_1 + 0x2c) & 0xfffbffff;
    }
    else {
      uVar1 = *(uint *)(param_1 + 0x2c) | 0x40000;
    }
    *(uint *)(param_1 + 0x2c) = uVar1;
    if ((*param_3 & 2) != 0) {
      uVar1 = *(uint *)(param_1 + 0x2c) | 0x80000;
      goto LAB_0001721c;
    }
    uVar1 = 0xfff70000;
  }
  else {
    if (param_2 == 0xc) {
      if (param_4 != 4) {
        return -0x200;
      }
      uVar1 = *(uint *)(param_1 + 0x7c);
LAB_000170b4:
      *param_3 = uVar1;
      return 0;
    }
    if (param_2 == 0xd) {
      if (param_4 != 4) {
        return -0x200;
      }
      local_18[0] = *param_3;
      if (local_18[0] < 0x10000) {
        *(uint *)(param_1 + 0x7c) = local_18[0];
        FUN_0000d8cc(param_1 + 0xcc);
        return 0;
      }
      return -0x200;
    }
    if (param_2 == 0xe) {
      if (param_4 != 4) {
        return -0x200;
      }
      uVar1 = *(uint *)(param_1 + 0x90);
      goto LAB_000170b4;
    }
    if (param_2 == 0xf) {
      if (param_4 != 4) {
        return -0x200;
      }
      local_18[0] = *param_3;
      if (0xffff < local_18[0]) {
        return -0x200;
      }
      if ((*(int *)(param_1 + 0x90) < (int)local_18[0]) &&
         ((*(uint *)(param_1 + 0x2c) & 0x100) == 0)) {
        *(uint *)(param_1 + 0x2c) = *(uint *)(param_1 + 0x2c) | 0x8000;
        FUN_00013b50(param_1);
      }
      *(uint *)(param_1 + 0x90) = local_18[0];
      return 0;
    }
    if (param_2 == 0x10) {
      if (param_4 != 4) {
        return -0x200;
      }
      local_18[0] = *param_3;
      iVar2 = FUN_000160a0(param_1,local_18);
      if (iVar2 == -500) {
        if ((*(uint *)(param_1 + 0x2c) & 0x1000000) != 0) {
          *(uint *)(param_1 + 0x2c) = *(uint *)(param_1 + 0x2c) | 0x2000000;
          return -500;
        }
        return -500;
      }
      return iVar2;
    }
    if (param_2 == 0x11) {
      if (0xf < param_4) {
        *param_3 = 1;
        param_3[1] = 0x7d78;
        param_3[2] = 0x7d78;
        param_3[3] = 0;
        return 1;
      }
      return 0;
    }
    if (param_2 == 0x12) {
      if (param_4 == 4) {
        *param_3 = *(byte *)(param_1 + 0x2f) & 1;
        return 0;
      }
      return -0x200;
    }
    if (param_2 != 0x13) {
      if (param_2 == 0x14) {
        if (param_4 != 4) {
          return -0x200;
        }
        *param_3 = *(uint *)(param_1 + 0x34);
        *(undefined4 *)(param_1 + 0x34) = 0;
      }
      else if (param_2 == 0x15) {
        uVar3 = FUN_00009eec(*(undefined4 *)(param_1 + 0x98));
        *(undefined4 *)(param_1 + 0x9c) = uVar3;
        *(undefined4 *)(param_1 + 0x98) = uVar3;
        uVar3 = FUN_00009eec(*(undefined4 *)(param_1 + 0xa4));
        *(undefined4 *)(param_1 + 0xa8) = uVar3;
        *(undefined4 *)(param_1 + 0xa4) = uVar3;
        *(undefined4 *)(param_1 + 0xa0) = 0;
        *(undefined4 *)(param_1 + 0x94) = 0;
        *(uint *)(param_1 + 0x2c) = *(uint *)(param_1 + 0x2c) | 0x8000000;
      }
      else if (param_2 != 1) {
        return -0x200;
      }
      if (param_1 == 0) {
        local_18[0] = 0;
        iVar2 = DAT_0001b9a0;
        while( true ) {
          if (iVar2 == 0) {
            return local_18[0];
          }
          if (param_4 < 0x4c) break;
          iVar4 = FUN_00016e2c(iVar2,param_3);
          param_3 = param_3 + 0x13;
          if (iVar4 < 0) {
            return iVar4;
          }
          param_4 = param_4 - 0x4c;
          iVar2 = *(int *)(iVar2 + 4);
          local_18[0] = local_18[0] + 1;
        }
        return local_18[0];
      }
      if (0x4b < param_4) {
        iVar2 = FUN_00016e2c(param_1,param_3);
        return iVar2;
      }
      return 0;
    }
    if (param_4 != 4) {
      return -0x200;
    }
    if (*param_3 != 0) {
      uVar1 = *(uint *)(param_1 + 0x2c) | 0x1000000;
      goto LAB_0001721c;
    }
    uVar1 = 0xfeff0000;
  }
  uVar1 = *(uint *)(param_1 + 0x2c) & (uVar1 | 0xffff);
LAB_0001721c:
  *(uint *)(param_1 + 0x2c) = uVar1;
  return 0;
}


================================================================