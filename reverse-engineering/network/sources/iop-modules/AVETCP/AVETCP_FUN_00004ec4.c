FUNCTION FUN_00004ec4 @ 0x00004ec4 size=2404
CALLERS (5): FUN_0000af84@0x0000af84, FUN_0000353c@0x0000353c, FUN_00001dd0@0x00001dd0, FUN_0000b3d4@0x0000b3d4, FUN_00004cac@0x00004cac
CALLEES (13): FUN_0000139c@0x0000139c, FUN_000041b0@0x000041b0, FUN_00001454@0x00001454, FUN_00005f10@0x00005f10, FUN_00004254@0x00004254, FUN_00014e24@0x00014e24, FUN_0000223c@0x0000223c, FUN_000010c0@0x000010c0, FUN_000010a8@0x000010a8, FUN_00005e38@0x00005e38, FUN_00012608@0x00012608, FUN_00011d00@0x00011d00, FUN_0000f228@0x0000f228

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
FUN_00004ec4(uint *param_1,int param_2,char param_3,char param_4,char param_5,char param_6,
            ushort param_7,int param_8,undefined1 param_9)

{
  uint *puVar1;
  bool bVar2;
  short sVar3;
  ushort uVar4;
  undefined2 uVar5;
  int iVar6;
  undefined4 uVar7;
  uint uVar8;
  uint *puVar9;
  int iVar10;
  int iVar11;
  uint uVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  int *piVar16;
  int local_res4 [3];
  undefined1 auStack_100 [8];
  int local_f8;
  uint local_f4;
  undefined2 local_f0 [2];
  undefined1 auStack_ec [140];
  undefined1 local_60;
  int local_5c;
  int local_58;
  ushort local_50;
  short local_48;
  short local_40;
  int local_38;
  int local_34;
  int local_30;
  
  iVar15 = 5;
  uVar12 = 0;
  local_60 = param_9;
  local_res4[0] = param_2;
  sVar3 = FUN_000041b0(param_2);
  if ((((sVar3 == -1) && (sVar3 = FUN_00005f10(local_res4[0],0), sVar3 != 1)) &&
      ((DAT_0001616c != 1 || (local_res4[0] == -1)))) &&
     ((local_5c = FUN_0000f228(local_res4[0]), local_5c != 0 &&
      (iVar6 = FUN_00004254((int)*(short *)(local_5c + 0x14)), iVar6 != 0)))) {
    if (param_3 == '\x01') {
      FUN_00001454(param_1 + *param_1 * 3,0xe);
      FUN_0000139c(auStack_100,&DAT_00016880);
      FUN_000010c0(auStack_100,param_1 + *param_1 * 3,0x14);
      FUN_00001454(param_1 + *param_1 * 3,0x14);
      *(short *)(param_1 + (*param_1 - 1) * 3 + 2) = (short)param_1[(*param_1 - 1) * 3 + 2] + -0x22;
      param_1[1] = param_1[1] - 0x22;
    }
    if ((param_7 != 0) && (param_8 != 0)) {
      iVar15 = ((param_7 + 3 & 0xff) >> 2) + 5;
    }
    DAT_00016880 = (byte)iVar15 | 0x40;
    if (param_3 == '\0') {
      if (param_5 == '\0') {
        DAT_00016881 = '\0';
      }
      else {
        DAT_00016881 = param_5;
      }
      DAT_00016888 = param_4;
      if (param_4 == '\0') {
        DAT_00016888 = 'x';
      }
    }
    uVar8 = 0;
    puVar9 = param_1;
    if (*param_1 != 0) {
      do {
        uVar8 = uVar8 + 1;
        uVar12 = uVar12 + (ushort)puVar9[2];
        puVar9 = puVar9 + 3;
      } while (uVar8 < *param_1);
    }
    if ((uVar12 & 0xffff) != 0) {
      iVar13 = (int)((uVar12 + iVar15 * 4) * 0x10000) >> 0x10;
      DAT_00016882 = FUN_000010a8(iVar13);
      DAT_00016889 = local_60;
      iVar10 = (int)DAT_00016898;
      DAT_00016898 = DAT_00016898 + 1;
      DAT_00016884 = FUN_000010a8(iVar10);
      FUN_00011d00(&DAT_00016890,local_res4,4);
      FUN_00011d00(&DAT_0001688c,iVar6 + 4,4);
      local_58 = *(int *)(local_5c + 8);
      if (*(int *)(iVar6 + 4) == local_58) {
        local_58 = local_res4[0];
      }
      if (iVar13 <= *(short *)(iVar6 + 2)) {
        DAT_00016886 = 0;
        if (param_6 != '\0') {
          DAT_00016886 = FUN_000010a8(0x4000);
        }
        iVar6 = 0;
        uVar12 = 0;
        puVar9 = param_1;
        if (*param_1 != 0) {
          do {
            uVar12 = uVar12 + 1;
            iVar6 = iVar6 + (uint)(ushort)puVar9[2];
            puVar9 = puVar9 + 3;
          } while (uVar12 < *param_1);
        }
        DAT_00016882 = FUN_000010a8((iVar6 + iVar15 * 4) * 0x10000 >> 0x10);
        _DAT_0001688a = 0;
        uVar5 = FUN_00005e38(&DAT_00016880,10);
        uVar12 = *param_1;
        _DAT_0001688a = CONCAT11((char)uVar5,(char)((ushort)uVar5 >> 8));
        FUN_0000139c(param_1 + uVar12 * 3 + 3,&DAT_00016880);
        *(short *)(param_1 + uVar12 * 3 + 2) = (short)(iVar15 * 4);
        *param_1 = *param_1 + 1;
        if ((DAT_00016178 & 0x10) != 0) {
          uVar7 = FUN_00012608();
          uVar5 = FUN_000010a8((int)DAT_00016882);
          FUN_00014e24("IP SEND: %u src %d.%d.%d.%d dst %d.%d.%d.%d len %d protocol %d\n",uVar7,
                       DAT_0001688c,DAT_0001688d,DAT_0001688e,DAT_0001688f,DAT_00016890,DAT_00016891
                       ,DAT_00016892,DAT_00016893,uVar5,DAT_00016889);
        }
        sVar3 = FUN_0000223c(param_1,local_58,(int)*(short *)(local_5c + 0x14));
        if (sVar3 == 0) {
          return 0;
        }
        return 0xffffffff;
      }
      if (param_6 != '\0') {
        return 0xffffffff;
      }
      DAT_00016886 = 0;
      iVar6 = (int)*(short *)(iVar6 + 2) + iVar15 * -4;
      local_48 = 0;
      if (iVar6 < 0) {
        iVar6 = iVar6 + 7;
      }
      local_34 = (iVar6 >> 3) << 0x13;
      local_50 = (ushort)((iVar6 >> 3) << 3);
      local_30 = local_34 >> 0x10;
      local_38 = iVar15 * 4;
      do {
        uVar12 = (uint)local_50;
        local_f8 = 0;
        local_f4 = 0;
        sVar3 = 0;
        iVar15 = *param_1 - 1;
        if (0 < local_30) {
          puVar9 = param_1 + iVar15 * 3;
          sVar3 = 0;
          do {
            bVar2 = iVar15 < 0;
            iVar15 = iVar15 + -1;
            if (bVar2) break;
            puVar1 = puVar9 + 2;
            puVar9 = puVar9 + -3;
            uVar12 = uVar12 - (ushort)*puVar1;
            sVar3 = sVar3 + 1;
          } while (0 < (int)(uVar12 * 0x10000));
        }
        iVar15 = sVar3 + -1;
        local_40 = 0;
        iVar6 = *param_1 - 1;
        if (0 < local_30) {
          iVar13 = iVar6 * 0xc + 8;
          puVar9 = param_1 + iVar6 * 3;
          piVar16 = &local_f8 + iVar15 * 3;
          iVar10 = iVar15 * 0xc + 8;
          uVar4 = local_50;
          do {
            if (iVar15 < 0) break;
            iVar14 = (int)param_1 + iVar13 + 4;
            FUN_00011d00((int)local_f0 + iVar10 + -4,iVar14,8);
            iVar11 = (int)(short)uVar4;
            if (iVar11 < (short)puVar9[2]) {
              *(ushort *)(piVar16 + 2) = uVar4;
              local_f4 = local_f4 + iVar11;
              *(ushort *)(puVar9 + 2) = (short)puVar9[2] - uVar4;
              uVar4 = 0;
              param_1[1] = param_1[1] - iVar11;
              FUN_00001454(iVar14);
            }
            else {
              *(short *)(piVar16 + 2) = (short)puVar9[2];
              local_f4 = local_f4 + (int)(short)puVar9[2];
              param_1[1] = param_1[1] - (int)(short)puVar9[2];
              uVar4 = uVar4 - (short)puVar9[2];
              if (iVar6 == 0) {
                uVar4 = (ushort)param_1[2];
                piVar16 = piVar16 + -3;
                iVar10 = iVar10 + -0xc;
                iVar15 = iVar15 + -1;
                iVar13 = -4;
                local_40 = 1;
                iVar6 = -1;
                puVar9 = param_1 + -3;
              }
              else {
                piVar16 = piVar16 + -3;
                iVar10 = iVar10 + -0xc;
                iVar15 = iVar15 + -1;
                puVar9 = puVar9 + -3;
                iVar13 = iVar13 + -0xc;
                iVar6 = iVar6 + -1;
                *param_1 = *param_1 - 1;
              }
            }
            local_f8 = local_f8 + 1;
          } while (0 < (int)((uint)uVar4 << 0x10));
        }
        if (local_40 == 1) {
          DAT_00016886 = 0;
        }
        else {
          DAT_00016886 = FUN_000010a8(0x2000);
        }
        uVar4 = FUN_000010a8((int)local_48);
        DAT_00016886 = DAT_00016886 | uVar4;
        DAT_00016882 = FUN_000010a8((int)(((local_f4 & 0xffff) + local_38) * 0x10000) >> 0x10);
        _DAT_0001688a = 0;
        uVar5 = FUN_00005e38(&DAT_00016880,10);
        iVar15 = local_f8;
        _DAT_0001688a = CONCAT11((char)uVar5,(char)((ushort)uVar5 >> 8));
        FUN_0000139c(auStack_ec + local_f8 * 0xc,&DAT_00016880);
        local_f0[iVar15 * 6] = (undefined2)local_38;
        local_f8 = local_f8 + 1;
        if ((DAT_00016178 & 0x10) != 0) {
          uVar7 = FUN_00012608();
          uVar5 = FUN_000010a8((int)DAT_00016882);
          FUN_00014e24("IP SEND: %u src %d.%d.%d.%d dst %d.%d.%d.%d len %d protocol %d\n",uVar7,
                       DAT_0001688c,DAT_0001688d,DAT_0001688e,DAT_0001688f,DAT_00016890,DAT_00016891
                       ,DAT_00016892,DAT_00016893,uVar5,DAT_00016889);
        }
        sVar3 = FUN_0000223c(&local_f8,local_58,(int)*(short *)(local_5c + 0x14));
        if (sVar3 != 0) {
          return 0xffffffff;
        }
        iVar15 = local_34 >> 0x10;
        if (iVar15 < 0) {
          iVar15 = iVar15 + 7;
        }
        local_48 = local_48 + (short)(iVar15 >> 3);
        if (local_40 == 1) {
          return 0;
        }
      } while( true );
    }
  }
  return 0xffffffff;
}


================================================================