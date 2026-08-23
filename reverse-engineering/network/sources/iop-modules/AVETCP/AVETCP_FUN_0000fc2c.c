FUNCTION FUN_0000fc2c @ 0x0000fc2c size=748
CALLERS (1): FUN_00000478@0x00000478
CALLEES (6): FUN_000124b8@0x000124b8, FUN_00011e58@0x00011e58, FUN_0000cc3c@0x0000cc3c, FUN_0000cdb4@0x0000cdb4, FUN_00012090@0x00012090, FUN_00012490@0x00012490

int FUN_0000fc2c(short *param_1,undefined4 *param_2,undefined2 *param_3,undefined2 *param_4)

{
  short sVar1;
  int iVar2;
  
  iVar2 = (int)*param_1;
  if ((iVar2 < (int)(uint)DAT_0001619b) && (-1 < iVar2)) {
    *(undefined2 *)(&DAT_00017e30 + iVar2 * 0x14) = 0xffff;
    if (*(int *)(param_1 + 2) == 0) {
      FUN_00011e58(&DAT_00017e40 + *param_1 * 5);
      if ((&DAT_00017e40)[*param_1 * 5] == -1) {
        return -0x10;
      }
    }
    else {
      (&DAT_00017e40)[*param_1 * 5] = 0xffffffff;
    }
    sVar1 = FUN_0000cc3c((int)*param_1,*(undefined4 *)(param_1 + 2),*(undefined4 *)(param_1 + 4));
    iVar2 = -4;
    if (sVar1 == 0) {
      iVar2 = -1;
      if (*(int *)(param_1 + 2) == 0) {
        FUN_000124b8();
        sVar1 = *(short *)(&DAT_00017e30 + *param_1 * 0x14);
        while (sVar1 == -1) {
          FUN_00012090();
          sVar1 = *(short *)(&DAT_00017e30 + *param_1 * 0x14);
        }
        FUN_00012490();
        (&DAT_00017e40)[*param_1 * 5] = 0xffffffff;
        FUN_0000cdb4((int)*(short *)(&DAT_00017e32 + *param_1 * 0x14));
        *param_2 = *(undefined4 *)(&DAT_00017e38 + *param_1 * 0x14);
        *param_3 = *(undefined2 *)(&DAT_00017e3c + *param_1 * 0x14);
        *param_4 = *(undefined2 *)(&DAT_00017e3e + *param_1 * 0x14);
        iVar2 = (int)*(short *)(&DAT_00017e32 + *param_1 * 0x14);
      }
    }
    else {
      (&DAT_00017e40)[*param_1 * 5] = 0xffffffff;
    }
  }
  else {
    iVar2 = -4;
  }
  return iVar2;
}


================================================================