FUNCTION FUN_00018de4 @ 0x00018de4 size=1004
CALLERS (1): FUN_000191d0@0x000191d0
CALLEES (8): FUN_0001866c@0x0001866c, FUN_0000e4e8@0x0000e4e8, FUN_0000a9c0@0x0000a9c0, FUN_00018170@0x00018170, FUN_000088e8@0x000088e8, FUN_00009e60@0x00009e60, FUN_00006200@0x00006200, FUN_00009eec@0x00009eec

int FUN_00018de4(int param_1,int param_2,int param_3,undefined4 param_4,uint param_5,uint param_6)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  ushort *puVar6;
  uint uVar7;
  int *piVar8;
  int iVar9;
  int iVar10;
  undefined4 uVar11;
  int local_res4;
  int local_38;
  int local_34;
  undefined4 local_30;
  
  local_38 = 0;
  local_34 = 0;
  local_30 = 0x40;
  iVar10 = 0;
  if (*(int *)(param_1 + 0xc) == 2) {
    iVar9 = -0x1f9;
    if ((*(short *)(param_1 + 0x1e) != 0) && (iVar9 = -0x1fa, param_5 != 0)) {
      if (param_6 == 0) {
        iVar9 = -0x1fa;
      }
      else {
        if ((param_5 & 0xf0000000) == 0xe0000000) {
          iVar10 = FUN_000088e8(*(undefined4 *)(param_1 + 0x3c));
          if ((iVar10 == 0) && (iVar10 = FUN_0000e4e8(param_5), iVar10 == 0)) {
            return -0x202;
          }
          if ((*(uint *)(iVar10 + 0x48) & 0x400) == 0) {
            return -0x202;
          }
          local_30 = *(undefined4 *)(param_1 + 0x40);
          local_34 = *(int *)(param_1 + 0x44);
        }
        else if ((param_5 != 0xffffffff) && (iVar10 = FUN_0000e4e8(param_5), iVar10 == 0)) {
          return -0x202;
        }
        uVar11 = 0;
        local_res4 = param_2;
        if (iVar10 != 0) {
          uVar11 = *(undefined4 *)(iVar10 + 0x70);
        }
        while (iVar9 = local_38, local_38 < param_3) {
          iVar9 = param_3 - local_38;
          if (DAT_0001b9d4 <= DAT_0001b9e0) {
            return -0x1f8;
          }
          iVar2 = 0;
          if (iVar10 != 0) {
            iVar2 = *(int *)(iVar10 + 0x84);
          }
          if (iVar2 < 1) {
            iVar2 = 0x5dc;
          }
          if ((iVar10 == 0) || (iVar5 = 0x1c, iVar2 + -0x1c < iVar9)) {
            iVar2 = FUN_00009e60(local_res4,iVar9);
            if (iVar2 == 0) {
              return -0x1f8;
            }
          }
          else {
            uVar7 = 0x2200;
            if ((*(uint *)(iVar10 + 0x48) & 0x10) != 0) {
              iVar5 = 0x2a;
              uVar7 = 0x2600;
              if ((*(uint *)(iVar10 + 0x48) & 0x80) == 0) {
                iVar5 = 0x2c;
                uVar7 = 0x2e00;
              }
            }
            iVar2 = FUN_00009e60(0,iVar5 + iVar9);
            if (iVar2 == 0) {
              return -0x1f8;
            }
            iVar3 = *(int *)(iVar2 + 0x14) + iVar5;
            *(int *)(iVar2 + 0x14) = iVar3;
            *(uint *)(iVar2 + 0xc) = *(uint *)(iVar2 + 0xc) | uVar7;
            *(int *)(iVar2 + 0x10) = *(int *)(iVar2 + 0x10) + iVar5;
            FUN_0000a9c0(local_res4,iVar3,iVar9);
            *(int *)(iVar2 + 0x14) = *(int *)(iVar2 + 0x14) + iVar9;
          }
          if ((local_34 != 0) && (piVar8 = *(int **)(param_1 + 0x50), piVar8 != (int *)0x0)) {
            do {
              if ((param_5 == piVar8[2]) && (iVar5 = FUN_00009e60(0,iVar9 + 8), iVar5 != 0)) {
                puVar6 = *(ushort **)(iVar5 + 0x14);
                *puVar6 = *(ushort *)(param_1 + 0x1e);
                puVar6[2] = (ushort)(iVar9 + 8);
                puVar6[3] = 0;
                puVar6[1] = (ushort)param_6;
                iVar3 = *(int *)(iVar5 + 0x14) + 8;
                *(int *)(iVar5 + 0x14) = iVar3;
                FUN_0000a9c0(local_res4,iVar3,iVar9);
                *(int *)(iVar5 + 0x14) = *(int *)(iVar5 + 0x14) + iVar9;
                *puVar6 = *puVar6 << 8 | *puVar6 >> 8;
                puVar6[1] = puVar6[1] << 8 | puVar6[1] >> 8;
                puVar6[2] = puVar6[2] << 8 | puVar6[2] >> 8;
                uVar1 = FUN_00006200(0x11,uVar11,param_5,iVar5);
                puVar6[3] = ~uVar1;
                uVar4 = FUN_0001866c(iVar10,uVar11,param_5,local_30,iVar5);
                FUN_00009eec(uVar4);
              }
              piVar8 = (int *)*piVar8;
            } while (piVar8 != (int *)0x0);
          }
          local_38 = local_38 + iVar9;
          FUN_00018170(iVar10,iVar2,local_30,uVar11,*(undefined2 *)(param_1 + 0x1e),param_5,
                       param_6 & 0xffff);
          local_res4 = local_res4 + iVar9;
        }
      }
    }
  }
  else {
    iVar9 = -0x1fc;
  }
  return iVar9;
}


================================================================