FUNCTION FUN_0000e90c @ 0x0000e90c size=1712
CALLERS (1): FUN_0000402c@0x0000402c
CALLEES (9): FUN_0000f710@0x0000f710, FUN_00001c50@0x00001c50, FUN_00010b34@0x00010b34, FUN_00000884@0x00000884, FUN_0000f9f4@0x0000f9f4, FUN_00010b3c@0x00010b3c, FUN_000002f8@0x000002f8, FUN_00000090@0x00000090, FUN_0000e6e0@0x0000e6e0

undefined4 FUN_0000e90c(int *param_1,undefined4 *param_2,short param_3)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  int *piVar4;
  undefined4 uVar5;
  int iVar6;
  byte *pbVar7;
  uint uVar8;
  byte *pbVar9;
  byte *pbVar10;
  undefined *puVar11;
  byte bVar12;
  byte *pbVar13;
  uint uVar14;
  int local_b8 [3];
  ushort local_ac;
  undefined2 uStack_aa;
  short local_a8;
  char local_a3;
  char local_a2;
  char local_a1;
  undefined4 local_a0;
  undefined1 auStack_9c [36];
  int aiStack_78 [2];
  int local_70 [2];
  ushort local_68;
  ushort uStack_66;
  short local_64 [2];
  byte local_5f;
  char local_5e;
  byte local_5d;
  undefined4 local_5c;
  undefined1 auStack_58 [40];
  short local_30 [4];
  
  bVar12 = 0;
  puVar11 = &DAT_00013780;
  pbVar7 = (byte *)(*param_1 + (uint)*(byte *)((int)param_1 + 10) * 0x8c);
  pbVar9 = *(byte **)(pbVar7 + 4);
  local_30[0] = param_3;
  iVar1 = FUN_000002f8(local_70);
  if (local_5c._2_1_ == '\x06') {
    if ((local_64[0] == 0) && (local_5e == '\0')) {
      iVar2 = FUN_0000f9f4(local_b8,param_2);
      iVar1 = iVar1 + iVar2;
      if (((local_a0 & 0xffffff) == 0) && (pbVar13 = pbVar7, local_a2 != '\0')) {
LAB_0000ea64:
        pbVar10 = pbVar9;
        if ((local_70[0] == *(int *)(pbVar10 + 8)) &&
           ((local_70[1] == *(int *)(pbVar10 + 0xc) && (local_b8[0] == *(int *)(pbVar10 + 0x48)))))
        {
          if (pbVar13 != pbVar7) {
            if (pbVar10 == pbVar7) {
              *(byte *)((int)param_1 + 10) = *pbVar13;
            }
            else {
              *(undefined4 *)(pbVar13 + 4) = *(undefined4 *)(pbVar10 + 4);
              *(undefined4 *)(pbVar10 + 4) = *(undefined4 *)(pbVar7 + 4);
              *(byte **)(pbVar7 + 4) = pbVar10;
            }
          }
          if ((((local_5d != pbVar10[0x1b]) ||
               ((local_5c & 0xff0000ff) != (*(uint *)(pbVar10 + 0x1c) & 0xff0000ff))) ||
              (local_5f != pbVar10[0x19])) || (local_5c._1_1_ != pbVar10[0x1d]))
          goto switchD_0000ecc0_caseD_b;
          if (local_a0._3_1_ != pbVar10[99]) goto LAB_0000eed0;
          if ((local_5c._3_1_ != '\0') &&
             (iVar2 = FUN_00010b34(auStack_58,pbVar10 + 0x20,local_5c._3_1_), iVar2 != 0))
          goto LAB_0000eed0;
          if ((local_a0._3_1_ != '\0') &&
             (iVar2 = FUN_00010b34(auStack_9c,pbVar10 + 100,local_a0._3_1_), iVar2 != 0))
          goto LAB_0000eed0;
          if (local_a3 == '\0') {
            if (local_a8 != *(short *)(pbVar10 + 0x58)) goto LAB_0000eed0;
          }
          else {
            bVar12 = 1;
            puVar11 = (undefined *)FUN_0000e6e0(&DAT_00013780,local_a8);
          }
          if ((uint)local_ac - (uint)*(ushort *)(pbVar10 + 0x54) != 0) {
            puVar11 = (undefined *)
                      FUN_0000e6e0(puVar11,(uint)local_ac - (uint)*(ushort *)(pbVar10 + 0x54) &
                                           0xffff);
            bVar12 = bVar12 | 2;
          }
          uVar14 = local_b8[2] - *(int *)(pbVar10 + 0x50);
          if (uVar14 != 0) {
            if (0xffff < uVar14) goto LAB_0000eed0;
            puVar11 = (undefined *)FUN_0000e6e0(puVar11,uVar14 & 0xffff);
            bVar12 = bVar12 | 4;
          }
          uVar8 = local_b8[1] - *(int *)(pbVar10 + 0x4c);
          if (uVar8 != 0) {
            if (0xffff < uVar8) goto LAB_0000eed0;
            puVar11 = (undefined *)FUN_0000e6e0(puVar11,uVar8 & 0xffff);
            bVar12 = bVar12 | 8;
          }
          switch(bVar12) {
          case 0:
            if ((uint)local_68 == (uint)*(ushort *)(pbVar10 + 0x10)) goto switchD_0000ecc0_caseD_b;
            if ((uint)*(ushort *)(pbVar10 + 0x10) == iVar1 * 0x10000 >> 0x10)
            goto switchD_0000ecc0_caseD_1;
            goto LAB_0000eed0;
          default:
            goto switchD_0000ecc0_caseD_1;
          case 8:
            if (uVar8 != (uint)*(ushort *)(pbVar10 + 0x10) - (iVar1 * 0x10000 >> 0x10))
            goto switchD_0000ecc0_caseD_1;
            bVar12 = 0xf;
            break;
          case 0xb:
          case 0xf:
            goto switchD_0000ecc0_caseD_b;
          case 0xc:
            if ((uVar8 != uVar14) ||
               (uVar8 != (uint)*(ushort *)(pbVar10 + 0x10) - (iVar1 * 0x10000 >> 0x10)))
            goto switchD_0000ecc0_caseD_1;
            bVar12 = 0xb;
          }
          puVar11 = &DAT_00013780;
switchD_0000ecc0_caseD_1:
          if ((uint)uStack_66 - (uint)*(ushort *)(pbVar10 + 0x12) != 1) {
            puVar11 = (undefined *)
                      FUN_0000e6e0(puVar11,(uint)uStack_66 - (uint)*(ushort *)(pbVar10 + 0x12) &
                                           0xffff);
            bVar12 = bVar12 | 0x20;
          }
          if (local_a1 != '\0') {
            bVar12 = bVar12 | 0x10;
          }
          pbVar9 = pbVar10 + 8;
          piVar4 = local_70;
          do {
            iVar1 = piVar4[1];
            iVar2 = piVar4[2];
            iVar6 = piVar4[3];
            *(int *)pbVar9 = *piVar4;
            *(int *)(pbVar9 + 4) = iVar1;
            *(int *)(pbVar9 + 8) = iVar2;
            *(int *)(pbVar9 + 0xc) = iVar6;
            piVar4 = piVar4 + 4;
            pbVar9 = pbVar9 + 0x10;
          } while (piVar4 != (int *)local_30);
          pbVar9 = pbVar10 + 0x48;
          piVar4 = local_b8;
          do {
            iVar1 = piVar4[1];
            iVar2 = piVar4[2];
            iVar6 = piVar4[3];
            *(int *)pbVar9 = *piVar4;
            *(int *)(pbVar9 + 4) = iVar1;
            *(int *)(pbVar9 + 8) = iVar2;
            *(int *)(pbVar9 + 0xc) = iVar6;
            piVar4 = piVar4 + 4;
            pbVar9 = pbVar9 + 0x10;
          } while (piVar4 != aiStack_78);
          *(int *)pbVar9 = *piVar4;
          if ((local_30[0] == 0) || (*(byte *)((int)param_1 + 0xb) != *pbVar10)) {
            puVar3 = (undefined4 *)
                     FUN_00000884(*param_2,(int)(puVar11 + -0x1377c) * 0x10000 >> 0x10);
            *param_2 = puVar3;
            pbVar9 = (byte *)*puVar3;
            *pbVar9 = bVar12 | 0x40;
            pbVar9[1] = *pbVar10;
            pbVar9 = pbVar9 + 2;
            *(byte *)((int)param_1 + 0xb) = *pbVar10;
          }
          else {
            piVar4 = (int *)FUN_00000884(*param_2,(int)(puVar11 + -0x1377d) * 0x10000 >> 0x10);
            *param_2 = piVar4;
            pbVar9 = (byte *)*piVar4;
            *pbVar9 = bVar12;
            pbVar9 = pbVar9 + 1;
          }
          uVar5 = FUN_00001c50(pbVar9,uStack_aa);
          FUN_00010b3c(uVar5,&DAT_00013780,(int)(puVar11 + -0x13780) * 0x10000 >> 0x10);
          param_1[7] = param_1[7] + 1;
          return 0x80;
        }
        if (pbVar10 != pbVar7) goto code_r0x0000eaa8;
        param_1[9] = param_1[9] + 1;
        *(byte *)((int)param_1 + 10) = *pbVar13;
switchD_0000ecc0_caseD_b:
LAB_0000eed0:
        pbVar9 = pbVar10 + 8;
        piVar4 = local_70;
        local_5c._0_3_ = CONCAT12(*pbVar10,(undefined2)local_5c);
        do {
          iVar2 = piVar4[1];
          iVar6 = piVar4[2];
          iVar1 = piVar4[3];
          *(int *)pbVar9 = *piVar4;
          *(int *)(pbVar9 + 4) = iVar2;
          *(int *)(pbVar9 + 8) = iVar6;
          *(int *)(pbVar9 + 0xc) = iVar1;
          piVar4 = piVar4 + 4;
          pbVar9 = pbVar9 + 0x10;
        } while (piVar4 != (int *)local_30);
        pbVar9 = pbVar10 + 0x48;
        piVar4 = local_b8;
        do {
          iVar2 = piVar4[1];
          iVar6 = piVar4[2];
          iVar1 = piVar4[3];
          *(int *)pbVar9 = *piVar4;
          *(int *)(pbVar9 + 4) = iVar2;
          *(int *)(pbVar9 + 8) = iVar6;
          *(int *)(pbVar9 + 0xc) = iVar1;
          piVar4 = piVar4 + 4;
          pbVar9 = pbVar9 + 0x10;
        } while (piVar4 != aiStack_78);
        *(int *)pbVar9 = *piVar4;
        *(byte *)((int)param_1 + 0xb) = *pbVar10;
        param_1[6] = param_1[6] + 1;
        uVar5 = FUN_0000f710(local_b8,*param_2,0);
        *param_2 = uVar5;
        uVar5 = FUN_00000090(local_70,uVar5,1);
        *param_2 = uVar5;
        return 0x70;
      }
      param_1[5] = param_1[5] + 1;
      uVar5 = FUN_0000f710(local_b8,*param_2,0);
      *param_2 = uVar5;
      goto LAB_0000ea50;
    }
    param_1[5] = param_1[5] + 1;
  }
  else {
    param_1[4] = param_1[4] + 1;
  }
  uVar5 = *param_2;
LAB_0000ea50:
  uVar5 = FUN_00000090(local_70,uVar5,1);
  *param_2 = uVar5;
  return 0x40;
code_r0x0000eaa8:
  pbVar9 = *(byte **)(pbVar10 + 4);
  param_1[8] = param_1[8] + 1;
  pbVar13 = pbVar10;
  goto LAB_0000ea64;
}


================================================================