FUNCTION FUN_00008dc4 @ 0x00008dc4 size=2568
CALLERS (1): FUN_0000b3d4@0x0000b3d4
CALLEES (4): FUN_0000139c@0x0000139c, FUN_00001454@0x00001454, FUN_000010c0@0x000010c0, FUN_00011d00@0x00011d00

/* WARNING: Removing unreachable block (ram,0x0000971c) */

undefined4 FUN_00008dc4(uint param_1,uint param_2,int *param_3,int param_4)

{
  ushort uVar1;
  bool bVar2;
  short sVar3;
  short sVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  short *psVar8;
  int iVar9;
  int *piVar10;
  int *piVar11;
  uint uVar12;
  int iVar13;
  int iVar14;
  ushort *puVar15;
  ushort *puVar16;
  int iVar17;
  undefined1 auStack_68 [8];
  short local_60;
  short local_5e;
  undefined1 auStack_58 [4];
  undefined1 local_54;
  undefined1 auStack_50 [4];
  undefined1 local_4c;
  undefined1 auStack_48 [4];
  undefined1 local_44;
  undefined1 auStack_40 [8];
  int local_38;
  ushort local_30;
  
  if ((*(uint *)(param_4 + 0xd8) & 1) == 1) {
    local_54 = 1;
    local_4c = 1;
    local_44 = 1;
    if ((param_2 == 0) || (*(int *)(param_4 + 8) == 0)) {
      return 0xffffffff;
    }
    FUN_0000139c(auStack_48,auStack_68);
    iVar9 = *(int *)(param_4 + 0xc);
    FUN_00011d00(auStack_58,param_4,8);
    if (iVar9 != 0) {
      FUN_00001454(auStack_58,(iVar9 << 0x14) >> 0x10);
    }
    FUN_000010c0(auStack_48,auStack_58,0x10);
    if (param_1 == 0) {
      FUN_00011d00(auStack_50,auStack_68,8);
    }
    else {
      if ((uint)(int)local_60 <= param_1) {
        do {
          param_1 = param_1 - (int)local_60;
          if (iVar9 < DAT_0001619e) {
            iVar9 = iVar9 + 1;
          }
          else {
            iVar9 = 0;
          }
          FUN_00011d00(auStack_58,param_4,8);
          if (iVar9 != 0) {
            FUN_00001454(auStack_58,(iVar9 << 0x14) >> 0x10);
          }
          FUN_000010c0(auStack_48,auStack_58,0x10);
        } while ((uint)(int)local_60 <= param_1);
      }
      FUN_00011d00(auStack_50,auStack_68,8);
      local_60 = local_60 - (short)param_1;
      FUN_00001454(auStack_50,(int)local_5e);
      local_5e = (short)param_1;
    }
    FUN_00001454(auStack_50,(int)local_5e);
    iVar13 = *param_3;
    if (param_2 != 0) {
      do {
        piVar10 = param_3 + *param_3 * 3 + 2;
        if (param_2 < (uint)(int)local_60) {
          *(short *)piVar10 = (short)param_2;
          iVar14 = param_3[1] + param_2;
          param_2 = 0;
          param_3[1] = iVar14;
        }
        else {
          *(short *)piVar10 = local_60;
          param_3[1] = param_3[1] + (int)local_60;
          param_2 = param_2 - (int)local_60;
        }
        FUN_00011d00(piVar10 + 1,auStack_50,8);
        *param_3 = *param_3 + 1;
        if (param_2 == 0) break;
        bVar2 = DAT_0001619e <= iVar9;
        iVar9 = iVar9 + 1;
        if (bVar2) {
          iVar9 = 0;
        }
        FUN_00011d00(auStack_58,param_4,8);
        if (iVar9 != 0) {
          FUN_00001454(auStack_58,(iVar9 << 0x14) >> 0x10);
        }
        FUN_000010c0(auStack_48,auStack_58,0x10);
        FUN_00011d00(auStack_50,auStack_68,8);
      } while (param_2 != 0);
    }
    local_38 = *param_3 - iVar13;
    iVar9 = (local_38 + -2) / 2;
    iVar13 = (local_38 + 1) / 2;
    if (iVar9 < 0) {
      return 0;
    }
    piVar11 = param_3 + iVar13 * 3;
    iVar17 = iVar13 * 0xc + 8;
    piVar10 = param_3 + iVar9 * 3;
    iVar14 = iVar9 * 0xc + 8;
    do {
      if (local_38 <= iVar13) {
        return 0;
      }
      iVar6 = (int)param_3 + iVar17 + 4;
      FUN_00011d00(auStack_40,iVar6,8);
      iVar7 = (int)param_3 + iVar14 + 4;
      FUN_00011d00(iVar6,iVar7,8);
      FUN_00011d00(iVar7,auStack_40,4);
      iVar14 = iVar14 + -0xc;
      iVar9 = iVar9 + -1;
      iVar17 = iVar17 + 0xc;
      iVar6 = piVar11[2];
      iVar13 = iVar13 + 1;
      *(short *)(piVar11 + 2) = (short)piVar10[2];
      *(short *)(piVar10 + 2) = (short)iVar6;
      piVar10 = piVar10 + -3;
      piVar11 = piVar11 + 3;
    } while (-1 < iVar9);
    return 0;
  }
  iVar13 = 0;
  local_30 = (ushort)param_1;
  uVar5 = *(uint *)(param_4 + 8);
  iVar9 = param_1 + *(ushort *)(param_4 + 0xc);
  if (uVar5 + *(int *)(param_4 + 0x18) <= param_1) {
    return 0xffffffff;
  }
  sVar4 = (short)param_2;
  if (uVar5 <= param_1) {
    param_1 = param_1 - uVar5;
    uVar5 = 0;
    puVar15 = (ushort *)(param_4 + 0x1c);
    if (*(int *)(param_4 + 0x14) == 0) {
      return 0;
    }
    while ((uint)(int)(short)*puVar15 <= param_1) {
      param_1 = param_1 - (int)(short)*puVar15;
      uVar5 = uVar5 + 1;
      puVar15 = puVar15 + 6;
      if (*(uint *)(param_4 + 0x14) <= uVar5) {
        return 0;
      }
    }
    *param_3 = 1;
    local_30 = (ushort)param_1;
    FUN_00011d00(param_3 + 3,puVar15 + 2,8);
    FUN_00001454(param_3 + 3,(int)(short)(ushort)param_1);
    param_3[1] = param_2;
    *(short *)(param_3 + 2) = sVar4;
    uVar1 = *puVar15;
    if ((uint)(int)(short)*puVar15 < param_2 + param_1) {
      *puVar15 = (ushort)(uVar1 - param_1);
      iVar9 = (uVar1 - param_1) * 0x10000;
      param_3[1] = iVar9 >> 0x10;
      *(short *)(param_3 + 2) = (short)((uint)iVar9 >> 0x10);
      uVar12 = uVar5 + 1;
      iVar9 = uVar12 - uVar5;
      if (uVar12 < *(uint *)(param_4 + 0x14)) {
        do {
          iVar13 = uVar12 - local_30;
          iVar14 = iVar9 << 0x10;
          while (0 < iVar14) {
            iVar13 = iVar13 + -1;
            sVar4 = (short)iVar9;
            iVar14 = iVar13 * 0x10000 >> 0x10;
            FUN_00011d00(param_3 + sVar4 * 3 + 3,param_3 + iVar14 * 3 + 3,8);
            iVar9 = iVar9 + -1;
            *(short *)(param_3 + sVar4 * 3 + 2) = (short)param_3[iVar14 * 3 + 2];
            iVar14 = iVar9 * 0x10000;
          }
          puVar16 = puVar15 + 6;
          param_2 = param_2 - (int)(short)*puVar15;
          *param_3 = *param_3 + 1;
          FUN_00011d00(param_3 + 3,puVar15 + 8,8);
          uVar12 = uVar12 + 1;
          if (param_2 <= (uint)(int)(short)*puVar16) {
            *(short *)(param_3 + 2) = (short)param_2;
            param_3[1] = param_3[1] + param_2;
            return 0;
          }
          *(ushort *)(param_3 + 2) = *puVar16;
          param_3[1] = param_3[1] + (int)(short)*puVar16;
          iVar9 = uVar12 - uVar5;
          puVar15 = puVar16;
        } while (uVar12 < *(uint *)(param_4 + 0x14));
      }
      param_3[1] = 0;
      *(undefined2 *)(param_3 + 5) = 0;
      *(undefined2 *)(param_3 + 2) = 0;
      return 0;
    }
    param_3[1] = param_2;
    *(short *)(param_3 + 2) = sVar4;
    return 0;
  }
  if (uVar5 < param_2 + param_1) {
    param_2 = param_2 - (uVar5 - (param_1 & 0xffff));
    uVar5 = 0;
    psVar8 = (short *)(param_4 + 0x1c);
    if (*(uint *)(param_4 + 0x14) != 0) {
      do {
        if (param_2 <= (uint)(int)*psVar8) {
          *param_3 = 1;
          FUN_00011d00(param_3 + 3,psVar8 + 2,8);
          iVar13 = 1;
          param_3[1] = param_2;
          *(short *)(param_3 + 2) = (short)param_2;
          break;
        }
        param_2 = param_2 - (int)*psVar8;
        uVar5 = uVar5 + 1;
        psVar8 = psVar8 + 6;
      } while (uVar5 < *(uint *)(param_4 + 0x14));
    }
    iVar9 = uVar5 - 1;
    if (-1 < iVar9) {
      piVar10 = param_3 + iVar13 * 3;
      iVar14 = iVar13 * 0xc + 8;
      do {
        iVar17 = iVar14 + 4;
        iVar14 = iVar14 + 0xc;
        iVar13 = iVar13 + 1;
        iVar9 = iVar9 + -1;
        *param_3 = *param_3 + 1;
        FUN_00011d00((int)param_3 + iVar17,psVar8 + -4,8);
        sVar4 = psVar8[-6];
        *(short *)(piVar10 + 2) = sVar4;
        param_3[1] = param_3[1] + (int)sVar4;
        piVar10 = piVar10 + 3;
        psVar8 = psVar8 + -6;
      } while (-1 < iVar9);
    }
    piVar10 = param_3 + iVar13 * 3 + 2;
    uVar5 = (uint)local_30 + (uint)*(ushort *)(param_4 + 0xc);
    if ((int)(uVar5 & 0xffff) < (int)(short)DAT_000161a4) {
      if ((uint)(int)(short)DAT_000161a4 < (uint)(*(int *)(param_4 + 0xc) + *(int *)(param_4 + 8)))
      {
        *param_3 = *param_3 + 2;
        FUN_00011d00(piVar10 + 1,param_4,8);
        FUN_00011d00(piVar10 + 4,param_4,8);
        FUN_00001454(piVar10 + 4,(int)(uVar5 * 0x10000) >> 0x10);
        sVar3 = *(short *)(param_4 + 8);
        sVar4 = DAT_000161a4 - (short)uVar5;
        *(short *)(piVar10 + 3) = sVar4;
        sVar4 = (sVar3 - local_30) - sVar4;
        goto LAB_000096d0;
      }
      *param_3 = *param_3 + 1;
      FUN_00011d00(piVar10 + 1,param_4,8);
    }
    else {
      *param_3 = *param_3 + 1;
      FUN_00011d00(piVar10 + 1,param_4,8);
      uVar5 = uVar5 - DAT_000161a4;
    }
    FUN_00001454(piVar10 + 1,(int)(uVar5 * 0x10000) >> 0x10);
    sVar4 = *(short *)(param_4 + 8) - local_30;
LAB_000096d0:
    *(short *)piVar10 = sVar4;
    param_3[1] = param_3[1] + (*(int *)(param_4 + 8) - (uint)local_30);
    return 0;
  }
  param_1 = *(int *)(param_4 + 0xc) + param_1;
  if (param_1 < (uint)(int)(short)DAT_000161a4) {
    if ((uint)(int)(short)DAT_000161a4 < param_1 + param_2) {
      *param_3 = 2;
      FUN_00011d00(param_3 + 3,param_4,8);
      FUN_00011d00(param_3 + 6,param_4,8);
      FUN_00001454(param_3 + 6,iVar9 * 0x10000 >> 0x10);
      sVar3 = DAT_000161a4 - (short)iVar9;
      *(short *)(param_3 + 5) = sVar3;
      *(short *)(param_3 + 2) = sVar4 - sVar3;
      goto LAB_00009298;
    }
    *param_3 = 1;
    FUN_00011d00(param_3 + 3,param_4,8);
  }
  else {
    *param_3 = 1;
    FUN_00011d00(param_3 + 3,param_4,8);
    iVar9 = iVar9 - (uint)DAT_000161a4;
  }
  FUN_00001454(param_3 + 3,iVar9 * 0x10000 >> 0x10);
  *(short *)(param_3 + 2) = sVar4;
LAB_00009298:
  param_3[1] = param_2;
  return 0;
}


================================================================