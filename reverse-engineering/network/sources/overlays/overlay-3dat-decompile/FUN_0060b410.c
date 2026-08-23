FUNCTION FUN_0060b410 @ 0x0060b410  size=1300
CALLERS (2): FUN_0060ba40@0x0060ba40, FUN_0060b930@0x0060b930
CALLEES (0): 
----------------------------------------------------------------

undefined4
FUN_0060b410(int *param_1,uint param_2,uint param_3,int param_4,int param_5,uint *param_6,
            uint *param_7,int param_8,int *param_9,uint *param_10)

{
  undefined3 uVar1;
  uint uVar2;
  uint uVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  int *piVar8;
  uint uVar9;
  uint uVar10;
  uint *puVar11;
  uint uVar12;
  uint uVar13;
  int iVar14;
  undefined1 uVar15;
  int iVar16;
  uint uVar17;
  undefined4 *puVar18;
  uint uVar19;
  uint *puVar20;
  int iVar21;
  uint auStack_d0 [32];
  uint auStack_50 [18];
  undefined4 uStack_8;
  uint uStack_4;
  
  auStack_50[0] = 0;
  auStack_50[1] = 0;
  auStack_50[2] = 0;
  auStack_50[3] = 0;
  auStack_50[4] = 0;
  auStack_50[5] = 0;
  auStack_50[6] = 0;
  auStack_50[7] = 0;
  auStack_50[8] = 0;
  auStack_50[9] = 0;
  auStack_50[10] = 0;
  auStack_50[0xb] = 0;
  auStack_50[0xc] = 0;
  auStack_50[0xd] = 0;
  auStack_50[0xe] = 0;
  auStack_50[0xf] = 0;
  piVar8 = param_1;
  uVar9 = param_2;
  do {
    iVar7 = *piVar8;
    uVar9 = uVar9 - 1;
    piVar8 = piVar8 + 1;
    auStack_50[iVar7] = auStack_50[iVar7] + 1;
  } while (uVar9 != 0);
  if (auStack_50[0] == param_2) {
    *param_6 = 0;
    uVar4 = 0;
    *param_7 = 0;
  }
  else {
    for (uVar9 = 1; (uVar9 < 0x10 && (auStack_50[uVar9] == 0)); uVar9 = uVar9 + 1) {
    }
    uVar10 = *param_7;
    if (*param_7 < uVar9) {
      uVar10 = uVar9;
    }
    for (uVar2 = 0xf; (uVar2 != 0 && (auStack_50[uVar2] == 0)); uVar2 = uVar2 - 1) {
    }
    if (uVar2 < uVar10) {
      uVar10 = uVar2;
    }
    *param_7 = uVar10;
    iVar7 = 1 << (uVar9 & 0x1f);
    for (uVar3 = uVar9; uVar3 < uVar2; uVar3 = uVar3 + 1) {
      if ((int)(iVar7 - auStack_50[uVar3]) < 0) {
        return 0xfffffffd;
      }
      iVar7 = (iVar7 - auStack_50[uVar3]) * 2;
    }
    uVar3 = auStack_50[uVar2];
    iVar7 = iVar7 - uVar3;
    if (iVar7 < 0) {
      uVar4 = 0xfffffffd;
    }
    else {
      uVar5 = 0;
      auStack_50[uVar2] = uVar3 + iVar7;
      puVar11 = auStack_d0 + 2;
      puVar20 = auStack_50;
      auStack_d0[1] = 0;
      uVar3 = uVar2;
      while( true ) {
        puVar20 = puVar20 + 1;
        uVar3 = uVar3 - 1;
        if (uVar3 == 0) break;
        uVar5 = uVar5 + *puVar20;
        *puVar11 = uVar5;
        puVar11 = puVar11 + 1;
      }
      uVar3 = 0;
      do {
        iVar21 = *param_1;
        if (iVar21 != 0) {
          uVar5 = auStack_d0[iVar21];
          auStack_d0[iVar21] = uVar5 + 1;
          param_10[uVar5] = uVar3;
        }
        uVar3 = uVar3 + 1;
        param_1 = param_1 + 1;
      } while (uVar3 < param_2);
      uVar6 = 0;
      iVar21 = -1;
      uVar3 = -uVar10;
      uVar13 = 0;
      uVar5 = 0;
      auStack_d0[0] = 0;
      puVar20 = param_10 + auStack_d0[uVar2];
      auStack_d0[0x10] = 0;
      for (; (int)uVar9 <= (int)uVar2; uVar9 = uVar9 + 1) {
        uVar17 = auStack_50[uVar9];
        while (uVar12 = uVar17 - 1, uVar17 != 0) {
          while ((int)(uVar3 + uVar10) < (int)uVar9) {
            uVar3 = uVar3 + uVar10;
            iVar16 = iVar21 + 1;
            uVar5 = uVar2 - uVar3;
            if (uVar10 < uVar2 - uVar3) {
              uVar5 = uVar10;
            }
            uVar19 = uVar9 - uVar3;
            uVar13 = 1 << (uVar19 & 0x1f);
            if ((uVar17 < uVar13) &&
               (iVar14 = uVar13 - uVar17, puVar11 = auStack_50 + uVar9, uVar19 < uVar5)) {
              while (uVar19 = uVar19 + 1, uVar19 < uVar5) {
                uVar13 = puVar11[1];
                if ((uint)(iVar14 * 2) <= uVar13) break;
                iVar14 = iVar14 * 2 - uVar13;
                puVar11 = puVar11 + 1;
              }
            }
            uVar5 = 1 << (uVar19 & 0x1f);
            if (0x5a0 < *param_9 + uVar5) {
              return 0xfffffffd;
            }
            uVar13 = param_8 + *param_9 * 8;
            auStack_d0[iVar21 + 0x11] = uVar13;
            *param_9 = *param_9 + uVar5;
            if (iVar16 == 0) {
              *param_6 = uVar13;
              iVar21 = iVar16;
            }
            else {
              auStack_d0[iVar16] = uVar6;
              uStack_8._0_2_ = CONCAT11((char)uVar10,(char)uVar19);
              uVar19 = uVar6 >> (uVar3 - uVar10 & 0x1f);
              iVar14 = uVar13 - auStack_d0[iVar21 + 0x10];
              if (iVar14 < 0) {
                iVar14 = iVar14 + 7;
              }
              uStack_4 = (iVar14 >> 3) - uVar19;
              puVar18 = (undefined4 *)(auStack_d0[iVar21 + 0x10] + uVar19 * 8);
              *puVar18 = uStack_8;
              puVar18[1] = uStack_4;
              iVar21 = iVar16;
            }
          }
          uVar1 = CONCAT21(uStack_8._2_2_,(char)(uVar9 - uVar3));
          if (param_10 < puVar20) {
            uStack_4 = *param_10;
            if (uStack_4 < param_3) {
              uVar15 = 0x60;
              if (uStack_4 < 0x100) {
                uVar15 = 0;
              }
              uStack_8 = CONCAT31(uVar1,uVar15);
              param_10 = param_10 + 1;
            }
            else {
              param_10 = param_10 + 1;
              iVar16 = (uStack_4 - param_3) * 4;
              uStack_8 = CONCAT31(uVar1,(char)*(undefined4 *)(param_5 + iVar16) + 'P');
              uStack_4 = *(uint *)(param_4 + iVar16);
            }
          }
          else {
            uStack_8 = CONCAT31(uVar1,0xc0);
          }
          for (uVar17 = uVar6 >> (uVar3 & 0x1f); uVar19 = 1 << (uVar9 - 1 & 0x1f), uVar17 < uVar5;
              uVar17 = uVar17 + (1 << (uVar9 - uVar3 & 0x1f))) {
            puVar18 = (undefined4 *)(uVar13 + uVar17 * 8);
            *puVar18 = uStack_8;
            puVar18[1] = uStack_4;
          }
          while ((uVar6 & uVar19) != 0) {
            uVar6 = uVar6 ^ uVar19;
            uVar19 = uVar19 >> 1;
          }
          uVar6 = uVar6 ^ uVar19;
          for (; uVar17 = uVar12, (uVar6 & (1 << (uVar3 & 0x1f)) - 1U) != auStack_d0[iVar21];
              iVar21 = iVar21 + -1) {
            uVar3 = uVar3 - uVar10;
          }
        }
      }
      uVar4 = 0;
      if ((iVar7 != 0) && (uVar4 = 0xfffffffb, uVar2 == 1)) {
        uVar4 = 0;
      }
    }
  }
  return uVar4;
}



================================================================