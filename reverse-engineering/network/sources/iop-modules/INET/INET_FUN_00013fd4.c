FUNCTION FUN_00013fd4 @ 0x00013fd4 size=756
CALLERS (9): FUN_00014df8@0x00014df8, FUN_00015158@0x00015158, FUN_00014c8c@0x00014c8c, FUN_00014ad4@0x00014ad4, FUN_00015290@0x00015290, FUN_000151ec@0x000151ec, FUN_000150c8@0x000150c8, FUN_00014eb8@0x00014eb8, FUN_00014fd8@0x00014fd8
CALLEES (5): FUN_00013744@0x00013744, FUN_000137c8@0x000137c8, FUN_00017540@0x00017540, FUN_0001380c@0x0001380c, FUN_0000a104@0x0000a104

undefined4 FUN_00013fd4(int param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  iVar4 = *(int *)(param_2 + 8);
  uVar1 = 0xffffffff;
  if ((*(byte *)(param_2 + 0xd) & 0x10) != 0) {
    iVar6 = iVar4 - *(int *)(param_1 + 0x38);
    uVar1 = 0;
    if (0 < iVar6) {
      if (*(int *)(param_1 + 0x3c) - iVar4 < 0) {
        if (*(int *)(param_1 + 0x28) == 3) {
          FUN_00013744(param_1);
          uVar1 = 0;
        }
        else {
          uVar1 = 0;
          if (*(int *)(param_1 + 0x6c) == 0) {
            FUN_000137c8(param_1);
            uVar1 = 0;
          }
        }
      }
      else {
        if ((*(int *)(param_1 + 0x68) == 0) && (0 < *(int *)(param_1 + 0xb0))) {
          iVar2 = FUN_00017540();
          iVar2 = iVar2 - *(int *)(param_1 + 0xac);
          if (iVar2 < 0) {
            iVar2 = 0;
          }
          iVar3 = *(int *)(param_1 + 0x60);
          if (iVar3 == 0) {
            *(int *)(param_1 + 0x60) = iVar2 << 3;
            iVar3 = *(int *)(param_1 + 0x60);
          }
          iVar2 = iVar2 - (iVar3 >> 3);
          *(int *)(param_1 + 0x60) = iVar3 + iVar2;
          if (iVar2 < 0) {
            iVar2 = -iVar2;
          }
          iVar2 = *(int *)(param_1 + 100) + (iVar2 - (*(int *)(param_1 + 100) >> 2));
          iVar3 = (*(int *)(param_1 + 0x60) >> 2) + iVar2 >> 1;
          *(int *)(param_1 + 100) = iVar2;
          *(int *)(param_1 + 0x5c) = iVar3;
          iVar2 = 64000;
          if (iVar3 < 64000) {
            iVar2 = iVar3;
          }
          *(int *)(param_1 + 0x5c) = iVar2;
          if (iVar2 < 1000) {
            iVar2 = 1000;
          }
          iVar5 = *(int *)(param_1 + 0x54);
          iVar3 = *(int *)(param_1 + 0x4c);
          *(int *)(param_1 + 0x5c) = iVar2;
          if (*(int *)(param_1 + 0x50) < iVar3) {
            if (iVar3 == 0) {
              trap(0x1c00);
            }
            if ((iVar3 == -1) && (iVar5 * iVar5 == -0x80000000)) {
              trap(0x1800);
            }
            iVar5 = (iVar5 * iVar5) / iVar3 + (iVar5 >> 3);
          }
          *(int *)(param_1 + 0x4c) = iVar3 + iVar5;
        }
        *(int *)(param_1 + 0x38) = iVar4;
        if ((*(uint *)(param_1 + 0x2c) & 4) != 0) {
          iVar6 = iVar6 + -1;
          *(uint *)(param_1 + 0x2c) = *(uint *)(param_1 + 0x2c) & 0xfffffffb | 8;
        }
        if (0 < iVar6) {
          if (((*(uint *)(param_1 + 0x2c) & 0x20) != 0) && (iVar4 == *(int *)(param_1 + 0x3c))) {
            iVar6 = iVar6 + -1;
            *(uint *)(param_1 + 0x2c) = *(uint *)(param_1 + 0x2c) & 0xffffffdf | 0x40;
          }
          if (0 < iVar6) {
            FUN_0000a104(param_1 + 0x84,0,iVar6,0,1);
            iVar4 = *(int *)(param_1 + 0x8c) - iVar6;
            *(int *)(param_1 + 0x8c) = iVar4;
            if (iVar4 < 0) {
              *(undefined4 *)(param_1 + 0x8c) = 0;
            }
          }
        }
        uVar1 = FUN_00017540();
        *(undefined4 *)(param_1 + 0xac) = uVar1;
        if (*(int *)(param_1 + 0x8c) < 1) {
          *(undefined4 *)(param_1 + 0x68) = 0;
          *(undefined4 *)(param_1 + 0xb0) = 0;
        }
        else if (*(int *)(param_1 + 0x68) < 1) {
          if (iVar6 < 1) {
            return 0;
          }
          *(undefined4 *)(param_1 + 0x68) = 0;
          uVar1 = FUN_00017540();
          *(undefined4 *)(param_1 + 0xac) = uVar1;
          *(undefined4 *)(param_1 + 0xb0) = *(undefined4 *)(param_1 + 0x5c);
        }
        else {
          *(undefined4 *)(param_1 + 0x68) = 0;
          *(undefined4 *)(param_1 + 0xb0) = *(undefined4 *)(param_1 + 0x5c);
          if (*(int *)(param_1 + 0x54) <= iVar6) {
            FUN_0001380c(param_1);
            return 0;
          }
        }
        uVar1 = 0;
      }
    }
  }
  return uVar1;
}


================================================================