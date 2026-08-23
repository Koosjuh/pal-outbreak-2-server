FUNCTION FUN_005f1da0 @ 0x005f1da0  size=1104
CALLERS (1): FUN_005eacd0@0x005eacd0
CALLEES (2): FUN_005f1a80@0x005f1a80, FUN_005f16b0@0x005f16b0
----------------------------------------------------------------

undefined2 FUN_005f1da0(undefined4 *param_1,char param_2)

{
  byte bVar1;
  ushort uVar2;
  ushort uVar3;
  short sVar4;
  undefined2 uVar5;
  short sVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  int iVar13;
  short sVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  undefined4 *puVar18;
  int iVar19;
  byte abStack_200 [2];
  undefined2 auStack_1fe [63];
  undefined1 auStack_180 [2];
  undefined2 auStack_17e [63];
  undefined1 auStack_100 [126];
  undefined2 uStack_82;
  undefined1 auStack_80 [2];
  short asStack_7e [63];
  
  if (*(char *)(iRam007012a0 + 0x186) == param_2) {
    if (*(char *)((int)param_1 + 0x4d) == '\0') {
      func_0x00106b60(auStack_80,0,0x80);
      func_0x00106b60(auStack_100,0,0x80);
      iVar17 = 0;
      puVar18 = param_1;
      do {
        func_0x00106b60(auStack_180,0,0x80);
        func_0x00106b60(abStack_200,0,0x80);
        iVar15 = 0;
        uVar9 = 0;
        uVar12 = 0;
        for (iVar16 = puVar18[3]; iVar16 != 0; iVar16 = *(int *)(iVar16 + 8)) {
          bVar1 = *(byte *)(iVar16 + 0x47);
          if (bVar1 < 2) {
            iVar13 = (uint)*(ushort *)((int)param_1 + 0x32) + (uint)*(ushort *)(param_1 + 0xc) * 2;
            uVar10 = (uint)*(ushort *)(iVar16 + 0x20) + iVar13;
            uVar11 = uVar10 & 0xffff;
            uVar7 = (uint)*(ushort *)(iVar16 + 0x22) + iVar13 & 0xffff;
            if ((uVar7 < uVar11) || ((*(byte *)(iVar16 + 0x46) & 1) != 0)) {
              uVar7 = uVar10 & 0xffff;
            }
            uVar12 = uVar12 + uVar11;
            uVar9 = uVar9 + uVar7;
            auStack_17e[iVar15 * 2] = (short)uVar12;
            auStack_180[iVar15 * 4] = 1;
            auStack_1fe[iVar15 * 2] = (short)uVar9;
            abStack_200[iVar15 * 4] = *(byte *)(iVar16 + 0x46);
          }
          else {
            uVar2 = *(ushort *)(iVar16 + 0x20);
            uVar10 = 0;
            uVar3 = *(ushort *)(iVar16 + 0x22);
            uVar11 = 0;
            if (uVar2 != 0) {
              uVar11 = (int)((uint)uVar2 -
                            (bVar1 - 1) *
                            ((uint)*(ushort *)(iVar16 + 0x32) + (uint)*(ushort *)(iVar16 + 0x30) * 2
                            )) / (int)(uint)bVar1 & 0xffff;
            }
            if (uVar3 != 0) {
              uVar10 = (int)((uint)uVar3 -
                            (bVar1 - 1) *
                            ((uint)*(ushort *)(iVar16 + 0x32) + (uint)*(ushort *)(iVar16 + 0x30) * 2
                            )) / (int)(uint)bVar1 & 0xffff;
            }
            if ((uVar10 < uVar11) || ((*(byte *)(iVar16 + 0x46) & 1) != 0)) {
              uVar10 = uVar11;
              uVar3 = uVar2;
            }
            uVar7 = uVar2 + uVar12;
            uVar8 = uVar3 + uVar9;
            for (iVar13 = 0; iVar13 < (int)(*(byte *)(iVar16 + 0x47) - 1); iVar13 = iVar13 + 1) {
              iVar19 = (uint)*(ushort *)((int)param_1 + 0x32) + (uint)*(ushort *)(param_1 + 0xc) * 2
              ;
              uVar12 = uVar12 + (uVar11 + iVar19 & 0xffff);
              auStack_17e[iVar15 * 2] = (short)uVar12;
              uVar9 = uVar9 + (uVar10 + iVar19 & 0xffff);
              auStack_180[iVar15 * 4] = 8;
              uVar12 = uVar12 & 0xffff;
              auStack_1fe[iVar15 * 2] = (short)uVar9;
              abStack_200[iVar15 * 4] = *(byte *)(iVar16 + 0x46) | 8;
              iVar16 = *(int *)(iVar16 + 8);
              uVar9 = uVar9 & 0xffff;
              if (iVar16 == 0) {
                return 0;
              }
              iVar15 = iVar15 + 1;
              if (0x1f < iVar15) {
                return 0;
              }
            }
            uVar12 = (uVar7 & 0xffff) +
                     (uint)*(ushort *)((int)param_1 + 0x32) + (uint)*(ushort *)(param_1 + 0xc) * 2;
            auStack_17e[iVar15 * 2] = (short)uVar12;
            auStack_180[iVar15 * 4] = *(undefined1 *)(iVar16 + 0x46);
            uVar9 = (uVar8 & 0xffff) +
                    (uint)*(ushort *)((int)param_1 + 0x32) + (uint)*(ushort *)(param_1 + 0xc) * 2;
            auStack_1fe[iVar15 * 2] = (short)uVar9;
            abStack_200[iVar15 * 4] = *(byte *)(iVar16 + 0x46);
          }
          uVar9 = uVar9 & 0xffff;
          uVar12 = uVar12 & 0xffff;
          iVar15 = iVar15 + 1;
          if (0x1f < iVar15) {
            return 0;
          }
        }
        if (iVar17 < iVar15) {
          iVar17 = iVar15;
        }
        FUN_005f1a80(auStack_80,auStack_180,iVar17);
        FUN_005f1a80(auStack_100,abStack_200,iVar17);
        puVar18 = (undefined4 *)puVar18[2];
      } while (puVar18 != (undefined4 *)0x0);
      FUN_005f16b0(*param_1,auStack_80,auStack_100,iVar17);
      puVar18 = param_1;
      do {
        iVar16 = puVar18[3];
        iVar15 = 0;
        if (iVar16 != 0) {
          sVar6 = *(short *)(iVar16 + 0x28);
          sVar14 = 0;
          do {
            if (*(byte *)(iVar16 + 0x47) != 0) {
              iVar15 = iVar15 + (*(byte *)(iVar16 + 0x47) - 1);
            }
            *(short *)(iVar16 + 0x28) = sVar6;
            *(short *)(iVar16 + 0x1c) =
                 (asStack_7e[iVar15 * 2] - sVar14) -
                 (*(short *)((int)param_1 + 0x32) + *(short *)(param_1 + 0xc) * 2);
            sVar4 = asStack_7e[iVar15 * 2];
            sVar6 = sVar6 + (sVar4 - sVar14);
            if (*(char *)(iVar16 + 0x47) != '\0') {
              iVar13 = 0;
              while ((iVar13 < (int)(*(byte *)(iVar16 + 0x47) - 1) && (*(int *)(iVar16 + 8) != 0)))
              {
                iVar13 = iVar13 + 1;
                iVar16 = *(int *)(iVar16 + 8);
              }
            }
            iVar16 = *(int *)(iVar16 + 8);
            iVar15 = iVar15 + 1;
            sVar14 = sVar4;
          } while (iVar16 != 0);
        }
        puVar18 = (undefined4 *)puVar18[2];
      } while (puVar18 != (undefined4 *)0x0);
      uVar5 = *(undefined2 *)(auStack_80 + iVar17 * 4 + -2);
    }
    else {
      uVar5 = 0;
    }
  }
  else {
    uVar5 = 0;
  }
  return uVar5;
}



================================================================