FUNCTION FUN_000102e4 @ 0x000102e4 size=776
CALLERS (1): FUN_00000594@0x00000594
CALLEES (6): FUN_00012090@0x00012090, FUN_00012490@0x00012490, FUN_000124b8@0x000124b8, FUN_00011e58@0x00011e58, FUN_000013ac@0x000013ac, FUN_0000d9c8@0x0000d9c8

int FUN_000102e4(short *param_1)

{
  short sVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint local_b0;
  int local_ac;
  short local_a8 [2];
  undefined1 auStack_a4 [140];
  
  iVar2 = -4;
  if ((*param_1 < (short)(ushort)DAT_0001619b) && (-1 < *param_1)) {
    local_ac = 0;
    local_b0 = (uint)*(byte *)((int)param_1 + 9);
    iVar2 = -0xc;
    if (*(byte *)((int)param_1 + 9) < 5) {
      uVar4 = 0;
      if (local_b0 != 0) {
        uVar3 = 0;
        do {
          FUN_000013ac(auStack_a4 + uVar3 * 0xc,*(undefined4 *)(param_1 + uVar3 * 4 + 8));
          sVar1 = param_1[uVar3 * 4 + 6];
          local_a8[uVar3 * 6] = sVar1;
          local_ac = local_ac + sVar1;
          uVar4 = uVar4 + 1;
          uVar3 = uVar4 & 0xffff;
        } while ((uVar4 & 0xffff) < local_b0);
      }
      iVar2 = 0;
      if (local_ac != 0) {
        *(undefined2 *)(&DAT_00018820 + *param_1 * 0xc) = 0xffff;
        *(short *)(&DAT_00018824 + *param_1 * 0xc) = *param_1;
        if (*(int *)(param_1 + 2) == 0) {
          FUN_00011e58(&DAT_00018828 + *param_1 * 3);
          if ((&DAT_00018828)[*param_1 * 3] == -1) {
            return -0x4d2;
          }
        }
        else {
          (&DAT_00018828)[*param_1 * 3] = 0xffffffff;
        }
        sVar1 = FUN_0000d9c8((int)*param_1,&local_b0,*(undefined4 *)(param_1 + 2),(char)param_1[4]);
        iVar2 = (int)sVar1;
        if (iVar2 < 0) {
          (&DAT_00018828)[*param_1 * 3] = 0xffffffff;
        }
        else {
          iVar2 = -1;
          if (*(int *)(param_1 + 2) == 0) {
            FUN_000124b8();
            sVar1 = *(short *)(&DAT_00018820 + *param_1 * 0xc);
            while (sVar1 == -1) {
              FUN_00012090();
              sVar1 = *(short *)(&DAT_00018820 + *param_1 * 0xc);
            }
            FUN_00012490();
            (&DAT_00018828)[*param_1 * 3] = 0xffffffff;
            iVar2 = (int)*(short *)(&DAT_00018822 + *param_1 * 0xc);
          }
        }
      }
    }
  }
  return iVar2;
}


================================================================