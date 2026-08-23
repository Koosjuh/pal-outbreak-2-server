FUNCTION FUN_00608c80 @ 0x00608c80  size=3820
CALLERS (1): FUN_0060ae40@0x0060ae40
CALLEES (7): FUN_0060ba40@0x0060ba40, FUN_0060b930@0x0060b930, FUN_0060a650@0x0060a650, FUN_0060bc60@0x0060bc60, FUN_00609be0@0x00609be0, FUN_0060bca0@0x0060bca0, FUN_00609c60@0x00609c60
----------------------------------------------------------------

void FUN_00608c80(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  byte bVar1;
  byte bVar2;
  uint uVar3;
  undefined4 uVar4;
  uint uVar5;
  long lVar6;
  undefined8 uVar7;
  undefined1 uVar8;
  int iVar9;
  uint uVar10;
  undefined1 *puVar11;
  int *piVar12;
  int iVar13;
  byte *pbVar14;
  ulong uVar15;
  ulong uVar16;
  uint uVar17;
  uint uVar18;
  uint uVar19;
  uint uStack_30;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  puVar11 = (undefined1 *)param_1;
  uVar18 = *(uint *)(puVar11 + 0x38);
  piVar12 = (int *)param_2;
  pbVar14 = (byte *)*piVar12;
  uVar17 = piVar12[1];
  uVar16 = *(ulong *)(puVar11 + 0x20);
  uVar15 = (ulong)*(int *)(puVar11 + 0x1c);
  if (uVar18 < *(uint *)(puVar11 + 0x34)) {
    uVar19 = (*(uint *)(puVar11 + 0x34) - uVar18) - 1;
  }
  else {
    uVar19 = *(int *)(puVar11 + 0x30) - uVar18;
  }
LAB_00608cec:
  uVar8 = *puVar11;
  do {
    uVar4 = (undefined4)uVar15;
    switch(uVar8) {
    case 0:
      while (iVar13 = (int)uVar15, uVar15 < 3) {
        if (uVar17 == 0) {
          *(ulong *)(puVar11 + 0x20) = uVar16;
          *(int *)(puVar11 + 0x1c) = iVar13;
          piVar12[1] = 0;
          *(long *)(piVar12 + 2) = *(long *)(piVar12 + 2) + (long)((int)pbVar14 - *piVar12);
          *piVar12 = (int)pbVar14;
          *(uint *)(puVar11 + 0x38) = uVar18;
          FUN_0060bca0(param_1,param_2,param_3);
          return;
        }
        param_3 = 0;
        bVar1 = *pbVar14;
        uVar17 = uVar17 - 1;
        pbVar14 = pbVar14 + 1;
        uVar16 = uVar16 | (ulong)bVar1 << uVar15;
        uVar15 = (ulong)(iVar13 + 8);
      }
      uVar5 = ((uint)uVar16 & 7) >> 1;
      *(uint *)(puVar11 + 0x18) = (uint)uVar16 & 1;
      if (uVar5 == 3) {
        *puVar11 = 9;
        piVar12[8] = (int)s_invalid_block_type_0064a150;
        *(ulong *)(puVar11 + 0x20) = uVar16 >> 3;
        *(int *)(puVar11 + 0x1c) = iVar13 + -3;
        piVar12[1] = uVar17;
        *(long *)(piVar12 + 2) = *(long *)(piVar12 + 2) + (long)((int)pbVar14 - *piVar12);
        *piVar12 = (int)pbVar14;
        *(uint *)(puVar11 + 0x38) = uVar18;
        FUN_0060bca0(param_1,param_2,0xfffffffffffffffd);
        return;
      }
      if (uVar5 == 2) {
        *puVar11 = 3;
        uVar16 = uVar16 >> 3;
        uVar15 = (ulong)(iVar13 + -3);
        goto LAB_00608cec;
      }
      if (uVar5 == 1) {
        FUN_0060bc60(&uStack_4,&uStack_8,&uStack_c,&uStack_10,param_2);
        uVar4 = FUN_00609be0(uStack_4,uStack_8,uStack_c,uStack_10,param_2);
        *(undefined4 *)(puVar11 + 4) = uVar4;
        if (*(int *)(puVar11 + 4) == 0) {
          *(ulong *)(puVar11 + 0x20) = uVar16;
          *(int *)(puVar11 + 0x1c) = iVar13;
          piVar12[1] = uVar17;
          *(long *)(piVar12 + 2) = *(long *)(piVar12 + 2) + (long)((int)pbVar14 - *piVar12);
          *piVar12 = (int)pbVar14;
          *(uint *)(puVar11 + 0x38) = uVar18;
          FUN_0060bca0(param_1,param_2,0xfffffffffffffffc);
          return;
        }
        uVar16 = uVar16 >> 3;
        uVar15 = (ulong)(iVar13 + -3);
        *puVar11 = 6;
        goto LAB_00608cec;
      }
      if (uVar5 == 0) {
        *puVar11 = 1;
        uVar15 = (long)(iVar13 + -3) & 7;
        uVar16 = (uVar16 >> 3) >> uVar15;
        uVar15 = (ulong)((iVar13 + -3) - (int)uVar15);
        goto LAB_00608cec;
      }
      uVar8 = *puVar11;
      break;
    case 1:
      goto switchD_00608d0c_caseD_1;
    case 2:
      if (uVar17 == 0) {
        *(ulong *)(puVar11 + 0x20) = uVar16;
        *(undefined4 *)(puVar11 + 0x1c) = uVar4;
        piVar12[1] = 0;
        *(long *)(piVar12 + 2) = *(long *)(piVar12 + 2) + (long)((int)pbVar14 - *piVar12);
        *piVar12 = (int)pbVar14;
        *(uint *)(puVar11 + 0x38) = uVar18;
        FUN_0060bca0(param_1,param_2,param_3);
        return;
      }
      if (uVar19 == 0) {
        if (uVar18 == *(uint *)(puVar11 + 0x30)) {
          uVar5 = *(uint *)(puVar11 + 0x2c);
          uVar3 = *(uint *)(puVar11 + 0x34);
          if (uVar3 != uVar5) {
            uVar18 = uVar5;
            if (uVar5 < uVar3) {
              uVar19 = (uVar3 - uVar5) - 1;
            }
            else {
              uVar19 = *(uint *)(puVar11 + 0x30) - uVar5;
            }
          }
        }
        if (uVar19 == 0) {
          *(uint *)(puVar11 + 0x38) = uVar18;
          uVar7 = FUN_0060bca0(param_1,param_2,param_3);
          uVar18 = *(uint *)(puVar11 + 0x38);
          uVar5 = *(uint *)(puVar11 + 0x34);
          if (uVar18 < uVar5) {
            uVar19 = (uVar5 - uVar18) - 1;
          }
          else {
            uVar19 = *(int *)(puVar11 + 0x30) - uVar18;
          }
          if (uVar18 == *(uint *)(puVar11 + 0x30)) {
            uVar3 = *(uint *)(puVar11 + 0x2c);
            if (uVar5 != uVar3) {
              uVar18 = uVar3;
              if (uVar3 < uVar5) {
                uVar19 = (uVar5 - uVar3) - 1;
              }
              else {
                uVar19 = *(uint *)(puVar11 + 0x30) - uVar3;
              }
            }
          }
          if (uVar19 == 0) {
            *(ulong *)(puVar11 + 0x20) = uVar16;
            *(undefined4 *)(puVar11 + 0x1c) = uVar4;
            piVar12[1] = uVar17;
            *(long *)(piVar12 + 2) = *(long *)(piVar12 + 2) + (long)((int)pbVar14 - *piVar12);
            *piVar12 = (int)pbVar14;
            *(uint *)(puVar11 + 0x38) = uVar18;
            FUN_0060bca0(param_1,param_2,uVar7);
            return;
          }
        }
      }
      param_3 = 0;
      uStack_30 = *(uint *)(puVar11 + 4);
      if (uVar17 < *(uint *)(puVar11 + 4)) {
        uStack_30 = uVar17;
      }
      if (uVar19 < uStack_30) {
        uStack_30 = uVar19;
      }
      func_0x001069a8(uVar18,pbVar14,uStack_30);
      iVar13 = *(int *)(puVar11 + 4);
      pbVar14 = pbVar14 + uStack_30;
      uVar17 = uVar17 - uStack_30;
      uVar18 = uVar18 + uStack_30;
      uVar19 = uVar19 - uStack_30;
      *(uint *)(puVar11 + 4) = iVar13 - uStack_30;
      if (iVar13 - uStack_30 == 0) {
        uVar8 = 7;
        if (*(int *)(puVar11 + 0x18) == 0) {
          uVar8 = 0;
        }
        *puVar11 = uVar8;
      }
      goto LAB_00608cec;
    case 3:
      goto switchD_00608d0c_caseD_3;
    case 4:
      goto switchD_00608d0c_caseD_4;
    case 5:
      goto switchD_00608d0c_caseD_5;
    case 6:
      goto switchD_00608d0c_caseD_6;
    case 7:
      goto switchD_00608d0c_caseD_7;
    case 8:
      goto switchD_00608d0c_caseD_8;
    case 9:
      *(ulong *)(puVar11 + 0x20) = uVar16;
      *(undefined4 *)(puVar11 + 0x1c) = uVar4;
      piVar12[1] = uVar17;
      *(long *)(piVar12 + 2) = *(long *)(piVar12 + 2) + (long)((int)pbVar14 - *piVar12);
      *piVar12 = (int)pbVar14;
      *(uint *)(puVar11 + 0x38) = uVar18;
      FUN_0060bca0(param_1,param_2,0xfffffffffffffffd);
      return;
    default:
      *(ulong *)(puVar11 + 0x20) = uVar16;
      *(undefined4 *)(puVar11 + 0x1c) = uVar4;
      piVar12[1] = uVar17;
      *(long *)(piVar12 + 2) = *(long *)(piVar12 + 2) + (long)((int)pbVar14 - *piVar12);
      *piVar12 = (int)pbVar14;
      *(uint *)(puVar11 + 0x38) = uVar18;
      FUN_0060bca0(param_1,param_2,0xfffffffffffffffe);
      return;
    }
  } while( true );
switchD_00608d0c_caseD_3:
  while( true ) {
    iVar13 = (int)uVar15;
    if (0xd < uVar15) break;
    if (uVar17 == 0) {
      *(ulong *)(puVar11 + 0x20) = uVar16;
      *(int *)(puVar11 + 0x1c) = iVar13;
      piVar12[1] = 0;
      *(long *)(piVar12 + 2) = *(long *)(piVar12 + 2) + (long)((int)pbVar14 - *piVar12);
      *piVar12 = (int)pbVar14;
      *(uint *)(puVar11 + 0x38) = uVar18;
      FUN_0060bca0(param_1,param_2,param_3);
      return;
    }
    param_3 = 0;
    bVar1 = *pbVar14;
    uVar17 = uVar17 - 1;
    pbVar14 = pbVar14 + 1;
    uVar16 = uVar16 | (ulong)bVar1 << uVar15;
    uVar15 = (ulong)(iVar13 + 8);
  }
  uVar19 = (uint)uVar16 & 0x3fff;
  uVar5 = (uint)uVar16 & 0x1f;
  *(uint *)(puVar11 + 4) = uVar19;
  if ((0x1d < uVar5) || (uVar19 = uVar19 >> 5 & 0x1f, 0x1d < uVar19)) {
    *puVar11 = 9;
    piVar12[8] = (int)s_too_many_length_or_distance_symb_0064a190;
    *(ulong *)(puVar11 + 0x20) = uVar16;
    *(int *)(puVar11 + 0x1c) = iVar13;
    piVar12[1] = uVar17;
    *(long *)(piVar12 + 2) = *(long *)(piVar12 + 2) + (long)((int)pbVar14 - *piVar12);
    *piVar12 = (int)pbVar14;
    *(uint *)(puVar11 + 0x38) = uVar18;
    FUN_0060bca0(param_1,param_2,0xfffffffffffffffd);
    return;
  }
  lVar6 = (*(code *)piVar12[10])(piVar12[0xc],uVar5 + 0x102 + uVar19,4);
  *(int *)(puVar11 + 0xc) = (int)lVar6;
  if (lVar6 == 0) {
    *(ulong *)(puVar11 + 0x20) = uVar16;
    *(int *)(puVar11 + 0x1c) = iVar13;
    piVar12[1] = uVar17;
    *(long *)(piVar12 + 2) = *(long *)(piVar12 + 2) + (long)((int)pbVar14 - *piVar12);
    *piVar12 = (int)pbVar14;
    *(uint *)(puVar11 + 0x38) = uVar18;
    FUN_0060bca0(param_1,param_2,0xfffffffffffffffc);
    return;
  }
  *(undefined4 *)(puVar11 + 8) = 0;
  uVar16 = uVar16 >> 0xe;
  uVar15 = (ulong)(iVar13 + -0xe);
  *puVar11 = 4;
switchD_00608d0c_caseD_4:
  while (*(uint *)(puVar11 + 8) < (*(uint *)(puVar11 + 4) >> 10) + 4) {
    while (iVar13 = (int)uVar15, uVar15 < 3) {
      if (uVar17 == 0) {
        *(ulong *)(puVar11 + 0x20) = uVar16;
        *(int *)(puVar11 + 0x1c) = iVar13;
        piVar12[1] = 0;
        *(long *)(piVar12 + 2) = *(long *)(piVar12 + 2) + (long)((int)pbVar14 - *piVar12);
        *piVar12 = (int)pbVar14;
        *(uint *)(puVar11 + 0x38) = uVar18;
        FUN_0060bca0(param_1,param_2,param_3);
        return;
      }
      param_3 = 0;
      bVar1 = *pbVar14;
      uVar17 = uVar17 - 1;
      pbVar14 = pbVar14 + 1;
      uVar16 = uVar16 | (ulong)bVar1 << uVar15;
      uVar15 = (ulong)(iVar13 + 8);
    }
    iVar9 = *(int *)(puVar11 + 8);
    uVar15 = (ulong)(iVar13 + -3);
    *(int *)(puVar11 + 8) = iVar9 + 1;
    *(uint *)(*(int *)(puVar11 + 0xc) + *(int *)(&LAB_00693250 + iVar9 * 4) * 4) = (uint)uVar16 & 7;
    uVar16 = uVar16 >> 3;
  }
  while (*(uint *)(puVar11 + 8) < 0x13) {
    iVar13 = *(int *)(puVar11 + 8);
    *(int *)(puVar11 + 8) = iVar13 + 1;
    *(undefined4 *)(*(int *)(puVar11 + 0xc) + *(int *)(&LAB_00693250 + iVar13 * 4) * 4) = 0;
  }
  *(undefined4 *)(puVar11 + 0x10) = 7;
  lVar6 = FUN_0060b930(*(undefined4 *)(puVar11 + 0xc),puVar11 + 0x10,puVar11 + 0x14,
                       *(undefined4 *)(puVar11 + 0x28),param_2);
  if (lVar6 != 0) {
    if (lVar6 == -3) {
      (*(code *)piVar12[0xb])(piVar12[0xc],*(undefined4 *)(puVar11 + 0xc));
      *puVar11 = 9;
    }
    *(ulong *)(puVar11 + 0x20) = uVar16;
    *(int *)(puVar11 + 0x1c) = (int)uVar15;
    piVar12[1] = uVar17;
    *(long *)(piVar12 + 2) = *(long *)(piVar12 + 2) + (long)((int)pbVar14 - *piVar12);
    *piVar12 = (int)pbVar14;
    *(uint *)(puVar11 + 0x38) = uVar18;
    FUN_0060bca0(param_1,param_2,lVar6);
    return;
  }
  *(undefined4 *)(puVar11 + 8) = 0;
  *puVar11 = 5;
switchD_00608d0c_caseD_5:
  while( true ) {
    uVar19 = *(uint *)(puVar11 + 8);
    uVar5 = (*(uint *)(puVar11 + 4) & 0x1f) + 0x102 + (*(uint *)(puVar11 + 4) >> 5 & 0x1f);
    if (uVar5 <= uVar19) break;
    while (iVar13 = (int)uVar15, uVar15 < (ulong)(long)*(int *)(puVar11 + 0x10)) {
      if (uVar17 == 0) {
        *(ulong *)(puVar11 + 0x20) = uVar16;
        *(int *)(puVar11 + 0x1c) = iVar13;
        piVar12[1] = 0;
        *(long *)(piVar12 + 2) = *(long *)(piVar12 + 2) + (long)((int)pbVar14 - *piVar12);
        *piVar12 = (int)pbVar14;
        *(uint *)(puVar11 + 0x38) = uVar18;
        FUN_0060bca0(param_1,param_2,param_3);
        return;
      }
      param_3 = 0;
      bVar1 = *pbVar14;
      uVar17 = uVar17 - 1;
      pbVar14 = pbVar14 + 1;
      uVar16 = uVar16 | (ulong)bVar1 << uVar15;
      uVar15 = (ulong)(iVar13 + 8);
    }
    iVar9 = *(int *)(puVar11 + 0x14) +
            ((uint)uVar16 & *(uint *)(&DAT_0064b530 + *(int *)(puVar11 + 0x10) * 4)) * 8;
    uVar3 = *(uint *)(iVar9 + 4);
    bVar1 = *(byte *)(iVar9 + 1);
    if (uVar3 < 0x10) {
      iVar9 = *(int *)(puVar11 + 8);
      uVar15 = (ulong)(int)(iVar13 - (uint)bVar1);
      uVar16 = uVar16 >> (ulong)bVar1;
      *(int *)(puVar11 + 8) = iVar9 + 1;
      *(uint *)(*(int *)(puVar11 + 0xc) + iVar9 * 4) = uVar3;
    }
    else {
      uVar10 = uVar3 - 0xe;
      if (uVar3 == 0x12) {
        uVar10 = 7;
      }
      iVar13 = 3;
      if (uVar3 == 0x12) {
        iVar13 = 0xb;
      }
      while (iVar9 = (int)uVar15, uVar15 < (ulong)(long)(int)(bVar1 + uVar10)) {
        if (uVar17 == 0) {
          *(ulong *)(puVar11 + 0x20) = uVar16;
          *(int *)(puVar11 + 0x1c) = iVar9;
          piVar12[1] = 0;
          *(long *)(piVar12 + 2) = *(long *)(piVar12 + 2) + (long)((int)pbVar14 - *piVar12);
          *piVar12 = (int)pbVar14;
          *(uint *)(puVar11 + 0x38) = uVar18;
          FUN_0060bca0(param_1,param_2,param_3);
          return;
        }
        param_3 = 0;
        bVar2 = *pbVar14;
        uVar17 = uVar17 - 1;
        pbVar14 = pbVar14 + 1;
        uVar16 = uVar16 | (ulong)bVar2 << uVar15;
        uVar15 = (ulong)(iVar9 + 8);
      }
      uVar16 = uVar16 >> (ulong)bVar1;
      iVar9 = (iVar9 - (uint)bVar1) - uVar10;
      uVar15 = (ulong)iVar9;
      iVar13 = iVar13 + ((uint)uVar16 & *(uint *)(&DAT_0064b530 + uVar10 * 4));
      uVar16 = uVar16 >> (ulong)uVar10;
      if ((uVar5 < uVar19 + iVar13) || ((uVar3 == 0x10 && (uVar19 == 0)))) {
        (*(code *)piVar12[0xb])(piVar12[0xc],*(undefined4 *)(puVar11 + 0xc));
        *puVar11 = 9;
        piVar12[8] = (int)s_invalid_bit_length_repeat_0064a1c0;
        *(ulong *)(puVar11 + 0x20) = uVar16;
        *(int *)(puVar11 + 0x1c) = iVar9;
        piVar12[1] = uVar17;
        *(long *)(piVar12 + 2) = *(long *)(piVar12 + 2) + (long)((int)pbVar14 - *piVar12);
        *piVar12 = (int)pbVar14;
        *(uint *)(puVar11 + 0x38) = uVar18;
        FUN_0060bca0(param_1,param_2,0xfffffffffffffffd);
        return;
      }
      if (uVar3 == 0x10) {
        uVar4 = *(undefined4 *)(*(int *)(puVar11 + 0xc) + uVar19 * 4 + -4);
      }
      else {
        uVar4 = 0;
      }
      do {
        iVar9 = uVar19 * 4;
        iVar13 = iVar13 + -1;
        uVar19 = uVar19 + 1;
        *(undefined4 *)(*(int *)(puVar11 + 0xc) + iVar9) = uVar4;
      } while (iVar13 != 0);
      *(uint *)(puVar11 + 8) = uVar19;
    }
  }
  *(undefined4 *)(puVar11 + 0x14) = 0;
  uStack_14 = 9;
  uStack_18 = 6;
  lVar6 = FUN_0060ba40((*(uint *)(puVar11 + 4) & 0x1f) + 0x101,
                       (*(uint *)(puVar11 + 4) >> 5 & 0x1f) + 1,*(undefined4 *)(puVar11 + 0xc),
                       &uStack_14,&uStack_18,&uStack_1c,&uStack_20,*(undefined4 *)(puVar11 + 0x28));
  if (lVar6 != 0) {
    if (lVar6 == -3) {
      (*(code *)piVar12[0xb])(piVar12[0xc],*(undefined4 *)(puVar11 + 0xc));
      *puVar11 = 9;
    }
    *(ulong *)(puVar11 + 0x20) = uVar16;
    *(int *)(puVar11 + 0x1c) = (int)uVar15;
    piVar12[1] = uVar17;
    *(long *)(piVar12 + 2) = *(long *)(piVar12 + 2) + (long)((int)pbVar14 - *piVar12);
    *piVar12 = (int)pbVar14;
    *(uint *)(puVar11 + 0x38) = uVar18;
    FUN_0060bca0(param_1,param_2,lVar6);
    return;
  }
  lVar6 = FUN_00609be0(uStack_14,uStack_18,uStack_1c,uStack_20,param_2);
  if (lVar6 == 0) {
    *(ulong *)(puVar11 + 0x20) = uVar16;
    *(int *)(puVar11 + 0x1c) = (int)uVar15;
    piVar12[1] = uVar17;
    *(long *)(piVar12 + 2) = *(long *)(piVar12 + 2) + (long)((int)pbVar14 - *piVar12);
    *piVar12 = (int)pbVar14;
    *(uint *)(puVar11 + 0x38) = uVar18;
    FUN_0060bca0(param_1,param_2,0xfffffffffffffffc);
    return;
  }
  *(int *)(puVar11 + 4) = (int)lVar6;
  (*(code *)piVar12[0xb])(piVar12[0xc],*(undefined4 *)(puVar11 + 0xc));
  *puVar11 = 6;
switchD_00608d0c_caseD_6:
  *(ulong *)(puVar11 + 0x20) = uVar16;
  *(int *)(puVar11 + 0x1c) = (int)uVar15;
  piVar12[1] = uVar17;
  *(long *)(piVar12 + 2) = *(long *)(piVar12 + 2) + (long)((int)pbVar14 - *piVar12);
  *piVar12 = (int)pbVar14;
  *(uint *)(puVar11 + 0x38) = uVar18;
  lVar6 = FUN_00609c60(param_1,param_2,param_3);
  if (lVar6 != 1) {
    FUN_0060bca0(param_1,param_2,lVar6);
    return;
  }
  param_3 = 0;
  FUN_0060a650(*(undefined4 *)(puVar11 + 4),param_2);
  uVar18 = *(uint *)(puVar11 + 0x38);
  uVar17 = piVar12[1];
  uVar16 = *(ulong *)(puVar11 + 0x20);
  uVar15 = (ulong)*(int *)(puVar11 + 0x1c);
  pbVar14 = (byte *)*piVar12;
  if (uVar18 < *(uint *)(puVar11 + 0x34)) {
    uVar19 = (*(uint *)(puVar11 + 0x34) - uVar18) - 1;
  }
  else {
    uVar19 = *(int *)(puVar11 + 0x30) - uVar18;
  }
  if (*(int *)(puVar11 + 0x18) != 0) {
    *puVar11 = 7;
switchD_00608d0c_caseD_7:
    *(uint *)(puVar11 + 0x38) = uVar18;
    uVar7 = FUN_0060bca0(param_1,param_2,param_3);
    uVar18 = *(uint *)(puVar11 + 0x38);
    if (*(uint *)(puVar11 + 0x34) == uVar18) {
      *puVar11 = 8;
switchD_00608d0c_caseD_8:
      *(ulong *)(puVar11 + 0x20) = uVar16;
      *(int *)(puVar11 + 0x1c) = (int)uVar15;
      piVar12[1] = uVar17;
      *(long *)(piVar12 + 2) = *(long *)(piVar12 + 2) + (long)((int)pbVar14 - *piVar12);
      *piVar12 = (int)pbVar14;
      *(uint *)(puVar11 + 0x38) = uVar18;
      FUN_0060bca0(param_1,param_2,1);
    }
    else {
      *(ulong *)(puVar11 + 0x20) = uVar16;
      *(int *)(puVar11 + 0x1c) = (int)uVar15;
      piVar12[1] = uVar17;
      *(long *)(piVar12 + 2) = *(long *)(piVar12 + 2) + (long)((int)pbVar14 - *piVar12);
      *piVar12 = (int)pbVar14;
      *(uint *)(puVar11 + 0x38) = uVar18;
      FUN_0060bca0(param_1,param_2,uVar7);
    }
    return;
  }
  *puVar11 = 0;
  goto LAB_00608cec;
switchD_00608d0c_caseD_1:
  while( true ) {
    iVar13 = (int)uVar15;
    if (0x1f < uVar15) break;
    if (uVar17 == 0) {
      *(ulong *)(puVar11 + 0x20) = uVar16;
      *(int *)(puVar11 + 0x1c) = iVar13;
      piVar12[1] = 0;
      *(long *)(piVar12 + 2) = *(long *)(piVar12 + 2) + (long)((int)pbVar14 - *piVar12);
      *piVar12 = (int)pbVar14;
      *(uint *)(puVar11 + 0x38) = uVar18;
      FUN_0060bca0(param_1,param_2,param_3);
      return;
    }
    param_3 = 0;
    bVar1 = *pbVar14;
    uVar17 = uVar17 - 1;
    pbVar14 = pbVar14 + 1;
    uVar16 = uVar16 | (ulong)bVar1 << uVar15;
    uVar15 = (ulong)(iVar13 + 8);
  }
  if ((~uVar16 >> 0x10 & 0xffff) != (uVar16 & 0xffff)) {
    *puVar11 = 9;
    piVar12[8] = (int)s_invalid_stored_block_lengths_0064a170;
    *(ulong *)(puVar11 + 0x20) = uVar16;
    *(int *)(puVar11 + 0x1c) = iVar13;
    piVar12[1] = uVar17;
    *(long *)(piVar12 + 2) = *(long *)(piVar12 + 2) + (long)((int)pbVar14 - *piVar12);
    *piVar12 = (int)pbVar14;
    *(uint *)(puVar11 + 0x38) = uVar18;
    FUN_0060bca0(param_1,param_2,0xfffffffffffffffd);
    return;
  }
  uVar15 = 0;
  *(uint *)(puVar11 + 4) = (uint)uVar16 & 0xffff;
  uVar16 = 0;
  if (*(int *)(puVar11 + 4) == 0) {
    uVar8 = 7;
    if (*(int *)(puVar11 + 0x18) == 0) {
      uVar8 = 0;
    }
  }
  else {
    uVar8 = 2;
  }
  *puVar11 = uVar8;
  goto LAB_00608cec;
}



================================================================