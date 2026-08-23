FUNCTION FUN_00010694 @ 0x00010694 size=492
CALLERS (1): FUN_00000600@0x00000600
CALLEES (6): FUN_000124b8@0x000124b8, FUN_00011e58@0x00011e58, FUN_000013ac@0x000013ac, FUN_0000dbac@0x0000dbac, FUN_00012090@0x00012090, FUN_00012490@0x00012490

int FUN_00010694(short *param_1)

{
  short sVar1;
  int iVar2;
  undefined1 auStack_18 [8];
  
  iVar2 = -4;
  if ((*param_1 < (short)(ushort)DAT_0001619b) && (-1 < *param_1)) {
    FUN_000013ac(auStack_18,*(undefined4 *)(param_1 + 6));
    sVar1 = param_1[5];
    *(undefined2 *)(&DAT_00018860 + *param_1 * 8) = 0xffff;
    if (*(int *)(param_1 + 2) == 0) {
      FUN_00011e58(&DAT_00018864 + *param_1 * 2);
      if ((&DAT_00018864)[*param_1 * 2] == -1) {
        return -0x10;
      }
    }
    else {
      (&DAT_00018864)[*param_1 * 2] = 0xffffffff;
    }
    sVar1 = FUN_0000dbac((int)*param_1,auStack_18,(int)sVar1,*(undefined4 *)(param_1 + 2),
                         (char)param_1[4]);
    iVar2 = (int)sVar1;
    if (iVar2 < 0) {
      (&DAT_00018864)[*param_1 * 2] = 0xffffffff;
    }
    else {
      iVar2 = -1;
      if (*(int *)(param_1 + 2) == 0) {
        FUN_000124b8();
        sVar1 = *(short *)(&DAT_00018860 + *param_1 * 8);
        while (sVar1 == -1) {
          FUN_00012090();
          sVar1 = *(short *)(&DAT_00018860 + *param_1 * 8);
        }
        FUN_00012490();
        (&DAT_00018864)[*param_1 * 2] = 0xffffffff;
        iVar2 = (int)*(short *)(&DAT_00018862 + *param_1 * 8);
      }
    }
  }
  return iVar2;
}


================================================================