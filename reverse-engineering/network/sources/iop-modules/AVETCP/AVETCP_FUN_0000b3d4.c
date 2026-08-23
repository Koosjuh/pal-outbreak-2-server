FUNCTION FUN_0000b3d4 @ 0x0000b3d4 size=2680
CALLERS (10): FUN_0000c428@0x0000c428, FUN_0000ce88@0x0000ce88, FUN_0000d704@0x0000d704, FUN_00007000@0x00007000, FUN_0000c5dc@0x0000c5dc, FUN_0000d42c@0x0000d42c, FUN_0000a264@0x0000a264, FUN_0000c088@0x0000c088, FUN_0000dbac@0x0000dbac, FUN_0000d9c8@0x0000d9c8
CALLEES (20): FUN_0000139c@0x0000139c, FUN_00001018@0x00001018, FUN_0000a788@0x0000a788, FUN_00001080@0x00001080, FUN_0001168c@0x0001168c, FUN_0000be4c@0x0000be4c, FUN_00004ec4@0x00004ec4, FUN_00004610@0x00004610, FUN_00014e24@0x00014e24, FUN_000010a8@0x000010a8, FUN_00000fa0@0x00000fa0, FUN_0000acf0@0x0000acf0, FUN_0000a7d8@0x0000a7d8, FUN_00012608@0x00012608, FUN_0000f308@0x0000f308, FUN_0000a79c@0x0000a79c, FUN_00011d00@0x00011d00, FUN_0000f228@0x0000f228, FUN_00008dc4@0x00008dc4, FUN_00003b30@0x00003b30

undefined4 FUN_0000b3d4(int param_1)

{
  undefined1 uVar1;
  short sVar2;
  ushort uVar3;
  ushort uVar4;
  undefined2 uVar5;
  undefined2 uVar6;
  undefined4 uVar7;
  uint uVar8;
  int iVar9;
  int *piVar10;
  undefined *puVar11;
  int iVar12;
  byte bVar13;
  uint uVar14;
  uint uVar15;
  undefined4 local_48;
  undefined4 local_44;
  undefined1 local_40;
  undefined1 local_3f;
  undefined2 local_3e;
  undefined2 local_38 [2];
  uint local_34;
  int local_30;
  
  if (*(short *)(param_1 + 0x13a) < 0) {
LAB_0000b450:
    uVar7 = 0xffffffff;
  }
  else {
    local_34 = (uint)(*(int *)(param_1 + 0x108) == *(int *)(param_1 + 0xdc));
    do {
      sVar2 = FUN_00004610();
      DAT_000168d0 = param_1;
      if (sVar2 == -1) goto LAB_0000b450;
      local_30 = 0;
      DAT_000168d0 = 0;
      iVar12 = *(int *)(param_1 + 0xe0) - *(int *)(param_1 + 0xdc);
      if (*(ushort *)(param_1 + 0xf4) < *(ushort *)(param_1 + 0x10c)) {
        uVar4 = *(ushort *)(param_1 + 0xf4);
      }
      else {
        uVar4 = *(ushort *)(param_1 + 0x10c);
      }
      uVar14 = (uint)uVar4;
      if (*(char *)(param_1 + 0x140) != '\0') {
        if (uVar14 == 0) {
          uVar14 = 1;
        }
        else {
          *(undefined2 *)(param_1 + 0x126) = 0;
          *(undefined2 *)(param_1 + 0x122) = 0;
        }
      }
      uVar8 = FUN_0000a79c(param_1);
      uVar15 = uVar14 - iVar12;
      if (uVar8 < uVar14) {
        iVar9 = FUN_0000a79c(param_1);
        uVar15 = iVar9 - iVar12;
      }
      bVar13 = (&DAT_00015750)[*(short *)(param_1 + 0x13a)];
      if (((int)uVar15 < 0) && (uVar15 = 0, uVar14 == 0)) {
        *(undefined2 *)(param_1 + 0x124) = 0;
        *(undefined4 *)(param_1 + 0xe0) = *(undefined4 *)(param_1 + 0xdc);
      }
      if (*(ushort *)(param_1 + 300) < uVar15) {
        local_30 = 1;
        uVar15 = (uint)*(ushort *)(param_1 + 300);
      }
      iVar9 = FUN_0000a79c(param_1);
      if ((int)((*(int *)(param_1 + 0xe0) + uVar15) - (*(int *)(param_1 + 0xdc) + iVar9)) < 0) {
        bVar13 = bVar13 & 0xfe;
      }
      uVar14 = FUN_0000a788(param_1);
      if (((((bVar13 & 1) == 0) ||
           (((*(byte *)(param_1 + 0x13f) & 0x10) != 0 &&
            (*(int *)(param_1 + 0xe0) != *(int *)(param_1 + 0xdc))))) &&
          ((*(byte *)(param_1 + 0x13f) & 1) == 0)) &&
         (((bVar13 & 6) == 0 && (*(int *)(param_1 + 0xe4) - *(int *)(param_1 + 0xdc) < 1)))) {
        if (uVar15 != 0) {
          if (uVar15 == *(ushort *)(param_1 + 300)) goto LAB_0000b714;
          if ((*(uint *)(param_1 + 0xd8) & 1) == 1) {
LAB_0000b60c:
            uVar8 = FUN_0000a79c(param_1);
          }
          else {
            iVar9 = FUN_0000a79c(param_1);
            uVar8 = (uint)DAT_000168d8;
            if (iVar9 < (int)uVar8) goto LAB_0000b60c;
          }
          if (((((local_34 != 0) || ((*(byte *)(param_1 + 0x13f) & 4) != 0)) &&
               ((int)uVar8 <= (int)(uVar15 + iVar12))) ||
              ((*(char *)(param_1 + 0x140) != '\0' || (*(ushort *)(param_1 + 0x11e) >> 1 <= uVar15))
              )) || (*(uint *)(param_1 + 0xe0) < *(uint *)(param_1 + 0x108))) goto LAB_0000b714;
        }
        if (uVar14 == 0) {
LAB_0000b6dc:
          iVar12 = FUN_0000a79c(param_1);
          if (iVar12 == 0) {
            return 0;
          }
          if (*(int *)(param_1 + 0x124) != 0) {
            return 0;
          }
          *(undefined2 *)(param_1 + 0x122) = 0;
          FUN_0000be4c(param_1);
          return 0;
        }
        uVar8 = uVar14 - (*(int *)(param_1 + 0x104) - *(int *)(param_1 + 0xf8));
        if ((int)uVar8 < 0) {
          uVar8 = -uVar8;
        }
        if ((uVar8 < (uint)*(ushort *)(param_1 + 300) << 1) &&
           (iVar9 = FUN_0000a7d8(param_1), (int)(uVar8 << 1) < iVar9)) goto LAB_0000b6dc;
      }
LAB_0000b714:
      if ((((bVar13 & 1) != 0) && ((*(byte *)(param_1 + 0x13f) & 0x10) != 0)) &&
         (*(int *)(param_1 + 0xe0) == *(int *)(param_1 + 0x108))) {
        *(int *)(param_1 + 0xe0) = *(int *)(param_1 + 0xe0) + -1;
      }
      puVar11 = (undefined *)0x0;
      uVar7 = FUN_00001080(*(undefined4 *)(param_1 + 0xe0));
      *(undefined4 *)(param_1 + 0x148) = uVar7;
      uVar7 = FUN_00001080(*(undefined4 *)(param_1 + 0xf8));
      *(undefined4 *)(param_1 + 0x14c) = uVar7;
      if ((bVar13 & 2) != 0) {
        puVar11 = &DAT_000168d4;
        uVar3 = FUN_0000acf0(param_1);
        uVar4 = DAT_000168d8;
        if (uVar3 <= DAT_000168d8) {
          uVar4 = FUN_0000acf0(param_1);
        }
        local_38[0] = FUN_000010a8((int)(short)uVar4);
        FUN_00011d00(&DAT_000168d6,local_38,2);
      }
      *(byte *)(param_1 + 0x151) = bVar13;
      uVar8 = FUN_0000a7d8(param_1);
      if ((uVar14 < uVar8 >> 2) && (uVar14 < *(ushort *)(param_1 + 300))) {
        uVar14 = 0;
      }
      uVar8 = *(int *)(param_1 + 0x104) - *(int *)(param_1 + 0xf8);
      if ((int)uVar14 < (int)uVar8) {
        uVar14 = uVar8;
      }
      if (DAT_000168d8 < uVar14) {
        uVar14 = (uint)DAT_000168d8;
      }
      uVar5 = FUN_000010a8((int)(short)uVar14);
      *(undefined2 *)(param_1 + 0x152) = uVar5;
      if (*(int *)(param_1 + 0xe4) - *(int *)(param_1 + 0xe0) < 1) {
        *(undefined4 *)(param_1 + 0xe4) = *(undefined4 *)(param_1 + 0xdc);
      }
      else {
        bVar13 = bVar13 | 0x20;
        uVar5 = FUN_000010a8((int)(((uint)*(ushort *)(param_1 + 0xe4) -
                                   (uint)*(ushort *)(param_1 + 0xe0)) * 0x10000) >> 0x10);
        *(undefined2 *)(param_1 + 0x156) = uVar5;
      }
      if ((uVar15 != 0) && (iVar9 = FUN_0000a79c(param_1), iVar12 + uVar15 == iVar9)) {
        bVar13 = bVar13 | 8;
      }
      iVar9 = FUN_0000f228(*(undefined4 *)(param_1 + 0x158));
      if (iVar9 == 0) {
        FUN_0001168c((param_1 - DAT_00016180) * -0x69184000 >> 0x10,*(undefined4 *)(param_1 + 0x168)
                     ,3,0xc);
        return 0xffffffff;
      }
      *(undefined2 *)(param_1 + 0x154) = 0;
      *(byte *)(param_1 + 0x151) = bVar13;
      if (puVar11 == (undefined *)0x0) {
        uVar1 = 0x50;
      }
      else {
        uVar1 = 0x60;
      }
      *(undefined1 *)(param_1 + 0x150) = uVar1;
      piVar10 = (int *)FUN_00000fa0();
      if (piVar10 == (int *)0x0) goto LAB_0000b450;
      *piVar10 = 0;
      piVar10[1] = 0;
      iVar12 = FUN_00008dc4(iVar12,uVar15,piVar10,param_1);
      if (iVar12 == -1) {
        *piVar10 = 0;
        piVar10[1] = 0;
      }
      if (puVar11 != (undefined *)0x0) {
        *piVar10 = *piVar10 + 1;
        piVar10[1] = piVar10[1] + 4;
        *(undefined2 *)(piVar10 + (*piVar10 + -1) * 3 + 2) = 4;
        FUN_0000139c(piVar10 + *piVar10 * 3,puVar11);
      }
      *piVar10 = *piVar10 + 1;
      piVar10[1] = piVar10[1] + 0x14;
      *(undefined2 *)(piVar10 + (*piVar10 + -1) * 3 + 2) = 0x14;
      FUN_0000139c(piVar10 + *piVar10 * 3,(short *)(param_1 + 0x144));
      local_48 = FUN_0000f308(iVar9);
      local_44 = *(undefined4 *)(param_1 + 0x158);
      local_40 = 0;
      local_3f = 6;
      local_3e = FUN_000010a8((int)(short)piVar10[1]);
      uVar5 = FUN_00003b30(&local_48,piVar10,1);
      *(char *)(param_1 + 0x154) = (char)((ushort)uVar5 >> 8);
      *(char *)(param_1 + 0x155) = (char)uVar5;
      if ((*(char *)(param_1 + 0x140) == '\0') || (*(short *)(param_1 + 0x126) == 0)) {
        iVar12 = *(int *)(param_1 + 0xe0);
        if ((bVar13 & 2) != 0) {
          *(int *)(param_1 + 0xe0) = iVar12 + 1;
        }
        if ((bVar13 & 1) != 0) {
          *(int *)(param_1 + 0xe0) = *(int *)(param_1 + 0xe0) + 1;
          *(byte *)(param_1 + 0x13f) = *(byte *)(param_1 + 0x13f) | 0x10;
        }
        uVar8 = *(int *)(param_1 + 0xe0) + uVar15;
        *(uint *)(param_1 + 0xe0) = uVar8;
        if ((*(uint *)(param_1 + 0x108) < uVar8) &&
           (*(uint *)(param_1 + 0x108) = uVar8, *(short *)(param_1 + 0x112) == 0)) {
          *(undefined2 *)(param_1 + 0x112) = 1;
          *(int *)(param_1 + 0x114) = iVar12;
        }
        if (((*(short *)(param_1 + 0x124) == 0) &&
            (*(int *)(param_1 + 0xe0) != *(int *)(param_1 + 0xdc))) &&
           (*(undefined2 *)(param_1 + 0x124) = *(undefined2 *)(param_1 + 0x120),
           *(short *)(param_1 + 0x126) != 0)) {
          *(undefined2 *)(param_1 + 0x126) = 0;
          *(undefined2 *)(param_1 + 0x122) = 0;
        }
      }
      else {
        iVar12 = *(int *)(param_1 + 0xe0) + uVar15;
        if (iVar12 != *(int *)(param_1 + 0x108)) {
          *(int *)(param_1 + 0x108) = iVar12;
        }
      }
      if ((DAT_00016178 & 2) != 0) {
        uVar7 = FUN_00012608();
        uVar5 = FUN_000010a8((int)*(short *)(param_1 + 0x144));
        uVar6 = FUN_000010a8((int)*(short *)(param_1 + 0x146));
        FUN_00014e24("TCP SEND: %u SP %d DP %d ",uVar7,uVar5,uVar6);
      }
      if (((bVar13 & 1) != 0) && ((DAT_00016178 & 2) != 0)) {
        FUN_00014e24(&DAT_000157b0);
      }
      if (((bVar13 & 2) != 0) && ((DAT_00016178 & 2) != 0)) {
        FUN_00014e24(&DAT_000157b4);
      }
      if (((bVar13 & 4) != 0) && ((DAT_00016178 & 2) != 0)) {
        FUN_00014e24(&DAT_000157b8);
      }
      if (((bVar13 & 8) != 0) && ((DAT_00016178 & 2) != 0)) {
        FUN_00014e24(&DAT_000157bc);
      }
      if (((bVar13 & 0x10) != 0) && ((DAT_00016178 & 2) != 0)) {
        FUN_00014e24(&DAT_000157c0);
      }
      if ((bVar13 & 0x20) == 0) {
LAB_0000bcb0:
        if ((DAT_00016178 & 2) != 0) {
          uVar7 = FUN_00001080(*(undefined4 *)(param_1 + 0x148));
          FUN_00014e24(" seq %u ",uVar7);
        }
      }
      else if ((DAT_00016178 & 2) != 0) {
        FUN_00014e24(&DAT_000157c4);
        goto LAB_0000bcb0;
      }
      if ((bVar13 & 0x10) == 0) {
LAB_0000bd24:
        if (((DAT_00016178 & 2) != 0) &&
           (FUN_00014e24("win %d len %d ",uVar14,uVar15), (DAT_00016178 & 2) != 0)) {
          FUN_00014e24(&DAT_000157ec);
        }
      }
      else if ((DAT_00016178 & 2) != 0) {
        uVar7 = FUN_00001080(*(undefined4 *)(param_1 + 0x14c));
        FUN_00014e24("ack %u ",uVar7);
        goto LAB_0000bd24;
      }
      sVar2 = FUN_00004ec4(piVar10,*(undefined4 *)(param_1 + 0x158),0,
                           *(undefined1 *)(param_1 + 0x170),*(undefined1 *)(param_1 + 0x16e),
                           *(undefined1 *)(param_1 + 0x16f),*(undefined2 *)(param_1 + 0x15c),
                           *(undefined4 *)(param_1 + 0x160),6,0);
      if (sVar2 != 0) {
        FUN_00001018(piVar10);
        return 0xffffffff;
      }
      FUN_00001018(piVar10);
      if ((uVar14 != 0) &&
         (iVar12 = *(int *)(param_1 + 0xf8) + uVar14, 0 < iVar12 - *(int *)(param_1 + 0x104))) {
        *(int *)(param_1 + 0x104) = iVar12;
      }
      *(undefined2 *)(param_1 + 0x174) = 0;
      *(byte *)(param_1 + 0x13f) = *(byte *)(param_1 + 0x13f) & 0xfc;
      uVar7 = 0;
    } while (local_30 != 0);
  }
  return uVar7;
}


================================================================