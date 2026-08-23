FUNCTION FUN_00005828 @ 0x00005828 size=1552
CALLERS (1): FUN_000044b4@0x000044b4
CALLEES (19): FUN_00005f68@0x00005f68, FUN_00000fa0@0x00000fa0, FUN_00014e24@0x00014e24, FUN_0000663c@0x0000663c, FUN_0000139c@0x0000139c, FUN_00012608@0x00012608, FUN_00001018@0x00001018, FUN_00011d00@0x00011d00, FUN_00005e94@0x00005e94, FUN_00001ab0@0x00001ab0, FUN_00005f10@0x00005f10, FUN_00005e38@0x00005e38, FUN_000041b0@0x000041b0, FUN_00003840@0x00003840, FUN_00011640@0x00011640, FUN_00007000@0x00007000, FUN_00004254@0x00004254, FUN_000010a8@0x000010a8, FUN_00001dd0@0x00001dd0

undefined4 FUN_00005828(int param_1,undefined4 param_2,uint param_3,short param_4)

{
  byte bVar1;
  bool bVar2;
  short sVar3;
  undefined2 uVar4;
  int iVar5;
  uint uVar6;
  undefined4 uVar7;
  uint uVar8;
  int *piVar9;
  int iVar10;
  int *piVar11;
  short *psVar12;
  byte *pbVar13;
  bool bVar14;
  uint uVar15;
  uint local_40;
  undefined4 local_3c;
  short local_38;
  byte *local_30;
  
  local_38 = param_4;
  iVar5 = FUN_00004254((int)param_4);
  if (iVar5 == 0) {
    return 0xffffffff;
  }
  pbVar13 = (byte *)(param_1 + (param_3 & 0xffff));
  FUN_00011d00(&local_40,pbVar13 + 0x10,4);
  FUN_00011d00(&local_3c,pbVar13 + 0xc,4);
  bVar1 = *pbVar13;
  uVar15 = (bVar1 & 0xf) * 4;
  uVar6 = FUN_000010a8((int)*(short *)(pbVar13 + 2));
  local_30 = pbVar13 + uVar15;
  if ((DAT_00016178 & 0x10) != 0) {
    uVar7 = FUN_00012608();
    FUN_00014e24("IP RECV: %u src %d.%d.%d.%d dst %d.%d.%d.%d len %d protocol %d\n",uVar7,
                 local_3c & 0xff,local_3c._1_1_,local_3c >> 0x10 & 0xff,local_3c >> 0x18,
                 local_40 & 0xff,local_40 >> 8 & 0xff,local_40 >> 0x10 & 0xff,local_40 >> 0x18,
                 uVar6 & 0xffff,pbVar13[9]);
  }
  if (uVar15 < 0x14) {
    return 0xffffffff;
  }
  if (*pbVar13 >> 4 != 4) {
    return 0xffffffff;
  }
  sVar3 = FUN_00005e38(pbVar13,uVar15 >> 1);
  if (sVar3 != 0) {
    return 0xffffffff;
  }
  if ((uVar6 & 0xffff) < uVar15) {
    return 0xffffffff;
  }
  if (((DAT_0001616c != 1) && (sVar3 = FUN_000041b0(local_40), sVar3 == -1)) &&
     (sVar3 = FUN_00005e94(local_40,(int)param_4), sVar3 == 0)) {
    return 0xffffffff;
  }
  iVar5 = (int)local_38;
  sVar3 = FUN_00005f10(local_3c,iVar5);
  if (sVar3 == 1) {
    return 0xffffffff;
  }
  uVar8 = FUN_000010a8((int)*(short *)(pbVar13 + 6));
  if ((uVar8 & 0xbfff) == 0) {
    piVar9 = (int *)FUN_00000fa0();
    if (piVar9 == (int *)0x0) {
      return 0xffffffff;
    }
    *(short *)(piVar9 + 2) = (short)(uVar6 + param_3);
    *piVar9 = 1;
    piVar9[1] = (int)((uVar6 + param_3) * 0x10000) >> 0x10;
    FUN_0000139c(piVar9 + 3,param_1);
    bVar14 = false;
  }
  else {
    uVar4 = FUN_000010a8((int)*(short *)(pbVar13 + 4));
    piVar9 = (int *)FUN_00005f68(param_1,param_3 + uVar15 & 0xffff,
                                 (int)((uVar6 + (bVar1 & 0xf) * -4) * 0x10000) >> 0x10,iVar5,
                                 pbVar13[8],uVar4,local_3c,uVar8 & 0x1fff,(uVar8 & 0x2000) != 0);
    bVar14 = true;
    if (piVar9 == (int *)0x0) {
      return 0;
    }
  }
  param_3 = param_3 + uVar15;
  bVar1 = pbVar13[9];
  if (bVar1 == 6) {
    sVar3 = FUN_00007000(piVar9,param_3 & 0xffff,local_3c,local_40);
    if (sVar3 != 0) {
      if (bVar14) {
        FUN_0000663c(piVar9);
      }
      goto LAB_00005dfc;
    }
LAB_00005c88:
    if (bVar14) {
      FUN_0000663c(piVar9);
    }
LAB_00005ca0:
    FUN_00001018(piVar9);
    return 0;
  }
  if (bVar1 < 7) {
    bVar2 = false;
    if (bVar1 == 1) {
      bVar2 = true;
      sVar3 = FUN_00001ab0(piVar9,param_3 & 0xffff,local_3c);
      if (sVar3 != 0) {
        if (bVar14) {
          FUN_0000663c(piVar9);
        }
        goto LAB_00005dfc;
      }
      if (bVar14) {
        FUN_0000663c(piVar9);
      }
      FUN_00001018(piVar9);
    }
LAB_00005cb0:
    iVar5 = 0;
    if (DAT_0001619d != 0) {
      iVar10 = 0;
      do {
        psVar12 = (short *)((iVar10 >> 0x10) * 0x14 + DAT_000161a8);
        if ((((*psVar12 == 1) &&
             ((*(uint *)(psVar12 + 2) == 0 || (*(uint *)(psVar12 + 2) == local_3c)))) &&
            (*(byte *)(psVar12 + 8) == pbVar13[9])) && (*(int *)(psVar12 + 4) != 0)) {
          bVar2 = true;
          FUN_00011640(piVar9,local_3c);
        }
        iVar5 = iVar5 + 1;
        iVar10 = iVar5 * 0x10000;
      } while (iVar5 * 0x10000 >> 0x10 < (int)(uint)DAT_0001619d);
    }
    if (bVar2) {
      return 0;
    }
    piVar11 = (int *)FUN_00000fa0();
    if (piVar11 == (int *)0x0) {
      return 0xffffffff;
    }
    *piVar11 = 1;
    piVar11[1] = 8;
    *(undefined2 *)(piVar11 + 2) = 8;
    FUN_0000139c(piVar11 + 3,local_30);
    *(short *)(piVar11 + 5) = (short)uVar15;
    *piVar11 = *piVar11 + 1;
    piVar11[1] = uVar15 + piVar11[1];
    FUN_0000139c(piVar11 + 6,pbVar13);
    FUN_00001dd0(3,2,local_3c,piVar11);
  }
  else {
    bVar2 = false;
    if (bVar1 != 0x11) goto LAB_00005cb0;
    sVar3 = FUN_00003840(piVar9,param_3 & 0xffff,local_3c,local_40);
    if (sVar3 == 0) goto LAB_00005c88;
    if (sVar3 != -2) {
      if (bVar14) {
        FUN_0000663c(piVar9);
      }
      goto LAB_00005dfc;
    }
    piVar11 = (int *)FUN_00000fa0();
    if (piVar11 == (int *)0x0) {
      return 0xffffffff;
    }
    *piVar11 = 1;
    piVar11[1] = 8;
    *(undefined2 *)(piVar11 + 2) = 8;
    FUN_0000139c(piVar11 + 3,local_30);
    *(short *)(piVar11 + 5) = (short)uVar15;
    *piVar11 = *piVar11 + 1;
    piVar11[1] = uVar15 + piVar11[1];
    FUN_0000139c(piVar11 + 6,pbVar13);
    sVar3 = FUN_00001dd0(3,3,local_3c,piVar11);
    if (sVar3 != -1) {
      if (bVar14) {
        FUN_0000663c(piVar9);
      }
      FUN_00001018(piVar9);
      piVar9 = piVar11;
      goto LAB_00005ca0;
    }
  }
  if (bVar14) {
    FUN_0000663c(piVar9);
  }
  FUN_00001018(piVar9);
  piVar9 = piVar11;
LAB_00005dfc:
  FUN_00001018(piVar9);
  return 0xffffffff;
}


================================================================