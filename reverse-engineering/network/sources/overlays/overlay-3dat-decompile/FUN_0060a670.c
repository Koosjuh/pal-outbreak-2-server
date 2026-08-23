FUNCTION FUN_0060a670 @ 0x0060a670  size=1348
CALLERS (1): FUN_00609c60@0x00609c60
CALLEES (0): 
----------------------------------------------------------------

undefined4 FUN_0060a670(int param_1,int param_2,int param_3,int param_4,int param_5,int *param_6)

{
  byte bVar1;
  uint uVar2;
  byte *pbVar3;
  uint uVar4;
  ulong uVar5;
  uint uVar6;
  undefined1 *puVar7;
  undefined1 *puVar8;
  uint uVar9;
  byte *pbVar10;
  uint uVar11;
  int iVar12;
  ulong uVar13;
  undefined1 *puVar14;
  undefined1 *puVar15;
  ulong uVar16;
  ulong uVar17;
  
  puVar8 = *(undefined1 **)(param_5 + 0x38);
  uVar9 = param_6[1];
  uVar17 = *(ulong *)(param_5 + 0x20);
  iVar12 = *(int *)(param_5 + 0x1c);
  pbVar10 = (byte *)*param_6;
  if (puVar8 < *(undefined1 **)(param_5 + 0x34)) {
    puVar7 = *(undefined1 **)(param_5 + 0x34) + (-1 - (int)puVar8);
  }
  else {
    puVar7 = (undefined1 *)(*(int *)(param_5 + 0x30) - (int)puVar8);
  }
  uVar4 = *(uint *)(&DAT_0064b530 + param_2 * 4);
  uVar2 = *(uint *)(&DAT_0064b530 + param_1 * 4);
  do {
    uVar13 = (ulong)iVar12;
LAB_0060a6f8:
    if (0x13 < uVar13) {
      pbVar3 = (byte *)(param_3 + ((uint)uVar17 & uVar2) * 8);
      uVar16 = (ulong)*pbVar3;
      if (uVar16 != 0) {
LAB_0060a740:
        uVar17 = uVar17 >> (ulong)pbVar3[1];
        uVar11 = (int)uVar13 - (uint)pbVar3[1];
        uVar13 = (ulong)(int)uVar11;
        if ((uVar16 & 0x10) == 0) break;
        iVar12 = (int)(uVar16 & 0xf);
        uVar16 = uVar17 >> (uVar16 & 0xf);
        uVar6 = *(int *)(pbVar3 + 4) + ((uint)uVar17 & *(uint *)(&DAT_0064b530 + iVar12 * 4));
        for (iVar12 = uVar11 - iVar12; uVar17 = (ulong)iVar12, uVar17 < 0xf; iVar12 = iVar12 + 8) {
          bVar1 = *pbVar10;
          uVar9 = uVar9 - 1;
          pbVar10 = pbVar10 + 1;
          uVar16 = uVar16 | (ulong)bVar1 << uVar17;
        }
        pbVar3 = (byte *)(param_4 + ((uint)uVar16 & uVar4) * 8);
        bVar1 = *pbVar3;
        while( true ) {
          uVar16 = uVar16 >> (ulong)pbVar3[1];
          uVar11 = (int)uVar17 - (uint)pbVar3[1];
          uVar17 = (ulong)(int)uVar11;
          if ((bVar1 & 0x10) != 0) break;
          if ((bVar1 & 0x40) != 0) {
            param_6[8] = (int)s_invalid_distance_code_0064a220;
            uVar4 = uVar11 >> 3;
            if (param_6[1] - uVar9 <= uVar11 >> 3) {
              uVar4 = param_6[1] - uVar9;
            }
            *(ulong *)(param_5 + 0x20) = uVar16;
            *(uint *)(param_5 + 0x1c) = uVar11 + uVar4 * -8;
            param_6[1] = uVar9 + uVar4;
            *(long *)(param_6 + 2) =
                 *(long *)(param_6 + 2) + (long)(int)(((int)pbVar10 - uVar4) - *param_6);
            *param_6 = (int)pbVar10 - uVar4;
            *(undefined1 **)(param_5 + 0x38) = puVar8;
            return 0xfffffffd;
          }
          pbVar3 = pbVar3 + ((uint)uVar16 & *(uint *)(&DAT_0064b530 + (uint)bVar1 * 4)) * 8 +
                            *(int *)(pbVar3 + 4) * 8;
          bVar1 = *pbVar3;
        }
        uVar5 = (ulong)bVar1 & 0xf;
        for (; uVar17 < uVar5; uVar17 = (ulong)((int)uVar17 + 8)) {
          bVar1 = *pbVar10;
          uVar9 = uVar9 - 1;
          pbVar10 = pbVar10 + 1;
          uVar16 = uVar16 | (ulong)bVar1 << uVar17;
        }
        puVar15 = *(undefined1 **)(param_5 + 0x2c);
        uVar13 = (ulong)((int)uVar17 - (int)uVar5);
        uVar17 = uVar16 >> uVar5;
        puVar14 = puVar8 + -(*(int *)(pbVar3 + 4) +
                            ((uint)uVar16 & *(uint *)(&DAT_0064b530 + (int)uVar5 * 4)));
        puVar7 = puVar7 + -uVar6;
        if (puVar14 < puVar15) {
          do {
            puVar14 = puVar14 + (*(int *)(param_5 + 0x30) - (int)puVar15);
          } while (puVar14 < puVar15);
          uVar11 = *(int *)(param_5 + 0x30) - (int)puVar14;
          if (uVar11 < uVar6) {
            iVar12 = uVar6 - uVar11;
            do {
              uVar11 = uVar11 - 1;
              *puVar8 = *puVar14;
              puVar14 = puVar14 + 1;
              puVar8 = puVar8 + 1;
            } while (uVar11 != 0);
            puVar15 = *(undefined1 **)(param_5 + 0x2c);
            do {
              iVar12 = iVar12 + -1;
              *puVar8 = *puVar15;
              puVar15 = puVar15 + 1;
              puVar8 = puVar8 + 1;
            } while (iVar12 != 0);
          }
          else {
            iVar12 = uVar6 - 2;
            *puVar8 = *puVar14;
            puVar8[1] = puVar14[1];
            puVar14 = puVar14 + 2;
            puVar8 = puVar8 + 2;
            do {
              iVar12 = iVar12 + -1;
              *puVar8 = *puVar14;
              puVar14 = puVar14 + 1;
              puVar8 = puVar8 + 1;
            } while (iVar12 != 0);
          }
        }
        else {
          iVar12 = uVar6 - 2;
          *puVar8 = *puVar14;
          puVar8[1] = puVar14[1];
          puVar14 = puVar14 + 2;
          puVar8 = puVar8 + 2;
          do {
            iVar12 = iVar12 + -1;
            *puVar8 = *puVar14;
            puVar14 = puVar14 + 1;
            puVar8 = puVar8 + 1;
          } while (iVar12 != 0);
        }
        goto LAB_0060ab30;
      }
      puVar7 = puVar7 + -1;
      uVar17 = uVar17 >> (ulong)pbVar3[1];
      uVar13 = (ulong)(int)((int)uVar13 - (uint)pbVar3[1]);
      *puVar8 = (char)*(undefined4 *)(pbVar3 + 4);
      puVar8 = puVar8 + 1;
      goto LAB_0060ab30;
    }
    bVar1 = *pbVar10;
    uVar9 = uVar9 - 1;
    pbVar10 = pbVar10 + 1;
    uVar17 = uVar17 | (ulong)bVar1 << uVar13;
    iVar12 = (int)uVar13 + 8;
  } while( true );
  if ((uVar16 & 0x40) != 0) {
    if ((uVar16 & 0x20) != 0) {
      uVar4 = uVar11 >> 3;
      if (param_6[1] - uVar9 <= uVar11 >> 3) {
        uVar4 = param_6[1] - uVar9;
      }
      *(ulong *)(param_5 + 0x20) = uVar17;
      *(uint *)(param_5 + 0x1c) = uVar11 + uVar4 * -8;
      param_6[1] = uVar9 + uVar4;
      *(long *)(param_6 + 2) =
           *(long *)(param_6 + 2) + (long)(int)(((int)pbVar10 - uVar4) - *param_6);
      *param_6 = (int)pbVar10 - uVar4;
      *(undefined1 **)(param_5 + 0x38) = puVar8;
      return 1;
    }
    param_6[8] = (int)s_invalid_literal_length_code_0064a240;
    uVar4 = uVar11 >> 3;
    if (param_6[1] - uVar9 <= uVar11 >> 3) {
      uVar4 = param_6[1] - uVar9;
    }
    *(ulong *)(param_5 + 0x20) = uVar17;
    *(uint *)(param_5 + 0x1c) = uVar11 + uVar4 * -8;
    param_6[1] = uVar9 + uVar4;
    *(long *)(param_6 + 2) = *(long *)(param_6 + 2) + (long)(int)(((int)pbVar10 - uVar4) - *param_6)
    ;
    *param_6 = (int)pbVar10 - uVar4;
    *(undefined1 **)(param_5 + 0x38) = puVar8;
    return 0xfffffffd;
  }
  pbVar3 = pbVar3 + ((uint)uVar17 & *(uint *)(&DAT_0064b530 + (int)uVar16 * 4)) * 8 +
                    *(int *)(pbVar3 + 4) * 8;
  uVar16 = (ulong)*pbVar3;
  if (uVar16 == 0) goto code_r0x0060aa3c;
  goto LAB_0060a740;
code_r0x0060aa3c:
  puVar7 = puVar7 + -1;
  uVar17 = uVar17 >> (ulong)pbVar3[1];
  uVar13 = (ulong)(int)(uVar11 - pbVar3[1]);
  *puVar8 = (char)*(undefined4 *)(pbVar3 + 4);
  puVar8 = puVar8 + 1;
LAB_0060ab30:
  if ((puVar7 < (undefined1 *)0x102) || (uVar9 < 10)) {
    uVar4 = (uint)uVar13 >> 3;
    if (param_6[1] - uVar9 <= uVar4) {
      uVar4 = param_6[1] - uVar9;
    }
    *(ulong *)(param_5 + 0x20) = uVar17;
    *(uint *)(param_5 + 0x1c) = (uint)uVar13 + uVar4 * -8;
    param_6[1] = uVar9 + uVar4;
    *(long *)(param_6 + 2) = *(long *)(param_6 + 2) + (long)(int)(((int)pbVar10 - uVar4) - *param_6)
    ;
    *param_6 = (int)pbVar10 - uVar4;
    *(undefined1 **)(param_5 + 0x38) = puVar8;
    return 0;
  }
  goto LAB_0060a6f8;
}



================================================================