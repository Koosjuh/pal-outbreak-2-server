FUNCTION FUN_00609c60 @ 0x00609c60  size=2532
CALLERS (1): FUN_00608c80@0x00608c80
CALLEES (2): FUN_0060a670@0x0060a670, FUN_0060bca0@0x0060bca0
----------------------------------------------------------------

void FUN_00609c60(undefined8 param_1,undefined8 param_2,long param_3)

{
  byte bVar1;
  undefined1 *puVar2;
  uint uVar3;
  undefined1 *puVar4;
  undefined1 *puVar5;
  uint uVar6;
  undefined1 uVar7;
  undefined8 uVar8;
  undefined1 *puVar9;
  int iVar10;
  int *piVar11;
  byte *pbVar12;
  undefined1 *puVar13;
  byte *pbVar14;
  int iVar15;
  ulong uVar16;
  ulong uVar17;
  uint uVar18;
  undefined1 *puVar19;
  
  iVar10 = (int)param_1;
  puVar13 = *(undefined1 **)(iVar10 + 0x38);
  puVar2 = *(undefined1 **)(iVar10 + 4);
  piVar11 = (int *)param_2;
  pbVar14 = (byte *)*piVar11;
  uVar18 = piVar11[1];
  uVar17 = *(ulong *)(iVar10 + 0x20);
  uVar16 = (ulong)*(int *)(iVar10 + 0x1c);
  if (puVar13 < *(undefined1 **)(iVar10 + 0x34)) {
    puVar9 = *(undefined1 **)(iVar10 + 0x34) + (-1 - (int)puVar13);
  }
  else {
    puVar9 = (undefined1 *)(*(int *)(iVar10 + 0x30) - (int)puVar13);
  }
LAB_00609cc8:
  do {
    iVar15 = (int)uVar16;
    switch(*puVar2) {
    case 0:
      if (((undefined1 *)0x101 < puVar9) && (9 < uVar18)) {
        *(ulong *)(iVar10 + 0x20) = uVar17;
        *(int *)(iVar10 + 0x1c) = iVar15;
        piVar11[1] = uVar18;
        *(long *)(piVar11 + 2) = *(long *)(piVar11 + 2) + (long)((int)pbVar14 - *piVar11);
        *piVar11 = (int)pbVar14;
        *(undefined1 **)(iVar10 + 0x38) = puVar13;
        param_3 = FUN_0060a670(puVar2[0x10],puVar2[0x11],*(undefined4 *)(puVar2 + 0x14),
                               *(undefined4 *)(puVar2 + 0x18),param_1,param_2);
        puVar13 = *(undefined1 **)(iVar10 + 0x38);
        uVar18 = piVar11[1];
        uVar17 = *(ulong *)(iVar10 + 0x20);
        uVar16 = (ulong)*(int *)(iVar10 + 0x1c);
        pbVar14 = (byte *)*piVar11;
        if (puVar13 < *(undefined1 **)(iVar10 + 0x34)) {
          puVar9 = *(undefined1 **)(iVar10 + 0x34) + (-1 - (int)puVar13);
        }
        else {
          puVar9 = (undefined1 *)(*(int *)(iVar10 + 0x30) - (int)puVar13);
        }
        if (param_3 != 0) {
          if (param_3 == 1) {
            uVar7 = 7;
          }
          else {
            uVar7 = 9;
          }
          *puVar2 = uVar7;
          break;
        }
      }
      *(uint *)(puVar2 + 0xc) = (uint)(byte)puVar2[0x10];
      *(undefined4 *)(puVar2 + 8) = *(undefined4 *)(puVar2 + 0x14);
      *puVar2 = 1;
    case 1:
      while (iVar15 = (int)uVar16, uVar16 < (ulong)(long)*(int *)(puVar2 + 0xc)) {
        if (uVar18 == 0) {
          *(ulong *)(iVar10 + 0x20) = uVar17;
          *(int *)(iVar10 + 0x1c) = iVar15;
          piVar11[1] = 0;
          *(long *)(piVar11 + 2) = *(long *)(piVar11 + 2) + (long)((int)pbVar14 - *piVar11);
          *piVar11 = (int)pbVar14;
          *(undefined1 **)(iVar10 + 0x38) = puVar13;
          FUN_0060bca0(param_1,param_2,param_3);
          return;
        }
        param_3 = 0;
        bVar1 = *pbVar14;
        uVar18 = uVar18 - 1;
        pbVar14 = pbVar14 + 1;
        uVar17 = uVar17 | (ulong)bVar1 << uVar16;
        uVar16 = (ulong)(iVar15 + 8);
      }
      pbVar12 = (byte *)(*(int *)(puVar2 + 8) +
                        ((uint)uVar17 & *(uint *)(&DAT_0064b530 + *(int *)(puVar2 + 0xc) * 4)) * 8);
      bVar1 = *pbVar12;
      uVar17 = uVar17 >> (ulong)pbVar12[1];
      iVar15 = iVar15 - (uint)pbVar12[1];
      uVar16 = (ulong)iVar15;
      if (bVar1 == 0) {
        *(undefined4 *)(puVar2 + 8) = *(undefined4 *)(pbVar12 + 4);
        *puVar2 = 6;
      }
      else if ((bVar1 & 0x10) == 0) {
        if ((bVar1 & 0x40) == 0) {
          *(uint *)(puVar2 + 0xc) = (uint)bVar1;
          *(byte **)(puVar2 + 8) = pbVar12 + *(int *)(pbVar12 + 4) * 8;
        }
        else {
          if ((bVar1 & 0x20) == 0) {
            *puVar2 = 9;
            piVar11[8] = (int)s_invalid_literal_length_code_0064a1e0;
            *(ulong *)(iVar10 + 0x20) = uVar17;
            *(int *)(iVar10 + 0x1c) = iVar15;
            piVar11[1] = uVar18;
            *(long *)(piVar11 + 2) = *(long *)(piVar11 + 2) + (long)((int)pbVar14 - *piVar11);
            *piVar11 = (int)pbVar14;
            *(undefined1 **)(iVar10 + 0x38) = puVar13;
            FUN_0060bca0(param_1,param_2,0xfffffffffffffffd);
            return;
          }
          *puVar2 = 7;
        }
      }
      else {
        *(uint *)(puVar2 + 8) = bVar1 & 0xf;
        *(undefined4 *)(puVar2 + 4) = *(undefined4 *)(pbVar12 + 4);
        *puVar2 = 2;
      }
      break;
    case 2:
      uVar3 = *(uint *)(puVar2 + 8);
      while (iVar15 = (int)uVar16, uVar16 < (ulong)(long)(int)uVar3) {
        if (uVar18 == 0) {
          *(ulong *)(iVar10 + 0x20) = uVar17;
          *(int *)(iVar10 + 0x1c) = iVar15;
          piVar11[1] = 0;
          *(long *)(piVar11 + 2) = *(long *)(piVar11 + 2) + (long)((int)pbVar14 - *piVar11);
          *piVar11 = (int)pbVar14;
          *(undefined1 **)(iVar10 + 0x38) = puVar13;
          FUN_0060bca0(param_1,param_2,param_3);
          return;
        }
        param_3 = 0;
        bVar1 = *pbVar14;
        uVar18 = uVar18 - 1;
        pbVar14 = pbVar14 + 1;
        uVar17 = uVar17 | (ulong)bVar1 << uVar16;
        uVar16 = (ulong)(iVar15 + 8);
      }
      uVar16 = (ulong)(int)(iVar15 - uVar3);
      *(uint *)(puVar2 + 4) =
           *(int *)(puVar2 + 4) + ((uint)uVar17 & *(uint *)(&DAT_0064b530 + uVar3 * 4));
      uVar17 = uVar17 >> (ulong)uVar3;
      *(uint *)(puVar2 + 0xc) = (uint)(byte)puVar2[0x11];
      *(undefined4 *)(puVar2 + 8) = *(undefined4 *)(puVar2 + 0x18);
      *puVar2 = 3;
    case 3:
      while (iVar15 = (int)uVar16, uVar16 < (ulong)(long)*(int *)(puVar2 + 0xc)) {
        if (uVar18 == 0) {
          *(ulong *)(iVar10 + 0x20) = uVar17;
          *(int *)(iVar10 + 0x1c) = iVar15;
          piVar11[1] = 0;
          *(long *)(piVar11 + 2) = *(long *)(piVar11 + 2) + (long)((int)pbVar14 - *piVar11);
          *piVar11 = (int)pbVar14;
          *(undefined1 **)(iVar10 + 0x38) = puVar13;
          FUN_0060bca0(param_1,param_2,param_3);
          return;
        }
        param_3 = 0;
        bVar1 = *pbVar14;
        uVar18 = uVar18 - 1;
        pbVar14 = pbVar14 + 1;
        uVar17 = uVar17 | (ulong)bVar1 << uVar16;
        uVar16 = (ulong)(iVar15 + 8);
      }
      pbVar12 = (byte *)(*(int *)(puVar2 + 8) +
                        ((uint)uVar17 & *(uint *)(&DAT_0064b530 + *(int *)(puVar2 + 0xc) * 4)) * 8);
      bVar1 = *pbVar12;
      uVar17 = uVar17 >> (ulong)pbVar12[1];
      iVar15 = iVar15 - (uint)pbVar12[1];
      uVar16 = (ulong)iVar15;
      if ((bVar1 & 0x10) == 0) {
        if ((bVar1 & 0x40) != 0) {
          *puVar2 = 9;
          piVar11[8] = (int)s_invalid_distance_code_0064a200;
          *(ulong *)(iVar10 + 0x20) = uVar17;
          *(int *)(iVar10 + 0x1c) = iVar15;
          piVar11[1] = uVar18;
          *(long *)(piVar11 + 2) = *(long *)(piVar11 + 2) + (long)((int)pbVar14 - *piVar11);
          *piVar11 = (int)pbVar14;
          *(undefined1 **)(iVar10 + 0x38) = puVar13;
          FUN_0060bca0(param_1,param_2,0xfffffffffffffffd);
          return;
        }
        *(uint *)(puVar2 + 0xc) = (uint)bVar1;
        *(byte **)(puVar2 + 8) = pbVar12 + *(int *)(pbVar12 + 4) * 8;
      }
      else {
        *(uint *)(puVar2 + 8) = bVar1 & 0xf;
        *(undefined4 *)(puVar2 + 0xc) = *(undefined4 *)(pbVar12 + 4);
        *puVar2 = 4;
      }
      break;
    case 4:
      uVar3 = *(uint *)(puVar2 + 8);
      while (iVar15 = (int)uVar16, uVar16 < (ulong)(long)(int)uVar3) {
        if (uVar18 == 0) {
          *(ulong *)(iVar10 + 0x20) = uVar17;
          *(int *)(iVar10 + 0x1c) = iVar15;
          piVar11[1] = 0;
          *(long *)(piVar11 + 2) = *(long *)(piVar11 + 2) + (long)((int)pbVar14 - *piVar11);
          *piVar11 = (int)pbVar14;
          *(undefined1 **)(iVar10 + 0x38) = puVar13;
          FUN_0060bca0(param_1,param_2,param_3);
          return;
        }
        param_3 = 0;
        bVar1 = *pbVar14;
        uVar18 = uVar18 - 1;
        pbVar14 = pbVar14 + 1;
        uVar17 = uVar17 | (ulong)bVar1 << uVar16;
        uVar16 = (ulong)(iVar15 + 8);
      }
      uVar16 = (ulong)(int)(iVar15 - uVar3);
      uVar6 = (uint)uVar17;
      uVar17 = uVar17 >> (ulong)uVar3;
      *(uint *)(puVar2 + 0xc) =
           *(int *)(puVar2 + 0xc) + (uVar6 & *(uint *)(&DAT_0064b530 + uVar3 * 4));
      *puVar2 = 5;
    case 5:
      for (puVar19 = puVar13 + -*(int *)(puVar2 + 0xc); puVar19 < *(undefined1 **)(iVar10 + 0x2c);
          puVar19 = puVar19 + (*(int *)(iVar10 + 0x30) - (int)*(undefined1 **)(iVar10 + 0x2c))) {
      }
      iVar15 = *(int *)(puVar2 + 4);
      while (iVar15 != 0) {
        if (puVar9 == (undefined1 *)0x0) {
          if (puVar13 == *(undefined1 **)(iVar10 + 0x30)) {
            puVar5 = *(undefined1 **)(iVar10 + 0x2c);
            puVar4 = *(undefined1 **)(iVar10 + 0x34);
            if (puVar4 != puVar5) {
              puVar13 = puVar5;
              if (puVar5 < puVar4) {
                puVar9 = puVar4 + (-1 - (int)puVar5);
              }
              else {
                puVar9 = *(undefined1 **)(iVar10 + 0x30) + -(int)puVar5;
              }
            }
          }
          if (puVar9 == (undefined1 *)0x0) {
            *(undefined1 **)(iVar10 + 0x38) = puVar13;
            uVar8 = FUN_0060bca0(param_1,param_2,param_3);
            puVar13 = *(undefined1 **)(iVar10 + 0x38);
            puVar5 = *(undefined1 **)(iVar10 + 0x34);
            if (puVar13 < puVar5) {
              puVar9 = puVar5 + (-1 - (int)puVar13);
            }
            else {
              puVar9 = (undefined1 *)(*(int *)(iVar10 + 0x30) - (int)puVar13);
            }
            if (puVar13 == *(undefined1 **)(iVar10 + 0x30)) {
              puVar4 = *(undefined1 **)(iVar10 + 0x2c);
              if (puVar5 != puVar4) {
                puVar13 = puVar4;
                if (puVar4 < puVar5) {
                  puVar9 = puVar5 + (-1 - (int)puVar4);
                }
                else {
                  puVar9 = *(undefined1 **)(iVar10 + 0x30) + -(int)puVar4;
                }
              }
            }
            if (puVar9 == (undefined1 *)0x0) {
              *(ulong *)(iVar10 + 0x20) = uVar17;
              *(int *)(iVar10 + 0x1c) = (int)uVar16;
              piVar11[1] = uVar18;
              *(long *)(piVar11 + 2) = *(long *)(piVar11 + 2) + (long)((int)pbVar14 - *piVar11);
              *piVar11 = (int)pbVar14;
              *(undefined1 **)(iVar10 + 0x38) = puVar13;
              FUN_0060bca0(param_1,param_2,uVar8);
              return;
            }
          }
        }
        param_3 = 0;
        puVar9 = puVar9 + -1;
        *puVar13 = *puVar19;
        puVar19 = puVar19 + 1;
        puVar13 = puVar13 + 1;
        if (puVar19 == *(undefined1 **)(iVar10 + 0x30)) {
          puVar19 = *(undefined1 **)(iVar10 + 0x2c);
        }
        *(int *)(puVar2 + 4) = *(int *)(puVar2 + 4) + -1;
        iVar15 = *(int *)(puVar2 + 4);
      }
      *puVar2 = 0;
      break;
    case 6:
      goto switchD_00609ce8_caseD_6;
    case 7:
      if (7 < uVar16) {
        uVar16 = (ulong)(iVar15 + -8);
        uVar18 = uVar18 + 1;
        pbVar14 = pbVar14 + -1;
      }
      *(undefined1 **)(iVar10 + 0x38) = puVar13;
      uVar8 = FUN_0060bca0(param_1,param_2,param_3);
      puVar13 = *(undefined1 **)(iVar10 + 0x38);
      if (*(undefined1 **)(iVar10 + 0x34) == puVar13) {
        *puVar2 = 8;
switchD_00609ce8_caseD_8:
        *(ulong *)(iVar10 + 0x20) = uVar17;
        *(int *)(iVar10 + 0x1c) = (int)uVar16;
        piVar11[1] = uVar18;
        *(long *)(piVar11 + 2) = *(long *)(piVar11 + 2) + (long)((int)pbVar14 - *piVar11);
        *piVar11 = (int)pbVar14;
        *(undefined1 **)(iVar10 + 0x38) = puVar13;
        FUN_0060bca0(param_1,param_2,1);
      }
      else {
        *(ulong *)(iVar10 + 0x20) = uVar17;
        *(int *)(iVar10 + 0x1c) = (int)uVar16;
        piVar11[1] = uVar18;
        *(long *)(piVar11 + 2) = *(long *)(piVar11 + 2) + (long)((int)pbVar14 - *piVar11);
        *piVar11 = (int)pbVar14;
        *(undefined1 **)(iVar10 + 0x38) = puVar13;
        FUN_0060bca0(param_1,param_2,uVar8);
      }
      return;
    case 8:
      goto switchD_00609ce8_caseD_8;
    case 9:
      *(ulong *)(iVar10 + 0x20) = uVar17;
      *(int *)(iVar10 + 0x1c) = iVar15;
      piVar11[1] = uVar18;
      *(long *)(piVar11 + 2) = *(long *)(piVar11 + 2) + (long)((int)pbVar14 - *piVar11);
      *piVar11 = (int)pbVar14;
      *(undefined1 **)(iVar10 + 0x38) = puVar13;
      FUN_0060bca0(param_1,param_2,0xfffffffffffffffd);
      return;
    default:
      *(ulong *)(iVar10 + 0x20) = uVar17;
      *(int *)(iVar10 + 0x1c) = iVar15;
      piVar11[1] = uVar18;
      *(long *)(piVar11 + 2) = *(long *)(piVar11 + 2) + (long)((int)pbVar14 - *piVar11);
      *piVar11 = (int)pbVar14;
      *(undefined1 **)(iVar10 + 0x38) = puVar13;
      FUN_0060bca0(param_1,param_2,0xfffffffffffffffe);
      return;
    }
  } while( true );
switchD_00609ce8_caseD_6:
  if (puVar9 == (undefined1 *)0x0) {
    if (puVar13 == *(undefined1 **)(iVar10 + 0x30)) {
      puVar19 = *(undefined1 **)(iVar10 + 0x2c);
      puVar5 = *(undefined1 **)(iVar10 + 0x34);
      if (puVar5 != puVar19) {
        puVar13 = puVar19;
        if (puVar19 < puVar5) {
          puVar9 = puVar5 + (-1 - (int)puVar19);
        }
        else {
          puVar9 = *(undefined1 **)(iVar10 + 0x30) + -(int)puVar19;
        }
      }
    }
    if (puVar9 == (undefined1 *)0x0) {
      *(undefined1 **)(iVar10 + 0x38) = puVar13;
      uVar8 = FUN_0060bca0(param_1,param_2,param_3);
      puVar13 = *(undefined1 **)(iVar10 + 0x38);
      puVar19 = *(undefined1 **)(iVar10 + 0x34);
      if (puVar13 < puVar19) {
        puVar9 = puVar19 + (-1 - (int)puVar13);
      }
      else {
        puVar9 = (undefined1 *)(*(int *)(iVar10 + 0x30) - (int)puVar13);
      }
      if (puVar13 == *(undefined1 **)(iVar10 + 0x30)) {
        puVar5 = *(undefined1 **)(iVar10 + 0x2c);
        if (puVar19 != puVar5) {
          puVar13 = puVar5;
          if (puVar5 < puVar19) {
            puVar9 = puVar19 + (-1 - (int)puVar5);
          }
          else {
            puVar9 = *(undefined1 **)(iVar10 + 0x30) + -(int)puVar5;
          }
        }
      }
      if (puVar9 == (undefined1 *)0x0) {
        *(ulong *)(iVar10 + 0x20) = uVar17;
        *(int *)(iVar10 + 0x1c) = iVar15;
        piVar11[1] = uVar18;
        *(long *)(piVar11 + 2) = *(long *)(piVar11 + 2) + (long)((int)pbVar14 - *piVar11);
        *piVar11 = (int)pbVar14;
        *(undefined1 **)(iVar10 + 0x38) = puVar13;
        FUN_0060bca0(param_1,param_2,uVar8);
        return;
      }
    }
  }
  param_3 = 0;
  puVar9 = puVar9 + -1;
  *puVar13 = (char)*(undefined4 *)(puVar2 + 8);
  *puVar2 = 0;
  puVar13 = puVar13 + 1;
  goto LAB_00609cc8;
}



================================================================