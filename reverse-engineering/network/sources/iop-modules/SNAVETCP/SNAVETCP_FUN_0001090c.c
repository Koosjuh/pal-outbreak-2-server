FUNCTION FUN_0001090c @ 0x0001090c size=692
CALLERS (1): FUN_000005b8@0x000005b8
CALLEES (6): FUN_00012090@0x00012090, FUN_00012490@0x00012490, FUN_000124b8@0x000124b8, FUN_00011e58@0x00011e58, FUN_000013ac@0x000013ac, FUN_0000dcd8@0x0000dcd8

int FUN_0001090c(short *param_1,undefined2 *param_2)

{
  short sVar1;
  int iVar2;
  undefined1 auStack_18 [8];
  
  if ((*param_1 < (short)(ushort)DAT_0001619b) && (-1 < *param_1)) {
    FUN_000013ac(auStack_18,*(undefined4 *)(param_1 + 2));
    *(undefined2 *)(&DAT_00017f40 + *param_1 * 0xc) = 0xffff;
    *(short *)(&DAT_00017f46 + *param_1 * 0xc) = *param_1;
    if (*(int *)(param_1 + 4) == 0) {
      FUN_00011e58(&DAT_00017f48 + *param_1 * 3);
      if ((&DAT_00017f48)[*param_1 * 3] == -1) {
        return -0x10;
      }
    }
    else {
      (&DAT_00017f48)[*param_1 * 3] = 0xffffffff;
    }
    sVar1 = FUN_0000dcd8((int)*param_1,auStack_18,(int)param_1[1],*(undefined4 *)(param_1 + 4));
    iVar2 = (int)sVar1;
    if (iVar2 < 0) {
      (&DAT_00017f48)[*param_1 * 3] = 0xffffffff;
    }
    else {
      iVar2 = -1;
      if (*(int *)(param_1 + 4) == 0) {
        FUN_000124b8();
        sVar1 = *(short *)(&DAT_00017f40 + *param_1 * 0xc);
        while (sVar1 == -1) {
          FUN_00012090();
          sVar1 = *(short *)(&DAT_00017f40 + *param_1 * 0xc);
        }
        FUN_00012490();
        (&DAT_00017f48)[*param_1 * 3] = 0xffffffff;
        *param_2 = *(undefined2 *)(&DAT_00017f44 + *param_1 * 0xc);
        if (*(short *)(&DAT_00017f42 + *param_1 * 0xc) == 0) {
          iVar2 = -8;
        }
        else {
          iVar2 = (int)*(short *)(&DAT_00017f42 + *param_1 * 0xc);
        }
      }
    }
  }
  else {
    iVar2 = -4;
  }
  return iVar2;
}


================================================================