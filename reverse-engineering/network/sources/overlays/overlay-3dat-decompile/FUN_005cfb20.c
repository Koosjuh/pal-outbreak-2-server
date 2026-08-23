FUNCTION FUN_005cfb20 @ 0x005cfb20  size=3624
CALLERS (0): 
CALLEES (4): FUN_005cf600@0x005cf600, FUN_005cf3a0@0x005cf3a0, FUN_005cf680@0x005cf680, FUN_005cf8e0@0x005cf8e0
----------------------------------------------------------------

/* WARNING: Removing unreachable block (ram,0x005cfbd0) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005cfb20(void)

{
  byte bVar1;
  char cVar2;
  ushort uVar3;
  ushort uVar4;
  int iVar5;
  char *pcVar6;
  bool bVar7;
  long lVar8;
  short sVar9;
  ulong uVar10;
  uint uVar11;
  float fVar12;
  float fVar13;
  float afStack_10 [4];
  
  afStack_10[0] = (float)_DAT_00642dd0;
  afStack_10[1] = (float)((ulong)_DAT_00642dd0 >> 0x20);
  afStack_10[2] = (float)DAT_00642dd8;
  afStack_10[3] = (float)DAT_00642ddc;
  if ((*(char *)(iRam00701070 + 0x2e) == '\x01') &&
     ((int)(*(ushort *)(iRam00701070 + 0x18) & 0x200) >> 9 == 0)) {
    return;
  }
  if (((*(ushort *)(iRam00701070 + 0x18) & 1) != 0) || (*(char *)(iRam00701068 + 0x4f8a8) == '\0'))
  {
    fVar13 = (DAT_00692b10 * (float)*(byte *)(iRam00701068 + 0x4f8a9)) / 8.0;
    bVar1 = *(byte *)(iRam00701068 + 0x4f8a8);
    fVar12 = (float)func_0x00120828(fVar13);
    *(short *)(iRam00701078 + 0x10) =
         *(short *)(iRam00701078 + 0x10) + (short)(int)(afStack_10[bVar1] * fVar12);
    bVar1 = *(byte *)(iRam00701068 + 0x4f8a8);
    fVar12 = (float)func_0x00120650(fVar13);
    *(short *)(iRam00701078 + 0x12) =
         *(short *)(iRam00701078 + 0x12) - (short)(int)(afStack_10[bVar1] * fVar12);
    if (*(char *)(iRam00701078 + 4) != '\0') {
      iVar5 = *(int *)(iRam00701068 + 0x5ffc0 + *(int *)(iRam00701078 + 0x20) * 4);
      fVar13 = *(float *)(iVar5 + 0x34) - (float)*(int *)(iRam00701070 + 4);
      fVar12 = fVar13 + 10.0;
      if ((float)(int)*(short *)(iRam00701078 + 0x10) < fVar12) {
        *(undefined2 *)(iRam00701078 + 0x10) = (short)(int)fVar12;
      }
      else {
        fVar12 = (*(float *)(iVar5 + 0x40) + fVar13) - 10.0;
        if (fVar12 < (float)(int)*(short *)(iRam00701078 + 0x10)) {
          *(undefined2 *)(iRam00701078 + 0x10) = (short)(int)fVar12;
        }
      }
      uVar11 = (uint)*(byte *)(iRam00701078 + 4);
      if (10 < uVar11) {
        uVar11 = 10;
      }
      if (*(char *)(iRam00701078 + 6) == '\0') {
        fVar13 = (*(float *)(*(int *)(*(int *)(iRam00701078 + 0x20) * 4 + iRam00701068 + 0x5ffc0) +
                            0x38) - (float)*(int *)(iRam00701070 + 8)) + 20.0;
        fVar12 = fVar13 + 9.0;
        if ((float)(int)*(short *)(iRam00701078 + 0x12) < fVar12) {
          *(undefined2 *)(iRam00701078 + 0x12) = (short)(int)fVar12;
        }
        else {
          fVar13 = fVar13 + (float)(int)(uVar11 * 0x12 + -9);
          if (fVar13 < (float)(int)*(short *)(iRam00701078 + 0x12)) {
            *(undefined2 *)(iRam00701078 + 0x12) = (short)(int)fVar13;
          }
        }
      }
      else {
        fVar13 = *(float *)(*(int *)(*(int *)(iRam00701078 + 0x20) * 4 + iRam00701068 + 0x5ffc0) +
                           0x38) - (float)*(int *)(iRam00701070 + 8);
        fVar12 = fVar13 - (float)(int)(uVar11 * 0x12 + -9);
        if ((float)(int)*(short *)(iRam00701078 + 0x12) < fVar12) {
          *(undefined2 *)(iRam00701078 + 0x12) = (short)(int)fVar12;
        }
        else {
          fVar13 = fVar13 - 9.0;
          if (fVar13 < (float)(int)*(short *)(iRam00701078 + 0x12)) {
            *(undefined2 *)(iRam00701078 + 0x12) = (short)(int)fVar13;
          }
        }
      }
    }
  }
  if (((*(ushort *)(iRam00701070 + 0x18) & 1) == 0) && (*(char *)(iRam00701068 + 0x4f8a8) != '\0'))
  {
    if (*(char *)(iRam00701068 + 0x68e7d) == '\x01') {
      *(undefined1 *)(iRam00701068 + 0x68e7c) = 1;
    }
    else {
      *(undefined1 *)(iRam00701068 + 0x68e7c) = 0;
    }
    *(undefined1 *)(iRam00701068 + 0x68e7d) = 0;
    bVar1 = *(byte *)(iRam00701068 + 0x4f8a9);
    if ((bVar1 < 2) || (9 < bVar1)) {
      if (((bVar1 < 10) || (0xf < bVar1)) && (1 < bVar1)) {
        return;
      }
      if (1000 < *(short *)(iRam00701078 + 0xe)) {
        *(undefined2 *)(iRam00701078 + 0xe) = 0;
      }
      sVar9 = *(short *)(iRam00701078 + 0xe) + 1;
      *(short *)(iRam00701078 + 0xe) = sVar9;
      uVar10 = (long)sVar9 & 7;
      if (((long)sVar9 < 0) && (uVar10 != 0)) {
        uVar10 = (ulong)((int)uVar10 + -8);
      }
      if ((uVar10 != 0) && (*(char *)(iRam00701068 + 0x68e7c) == '\0')) {
        return;
      }
      *(undefined2 *)(iRam00701078 + 0xe) = 0;
LAB_005d0778:
      uVar11 = (uint)*(ushort *)(iRam00701068 + 0x68e78);
      while (uVar11 = uVar11 - 1, 0 < (int)uVar11) {
        pcVar6 = *(char **)(iRam00701068 + uVar11 * 4 + 0x5ffc0);
        if (pcVar6 == (char *)0x0) {
          return;
        }
        if (*pcVar6 == '\0') {
          return;
        }
        lVar8 = FUN_005cf3a0(uVar11 & 0xffff,1);
        if (lVar8 != 0) {
          return;
        }
      }
      if ((*(ushort *)(iRam00701070 + 0x18) & 1) == 0) {
        uVar11 = 0;
        while ((((int)uVar11 < 500 &&
                (pcVar6 = *(char **)(iRam00701068 + uVar11 * 4 + 0x5ffc0), pcVar6 != (char *)0x0))
               && (*pcVar6 != '\0'))) {
          uVar11 = uVar11 + 1;
        }
        do {
          uVar11 = uVar11 - 1;
          if ((int)uVar11 < 1) {
            return;
          }
          pcVar6 = *(char **)(iRam00701068 + uVar11 * 4 + 0x5ffc0);
          if (pcVar6 == (char *)0x0) {
            return;
          }
          if (*pcVar6 == '\0') {
            return;
          }
          lVar8 = FUN_005cf3a0(uVar11 & 0xffff,1);
        } while (lVar8 == 0);
        return;
      }
      uVar11 = (uint)*(ushort *)(iRam00701068 + 0x68e78);
      while( true ) {
        if ((int)uVar11 < 1) {
          return;
        }
        pcVar6 = *(char **)(iRam00701068 + uVar11 * 4 + 0x5ffc0);
        if (pcVar6 == (char *)0x0) {
          return;
        }
        if (*pcVar6 == '\0') {
          return;
        }
        lVar8 = FUN_005cf3a0(uVar11 & 0xffff,1);
        if (lVar8 != 0) break;
        uVar11 = uVar11 - 1;
      }
      return;
    }
    if (1000 < *(short *)(iRam00701078 + 0xe)) {
      *(undefined2 *)(iRam00701078 + 0xe) = 0;
    }
    sVar9 = *(short *)(iRam00701078 + 0xe) + 1;
    *(short *)(iRam00701078 + 0xe) = sVar9;
    uVar10 = (long)sVar9 & 7;
    if (((long)sVar9 < 0) && (uVar10 != 0)) {
      uVar10 = (ulong)((int)uVar10 + -8);
    }
    if ((uVar10 != 0) && (*(char *)(iRam00701068 + 0x68e7c) == '\0')) {
      return;
    }
    *(undefined2 *)(iRam00701078 + 0xe) = 0;
  }
  else {
    if ((uRam0036d6dc == 0x29) && (*(char *)(iRam00701078 + 4) != '\0')) {
      FUN_005cf600();
      return;
    }
    cVar2 = *(char *)(iRam00715da8 + 0x49c);
    if ((cVar2 != '+') || (*(char *)(iRam00701078 + 4) != '\0')) {
      if ((cVar2 == 'K') && (*(byte *)(iRam00701078 + 4) != 0)) {
        if (10 < *(byte *)(iRam00701078 + 4)) {
          if (9 < *(byte *)(iRam00701078 + 5)) {
            *(byte *)(iRam00701078 + 5) = *(byte *)(iRam00701078 + 5) - 9;
            return;
          }
        }
        *(undefined1 *)(iRam00701078 + 5) = 1;
        return;
      }
      if ((cVar2 == 'N') && (*(byte *)(iRam00701078 + 4) != 0)) {
        uVar11 = *(byte *)(iRam00701078 + 5) + 9;
        if (*(byte *)(iRam00701078 + 4) <= uVar11) {
          return;
        }
        *(char *)(iRam00701078 + 5) = (char)uVar11;
        return;
      }
      if ((uRam0036d6dc < 0x4f) || (0x52 < uRam0036d6dc)) {
        uVar3 = *(ushort *)(iRam00701068 + 0x4f8a4);
        if (((uVar3 & 0x200) != 0) && (*(char *)(iRam00701078 + 4) != '\0')) {
          FUN_005cf600();
          return;
        }
        uVar4 = *(ushort *)(iRam00701068 + 0x4f8a0);
        if (((uVar4 & 8) != 0) || ((uVar4 & 2) != 0)) {
          if ((((uVar3 & 8) != 0) || ((uVar3 & 2) != 0)) && (*(char *)(iRam00701078 + 4) != '\0'))
          goto LAB_005d0438;
          if (1000 < *(short *)(iRam00701078 + 0xe)) {
            *(undefined2 *)(iRam00701078 + 0xe) = 0;
          }
          sVar9 = *(short *)(iRam00701078 + 0xe) + 1;
          *(short *)(iRam00701078 + 0xe) = sVar9;
          uVar10 = (long)sVar9 & 7;
          if (((long)sVar9 < 0) && (uVar10 != 0)) {
            uVar10 = (ulong)((int)uVar10 + -8);
          }
          if (((uVar10 != 0) && ((*(ushort *)(iRam00701068 + 0x4f8a4) & 8) == 0)) &&
             ((*(ushort *)(iRam00701068 + 0x4f8a4) & 2) == 0)) {
            return;
          }
          if ((*(int *)(iRam00701078 + 0x20) != 0) && (*(char *)(iRam00701078 + 4) != '\0')) {
            FUN_005cf680();
            return;
          }
          goto LAB_005d04fc;
        }
        if (((uVar4 & 4) == 0) && ((uVar4 & 1) == 0)) {
          *(undefined1 *)(iRam00701068 + 0x68e7d) = 1;
          *(undefined2 *)(iRam00701078 + 0xe) = 0;
          return;
        }
        if ((((uVar3 & 4) == 0) && ((uVar3 & 1) == 0)) || (*(char *)(iRam00701078 + 4) == '\0')) {
          if (1000 < *(short *)(iRam00701078 + 0xe)) {
            *(undefined2 *)(iRam00701078 + 0xe) = 0;
          }
          sVar9 = *(short *)(iRam00701078 + 0xe) + 1;
          *(short *)(iRam00701078 + 0xe) = sVar9;
          uVar10 = (long)sVar9 & 7;
          if (((long)sVar9 < 0) && (uVar10 != 0)) {
            uVar10 = (ulong)((int)uVar10 + -8);
          }
          if (((uVar10 != 0) && ((*(ushort *)(iRam00701068 + 0x4f8a4) & 4) == 0)) &&
             ((*(ushort *)(iRam00701068 + 0x4f8a4) & 1) == 0)) {
            return;
          }
          if ((*(int *)(iRam00701078 + 0x20) != 0) && (*(char *)(iRam00701078 + 4) != '\0')) {
            FUN_005cf8e0();
            return;
          }
          goto LAB_005d0778;
        }
      }
      else {
        if ((uRam0036d6dc != 0x50) && (uRam0036d6dc != 0x52)) {
          if ((uRam0036d6dc != 0x4f) && (uRam0036d6dc != 0x51)) {
            return;
          }
          if (((*(char *)(iRam00715da8 + 0x49d) != 'Q') && (*(char *)(iRam00715da8 + 0x49d) != 'O'))
             || (*(char *)(iRam00701078 + 4) == '\0')) {
            if (1000 < *(short *)(iRam00701078 + 0xe)) {
              *(undefined2 *)(iRam00701078 + 0xe) = 0;
            }
            sVar9 = *(short *)(iRam00701078 + 0xe) + 1;
            *(short *)(iRam00701078 + 0xe) = sVar9;
            uVar10 = (long)sVar9 & 7;
            if (((long)sVar9 < 0) && (uVar10 != 0)) {
              uVar10 = (ulong)((int)uVar10 + -8);
            }
            if (((uVar10 != 0) && (*(char *)(iRam00715da8 + 0x49d) != 'O')) &&
               (*(char *)(iRam00715da8 + 0x49d) != 'Q')) {
              return;
            }
            if (*(int *)(iRam00701078 + 0x20) == 0) goto LAB_005d04fc;
          }
LAB_005d0438:
          FUN_005cf680();
          return;
        }
        if (((*(char *)(iRam00715da8 + 0x49d) != 'R') && (*(char *)(iRam00715da8 + 0x49d) != 'P'))
           || (*(char *)(iRam00701078 + 4) == '\0')) {
          if (1000 < *(short *)(iRam00701078 + 0xe)) {
            *(undefined2 *)(iRam00701078 + 0xe) = 0;
          }
          sVar9 = *(short *)(iRam00701078 + 0xe) + 1;
          *(short *)(iRam00701078 + 0xe) = sVar9;
          uVar10 = (long)sVar9 & 7;
          if (((long)sVar9 < 0) && (uVar10 != 0)) {
            uVar10 = (ulong)((int)uVar10 + -8);
          }
          if (((uVar10 != 0) && (*(char *)(iRam00715da8 + 0x49d) != 'P')) &&
             (*(char *)(iRam00715da8 + 0x49d) != 'R')) {
            return;
          }
          if (*(int *)(iRam00701078 + 0x20) == 0) goto LAB_005d0778;
        }
      }
      FUN_005cf8e0();
      return;
    }
  }
LAB_005d04fc:
  uVar11 = (uint)*(ushort *)(iRam00701068 + 0x68e78);
  while( true ) {
    uVar11 = uVar11 + 1;
    if (499 < (int)uVar11) {
      return;
    }
    pcVar6 = *(char **)(iRam00701068 + uVar11 * 4 + 0x5ffc0);
    if ((pcVar6 == (char *)0x0) || (*pcVar6 == '\0')) break;
    lVar8 = FUN_005cf3a0(uVar11 & 0xffff,1);
    if (lVar8 != 0) {
      return;
    }
  }
  uVar11 = 0;
  if ((*(ushort *)(iRam00701070 + 0x18) & 1) != 0) {
    uVar11 = (uint)*(ushort *)(iRam00701068 + 0x68e78);
    while( true ) {
      if (499 < (int)uVar11) {
        return;
      }
      pcVar6 = *(char **)(iRam00701068 + uVar11 * 4 + 0x5ffc0);
      if (pcVar6 == (char *)0x0) {
        return;
      }
      if (*pcVar6 == '\0') {
        return;
      }
      lVar8 = FUN_005cf3a0(uVar11 & 0xffff,1);
      if (lVar8 != 0) break;
      uVar11 = uVar11 + 1;
    }
    return;
  }
  bVar7 = true;
  while( true ) {
    if (!bVar7) {
      return;
    }
    pcVar6 = *(char **)(iRam00701068 + uVar11 * 4 + 0x5ffc0);
    if (pcVar6 == (char *)0x0) {
      return;
    }
    if (*pcVar6 == '\0') {
      return;
    }
    lVar8 = FUN_005cf3a0(uVar11 & 0xffff,1);
    if (lVar8 != 0) break;
    uVar11 = uVar11 + 1;
    bVar7 = (int)uVar11 < 500;
  }
  return;
}



================================================================