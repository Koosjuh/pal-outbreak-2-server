FUNCTION FUN_005e3a80 @ 0x005e3a80  size=3520
CALLERS (1): FUN_005daf30@0x005daf30
CALLEES (4): FUN_005e0440@0x005e0440, FUN_005ddc20@0x005ddc20, FUN_005e1da0@0x005e1da0, FUN_005e07c0@0x005e07c0
----------------------------------------------------------------

void FUN_005e3a80(int param_1)

{
  byte bVar1;
  byte bVar2;
  char cVar3;
  char *pcVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  
  uVar7 = 0;
  while( true ) {
    if (499 < uVar7) {
      return;
    }
    pcVar4 = *(char **)(iRam00701068 + uVar7 * 4 + 0x5ffc0);
    if (pcVar4 == (char *)0x0) {
      return;
    }
    if (*pcVar4 == '\0') {
      return;
    }
    if ((pcVar4[2] == '\b') && (*(uint *)(iRam00701078 + 0x20) == uVar7)) break;
    uVar7 = uVar7 + 1 & 0xffff;
  }
  bVar1 = *(byte *)(iRam00701078 + 4);
  uVar8 = uVar7;
  if (bVar1 == 0) {
    return;
  }
  do {
    uVar5 = uVar8 + 1;
    uVar8 = uVar5 & 0xffff;
    uVar6 = uVar5 & 0xffff;
    if (((499 < uVar6) ||
        (iVar9 = *(int *)(iRam00701068 + (uVar5 & 0xffff) * 4 + 0x5ffc0),
        *(char *)(iVar9 + 2) != '\b')) || (bVar2 = *(byte *)(iVar9 + 0x5f), 10 < bVar2)) break;
  } while (bVar2 != 0);
  *(short *)(iRam00701078 + 8) =
       (short)((int)((*(byte *)(iRam00701078 + 5) - 1) * 0x90) / (int)(uint)bVar1) + 0x12;
  *(short *)(iRam00701078 + 10) =
       (short)(0x5a0 / *(byte *)(iRam00701078 + 4)) + *(short *)(iRam00701078 + 8);
  *(short *)(iRam00701078 + 0xc) = *(short *)(iRam00701078 + 10) - *(short *)(iRam00701078 + 8);
  if (0xb4 < *(short *)(iRam00701078 + 10)) {
    *(undefined2 *)(iRam00701078 + 10) = 0xb4;
  }
  if (10 < *(byte *)(iRam00701078 + 4)) {
    if (*(short *)(iRam00701078 + 8) < 0x12) {
      *(undefined2 *)(iRam00701078 + 8) = 0x12;
      *(short *)(iRam00701078 + 10) = *(short *)(iRam00701078 + 0xc) + 0x12;
      *(undefined1 *)(iRam00701078 + 5) = 1;
    }
    if (0xa2 < *(short *)(iRam00701078 + 10)) {
      *(short *)(iRam00701078 + 8) = 0xa2 - *(short *)(iRam00701078 + 0xc);
      *(undefined2 *)(iRam00701078 + 10) = 0xa2;
      *(char *)(iRam00701078 + 5) = *(char *)(iRam00701078 + 4) + -9;
    }
  }
  iVar9 = *(int *)(uVar7 * 4 + iRam00701068 + 0x5ffc0);
  fVar14 = *(float *)(iVar9 + 0x34) - (float)*(int *)(iRam00701070 + 4);
  fVar15 = *(float *)(iVar9 + 0x38) - (float)*(int *)(iRam00701070 + 8);
  fVar13 = fVar14 + *(float *)(iVar9 + 0x40);
  if (*(char *)(iRam00701078 + 6) == '\0') {
    iVar9 = uVar6 * 4;
    fVar12 = fVar15 + 20.0;
    FUN_005e0440(fVar14,fVar12,fVar13,
                 fVar12 + (float)((uint)*(byte *)(*(int *)(iVar9 + iRam00701068 + 0x5ffbc) + 0x5f) *
                                 0x12),0xffffffffffffffff);
    FUN_005e1da0(fVar14,fVar15 + 16.0 + 4.0,fVar13,
                 fVar12 + (float)((uint)*(byte *)(*(int *)(iVar9 + iRam00701068 + 0x5ffbc) + 0x5f) *
                                 0x12),0xffffffffff000001);
    fVar11 = (float)(int)*(short *)(iRam00701078 + 0x10);
    if (((fVar14 < fVar11) &&
        (((fVar11 <= fVar13 - 16.0 || ((*(byte *)(iRam00701078 + 4) < 0xb && (fVar11 < fVar13)))) &&
         (fVar12 < (float)(int)*(short *)(iRam00701078 + 0x12))))) &&
       (bVar2 = *(byte *)(*(int *)(iVar9 + iRam00701068 + 0x5ffbc) + 0x5f),
       (float)(int)*(short *)(iRam00701078 + 0x12) < fVar12 + (float)((uint)bVar2 * 0x12))) {
      for (uVar8 = 0; uVar8 < bVar2; uVar8 = uVar8 + 1 & 0xffff) {
        fVar11 = fVar12 + (float)(uVar8 * 0x12);
        if ((fVar11 <= (float)(int)*(short *)(iRam00701078 + 0x12)) &&
           ((float)(int)*(short *)(iRam00701078 + 0x12) < fVar12 + (float)((uVar8 + 1) * 0x12))) {
          FUN_005e0440(fVar14,fVar11,fVar13,0x600000ff);
          break;
        }
      }
    }
    if (10 < bVar1) {
      if (*(char *)(iRam00701078 + 3) == '\x05') {
        FUN_005e07c0(fVar13 - 16.0,fVar12,0x41800000,0x41a00000,0xe,0);
        if (*(int *)(iRam00701068 + 0x69018) == 0) {
          *(undefined1 *)(iRam00701078 + 3) = 0;
        }
      }
      else {
        FUN_005e07c0(fVar13 - 16.0,fVar12,0x41800000,0x41a00000,10,0);
      }
      FUN_005e07c0(fVar13 - 16.0,fVar12 + 20.0,0x41800000,0x43200000,0x12,0);
      if (*(char *)(iRam00701078 + 3) == '\x06') {
        FUN_005e07c0(fVar13 - 16.0,(fVar12 + 180.0) - 20.0,0xf,0);
        if (*(int *)(iRam00701068 + 0x69018) == 0) {
          *(undefined1 *)(iRam00701078 + 3) = 0;
        }
      }
      else {
        FUN_005e07c0(fVar13 - 16.0,(fVar12 + 180.0) - 20.0,0xb,0);
      }
      FUN_005e07c0(fVar13 - 16.0,fVar12 + (float)(int)*(short *)(iRam00701078 + 8),0x41800000,
                   (float)((int)*(short *)(iRam00701078 + 10) - (int)*(short *)(iRam00701078 + 8)),
                   0x13,0);
    }
  }
  else {
    iVar9 = uVar6 * 4;
    FUN_005e0440(fVar14,fVar15,fVar13,
                 fVar15 - (float)((uint)*(byte *)(*(int *)(iVar9 + iRam00701068 + 0x5ffbc) + 0x5f) *
                                 0x12),0xffffffffffffffff);
    FUN_005e1da0(fVar14,fVar15,fVar13,
                 fVar15 - (float)((uint)*(byte *)(*(int *)(iVar9 + iRam00701068 + 0x5ffbc) + 0x5f) *
                                 0x12),0xffffffffff000001);
    fVar11 = (float)(int)*(short *)(iRam00701078 + 0x10);
    if (((fVar14 < fVar11) &&
        ((fVar11 <= fVar13 - 16.0 || ((*(byte *)(iRam00701078 + 4) < 0xb && (fVar11 < fVar13))))))
       && ((float)(int)*(short *)(iRam00701078 + 0x12) < fVar15)) {
      uVar8 = *(byte *)(*(int *)(iVar9 + iRam00701068 + 0x5ffbc) + 0x5f) + 1;
      uVar5 = 0;
      if (fVar15 - (float)(uVar8 * 0x12) < (float)(int)*(short *)(iRam00701078 + 0x12)) {
        for (; uVar5 < uVar8; uVar5 = uVar5 + 1 & 0xffff) {
          fVar11 = fVar15 - (float)(uVar5 * 0x12);
          if ((fVar11 < (float)(int)*(short *)(iRam00701078 + 0x12)) &&
             ((float)(int)*(short *)(iRam00701078 + 0x12) <=
              fVar15 - (float)(int)((uVar5 - 1) * 0x12))) {
            FUN_005e0440(fVar14,fVar11,fVar13,0x600000ff);
            break;
          }
        }
      }
    }
    if (10 < bVar1) {
      if (*(char *)(iRam00701078 + 3) == '\x05') {
        FUN_005e07c0(fVar13 - 16.0,fVar15 - 180.0,0x41800000,0x41a00000,0xe,0);
        if (*(int *)(iRam00701068 + 0x69018) == 0) {
          *(undefined1 *)(iRam00701078 + 3) = 0;
        }
      }
      else {
        FUN_005e07c0(fVar13 - 16.0,fVar15 - 180.0,0x41800000,0x41a00000,10,0);
      }
      FUN_005e07c0(fVar13 - 16.0,fVar15 - 20.0,0x41800000,0xc30c0000,0x12,0);
      if (*(char *)(iRam00701078 + 3) == '\x06') {
        FUN_005e07c0(fVar13 - 16.0,fVar15 - 20.0,0xf,0);
        if (*(int *)(iRam00701068 + 0x69018) == 0) {
          *(undefined1 *)(iRam00701078 + 3) = 0;
        }
      }
      else {
        FUN_005e07c0(fVar13 - 16.0,fVar15 - 20.0,0xb,0);
      }
      FUN_005e07c0(fVar13 - 16.0,(fVar15 - 180.0) + (float)(int)*(short *)(iRam00701078 + 8),
                   0x41800000,
                   (float)((int)*(short *)(iRam00701078 + 10) - (int)*(short *)(iRam00701078 + 8)),
                   0x13,0);
    }
  }
  param_1 = param_1 * 4;
  uVar8 = 0;
  fVar13 = fVar15 + 2.0;
  fVar11 = fVar14 + 4.0;
  uVar7 = uVar7 + *(byte *)(iRam00701078 + 5);
  while( true ) {
    if (499 < (uVar7 & 0xffff)) {
      return;
    }
    iVar10 = (uVar7 & 0xffff) * 4;
    iVar9 = *(int *)(iRam00701068 + iVar10 + 0x5ffc0);
    if (*(char *)(iVar9 + 2) != '\b') {
      return;
    }
    cVar3 = *(char *)(iVar9 + 0x5f);
    uVar5 = uVar8 + 1;
    if (cVar3 == '\0') {
      return;
    }
    uVar8 = uVar5 & 0xffff;
    if (10 < uVar8) break;
    if (*(char *)(iRam00701078 + 6) == '\0') {
      if (bVar1 < 0xb) {
        iVar9 = *(int *)(param_1 + iRam00701068 + 0x5ffc0);
        if (cVar3 == *(char *)(iVar9 + 5)) {
          fVar12 = fVar15 + (float)(uVar8 * 0x12);
          FUN_005e0440(fVar14,fVar12,fVar14 + *(float *)(iVar9 + 0x40),fVar12 + 18.0 + 2.0,
                       0x6000ff00);
        }
      }
      else {
        iVar9 = *(int *)(param_1 + iRam00701068 + 0x5ffc0);
        if (cVar3 == *(char *)(iVar9 + 5)) {
          fVar12 = fVar15 + (float)(uVar8 * 0x12);
          FUN_005e0440(fVar14,fVar12,(fVar14 + *(float *)(iVar9 + 0x40)) - 16.0,fVar12 + 18.0 + 2.0,
                       0x6000ff00);
        }
      }
      iVar9 = *(int *)(iRam00701068 + iVar10 + 0x5ffc0);
      FUN_005ddc20(fVar11,fVar13 + (float)((uVar5 & 0xffff) * 0x12),0xe,0xffffffffff000001,0,
                   *(undefined1 *)(iVar9 + 4),*(undefined4 *)(iVar9 + 0x60));
    }
    else if (bVar1 < 0xb) {
      iVar9 = *(int *)(param_1 + iRam00701068 + 0x5ffc0);
      if (cVar3 == *(char *)(iVar9 + 5)) {
        fVar12 = fVar15 - (float)(int)(((bVar1 - uVar8) + 1) * 0x12);
        FUN_005e0440(fVar14,fVar12,fVar14 + *(float *)(iVar9 + 0x40),fVar12 + 18.0,0x6000ff00);
      }
      iVar9 = *(int *)(iRam00701068 + iVar10 + 0x5ffc0);
      FUN_005ddc20(fVar11,fVar13 - (float)(int)((((uint)bVar1 - (uVar5 & 0xffff)) + 1) * 0x12),0xe,
                   0xffffffffff000001,0,*(undefined1 *)(iVar9 + 4),*(undefined4 *)(iVar9 + 0x60));
    }
    else {
      iVar9 = *(int *)(param_1 + iRam00701068 + 0x5ffc0);
      if (cVar3 == *(char *)(iVar9 + 5)) {
        fVar12 = fVar15 - (float)(int)((0xb - uVar8) * 0x12);
        FUN_005e0440(fVar14,fVar12,(fVar14 + *(float *)(iVar9 + 0x40)) - 16.0,fVar12 + 18.0,
                     0x6000ff00);
      }
      iVar9 = *(int *)(iRam00701068 + iVar10 + 0x5ffc0);
      FUN_005ddc20(fVar11,fVar13 - (float)(int)((0xb - (uVar5 & 0xffff)) * 0x12),0xe,
                   0xffffffffff000001,0,*(undefined1 *)(iVar9 + 4),*(undefined4 *)(iVar9 + 0x60));
    }
    uVar7 = (uVar7 & 0xffff) + 1;
  }
  return;
}



================================================================