FUNCTION FUN_005d2c20 @ 0x005d2c20  size=3336
CALLERS (1): FUN_005d1e80@0x005d1e80
CALLEES (2): FUN_005d5df0@0x005d5df0, FUN_0061e730@0x0061e730
----------------------------------------------------------------

undefined8 FUN_005d2c20(undefined8 param_1)

{
  short sVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  
  iVar4 = (int)param_1;
  iVar7 = iVar4 * 4;
  iVar6 = *(int *)(iVar7 + iRam00701068 + 0x5ffc0);
  fVar11 = *(float *)(iVar6 + 0x34) - (float)*(int *)(iRam00701070 + 4);
  fVar9 = fVar11 + *(float *)(iVar6 + 0x40);
  fVar8 = *(float *)(iVar6 + 0x38) - (float)*(int *)(iRam00701070 + 8);
  fVar10 = (float)(int)*(short *)(iRam00701078 + 0x10);
  if ((fVar10 <= fVar11) || (fVar9 <= fVar10)) {
    *(undefined1 *)(iRam00701078 + 4) = 0;
    return 0;
  }
  uVar2 = (uint)*(byte *)(iRam00701078 + 4);
  uVar3 = (uint)*(byte *)(iRam00701078 + 4);
  if (((10 < uVar2) && (fVar9 - 16.0 < fVar10)) && (fVar10 < fVar9)) {
    if (*(char *)(iRam00701078 + 6) == '\0') {
      sVar1 = *(short *)(iRam00701078 + 0x12);
      fVar9 = fVar8 + 20.0;
      fVar10 = (float)(int)sVar1;
      if ((fVar9 < fVar10) && (fVar10 < fVar9 + 20.0)) {
        if (1 < *(byte *)(iRam00701078 + 5)) {
          FUN_005d5df0(0,0xffffffffffffffff,5);
          return param_1;
        }
        FUN_005d5df0(0,0,5);
        return param_1;
      }
      fVar10 = (float)(int)sVar1;
      if ((fVar9 + 20.0 <= fVar10) && (fVar10 <= fVar9 + (float)(int)*(short *)(iRam00701078 + 8)))
      {
        iVar6 = *(byte *)(iRam00701078 + 5) - 9;
        if (iVar6 < 1) {
          *(undefined1 *)(iRam00701078 + 5) = 1;
        }
        else {
          *(undefined1 *)(iRam00701078 + 5) = (char)iVar6;
        }
        *(short *)(iRam00701078 + 8) =
             (short)((int)((*(byte *)(iRam00701078 + 5) - 1) * 0x90) /
                    (int)(uint)*(byte *)(iRam00701078 + 4)) + 0x12;
        *(short *)(iRam00701078 + 10) =
             (short)(0x5a0 / *(byte *)(iRam00701078 + 4)) + *(short *)(iRam00701078 + 8);
        *(short *)(iRam00701078 + 0xc) =
             *(short *)(iRam00701078 + 10) - *(short *)(iRam00701078 + 8);
        *(int *)(iRam00701078 + 0x1c) =
             (int)*(short *)(iRam00701078 + 0x12) - (int)*(short *)(iRam00701078 + 8);
        return param_1;
      }
      iVar6 = (int)sVar1;
      if ((fVar9 + (float)(int)*(short *)(iRam00701078 + 8) < (float)iVar6) &&
         ((float)iVar6 < fVar9 + (float)(int)*(short *)(iRam00701078 + 10))) {
        return param_1;
      }
      if ((fVar9 + (float)(int)*(short *)(iRam00701078 + 10) <= (float)iVar6) &&
         ((float)iVar6 <= (fVar9 + 180.0) - 18.0)) {
        *(char *)(iRam00701078 + 5) = *(char *)(iRam00701078 + 5) + '\t';
        if ((uint)*(byte *)(iRam00701078 + 4) < *(byte *)(iRam00701078 + 5) + 10) {
          *(byte *)(iRam00701078 + 5) = *(byte *)(iRam00701078 + 4) - 9;
        }
        *(short *)(iRam00701078 + 8) =
             (short)((int)((*(byte *)(iRam00701078 + 5) - 1) * 0x90) /
                    (int)(uint)*(byte *)(iRam00701078 + 4)) + 0x12;
        *(short *)(iRam00701078 + 10) =
             (short)(0x5a0 / *(byte *)(iRam00701078 + 4)) + *(short *)(iRam00701078 + 8);
        *(short *)(iRam00701078 + 0xc) =
             *(short *)(iRam00701078 + 10) - *(short *)(iRam00701078 + 8);
        *(int *)(iRam00701078 + 0x1c) =
             (int)*(short *)(iRam00701078 + 0x12) - (int)*(short *)(iRam00701078 + 8);
        return param_1;
      }
      if ((fVar9 + 162.0 < (float)iVar6) && ((float)iVar6 < fVar9 + 180.0)) {
        if (9 < (int)(uVar3 - *(byte *)(iRam00701078 + 5))) {
          FUN_005d5df0(0,1,6);
          return param_1;
        }
        FUN_005d5df0(0,0,6);
        return param_1;
      }
    }
    else {
      sVar1 = *(short *)(iRam00701078 + 0x12);
      fVar9 = (float)(int)sVar1;
      if ((fVar9 < fVar8 - 162.0) && (fVar8 - 180.0 < fVar9)) {
        if (1 < *(byte *)(iRam00701078 + 5)) {
          FUN_005d5df0(0,0xffffffffffffffff,5);
          return param_1;
        }
        FUN_005d5df0(0,0,5);
        return param_1;
      }
      fVar9 = (float)(int)sVar1;
      if ((fVar8 - 162.0 <= fVar9) &&
         (fVar9 <= (fVar8 + (float)(int)*(short *)(iRam00701078 + 8)) - 180.0)) {
        iVar6 = *(byte *)(iRam00701078 + 5) - 9;
        if (iVar6 < 1) {
          *(undefined1 *)(iRam00701078 + 5) = 1;
        }
        else {
          *(undefined1 *)(iRam00701078 + 5) = (char)iVar6;
        }
        *(short *)(iRam00701078 + 8) =
             (short)((int)((*(byte *)(iRam00701078 + 5) - 1) * 0x90) /
                    (int)(uint)*(byte *)(iRam00701078 + 4)) + 0x12;
        *(short *)(iRam00701078 + 10) =
             (short)(0x5a0 / *(byte *)(iRam00701078 + 4)) + *(short *)(iRam00701078 + 8);
        *(short *)(iRam00701078 + 0xc) =
             *(short *)(iRam00701078 + 10) - *(short *)(iRam00701078 + 8);
        *(int *)(iRam00701078 + 0x1c) =
             (int)*(short *)(iRam00701078 + 0x12) - (int)*(short *)(iRam00701078 + 8);
        return param_1;
      }
      iVar6 = (int)sVar1;
      if (((fVar8 + (float)(int)*(short *)(iRam00701078 + 8)) - 180.0 < (float)iVar6) &&
         ((float)iVar6 < (fVar8 + (float)(int)*(short *)(iRam00701078 + 10)) - 180.0)) {
        return param_1;
      }
      if (((fVar8 + (float)(int)*(short *)(iRam00701078 + 10)) - 180.0 <= (float)iVar6) &&
         ((float)iVar6 <= fVar8 - 20.0)) {
        *(char *)(iRam00701078 + 5) = *(char *)(iRam00701078 + 5) + '\t';
        if ((uint)*(byte *)(iRam00701078 + 4) < *(byte *)(iRam00701078 + 5) + 10) {
          *(byte *)(iRam00701078 + 5) = *(byte *)(iRam00701078 + 4) - 9;
        }
        *(short *)(iRam00701078 + 8) =
             (short)((int)((*(byte *)(iRam00701078 + 5) - 1) * 0x90) /
                    (int)(uint)*(byte *)(iRam00701078 + 4)) + 0x12;
        *(short *)(iRam00701078 + 10) =
             (short)(0x5a0 / *(byte *)(iRam00701078 + 4)) + *(short *)(iRam00701078 + 8);
        *(short *)(iRam00701078 + 0xc) =
             *(short *)(iRam00701078 + 10) - *(short *)(iRam00701078 + 8);
        *(int *)(iRam00701078 + 0x1c) =
             (int)*(short *)(iRam00701078 + 0x12) - (int)*(short *)(iRam00701078 + 8);
        return param_1;
      }
      if (((float)iVar6 < fVar8 - 1.0) && (fVar8 - 20.0 < (float)iVar6)) {
        if (9 < (int)(uVar3 - *(byte *)(iRam00701078 + 5))) {
          FUN_005d5df0(0,1,6);
          return param_1;
        }
        FUN_005d5df0(0,0,6);
        return param_1;
      }
    }
  }
  if (*(char *)(iRam00701078 + 6) == '\0') {
    if (uVar2 < 10) {
      for (iVar6 = 0; iVar6 <= (int)uVar2; iVar6 = iVar6 + 1) {
        if ((fVar8 + 20.0 + (float)(iVar6 * 0x12) <= (float)(int)*(short *)(iRam00701078 + 0x12)) &&
           ((float)(int)*(short *)(iRam00701078 + 0x12) < fVar8 + 20.0 + (float)((iVar6 + 1) * 0x12)
           )) break;
      }
      if ((iVar6 < 0) || ((int)uVar2 < iVar6)) {
        return 0;
      }
    }
    else {
      for (iVar6 = 0; iVar6 < 0xb; iVar6 = iVar6 + 1) {
        if ((fVar8 + 20.0 + (float)(iVar6 * 0x12) <= (float)(int)*(short *)(iRam00701078 + 0x12)) &&
           ((float)(int)*(short *)(iRam00701078 + 0x12) < fVar8 + 20.0 + (float)((iVar6 + 1) * 0x12)
           )) break;
      }
      if ((int)(uVar3 - *(byte *)(iRam00701078 + 2)) < 9) {
        if ((iVar6 < 0) || (9 < iVar6)) {
          return 0;
        }
      }
      else {
        if (iVar6 < 0) {
          return 0;
        }
        if (10 < iVar6) {
          return 0;
        }
      }
    }
    FUN_0061e730();
    *(char *)(iRam00701078 + 2) = (char)iVar6 + (char)param_1 + *(char *)(iRam00701078 + 5);
    *(undefined4 *)(*(int *)(iRam00701068 + 0x5ffc0 + iVar7) + 0x60) =
         *(undefined4 *)
          (*(int *)(iRam00701068 + 0x5ffc0 + (iVar6 + iVar4 + (uint)*(byte *)(iRam00701078 + 5)) * 4
                   ) + 0x60);
    *(undefined1 *)(*(int *)(iRam00701068 + 0x5ffc0 + iVar7) + 5) =
         *(undefined1 *)
          (*(int *)(iRam00701068 + 0x5ffc0 + (iVar6 + iVar4 + (uint)*(byte *)(iRam00701078 + 5)) * 4
                   ) + 0x5f);
    *(short *)(iRam00701078 + 0x12) =
         (short)(int)((*(float *)(*(int *)(*(int *)(iRam00701078 + 0x20) * 4 + iRam00701068 +
                                          0x5ffc0) + 0x38) - (float)*(int *)(iRam00701070 + 8)) +
                     10.0);
  }
  else {
    if (uVar2 < 10) {
      for (iVar5 = 0; iVar5 <= (int)uVar2; iVar5 = iVar5 + 1) {
        if (((float)(int)*(short *)(iRam00701078 + 0x12) < (fVar8 + 20.0) - (float)(iVar5 * 0x12))
           && ((fVar8 + 20.0) - (float)((iVar5 + 1) * 0x12) <=
               (float)(int)*(short *)(iRam00701078 + 0x12))) break;
      }
      if ((iVar5 == 0) || (iVar6 = uVar3 - iVar5, (int)uVar2 < iVar5)) {
        return 0;
      }
    }
    else {
      for (iVar6 = 0; iVar6 < 0xb; iVar6 = iVar6 + 1) {
        if (((float)(int)*(short *)(iRam00701078 + 0x12) < (fVar8 + 20.0) - (float)(iVar6 * 0x12))
           && ((fVar8 + 20.0) - (float)((iVar6 + 1) * 0x12) <=
               (float)(int)*(short *)(iRam00701078 + 0x12))) break;
      }
      if ((int)(uVar3 - *(byte *)(iRam00701078 + 2)) < 9) {
        if ((((iVar6 == 0) || (9 < iVar6)) && (uVar2 < 10)) &&
           ((int)(uVar3 - *(byte *)(iRam00701078 + 5)) < 9)) {
          return 0;
        }
      }
      else {
        if (iVar6 == 0) {
          return 0;
        }
        if (10 < iVar6) {
          return 0;
        }
      }
      iVar6 = 10 - iVar6;
    }
    FUN_0061e730();
    *(char *)(iRam00701078 + 2) = (char)iVar6 + (char)param_1 + *(char *)(iRam00701078 + 5);
    *(undefined4 *)(*(int *)(iRam00701068 + 0x5ffc0 + iVar7) + 0x60) =
         *(undefined4 *)
          (*(int *)(iRam00701068 + 0x5ffc0 + (iVar6 + iVar4 + (uint)*(byte *)(iRam00701078 + 5)) * 4
                   ) + 0x60);
    *(undefined1 *)(*(int *)(iRam00701068 + 0x5ffc0 + iVar7) + 5) =
         *(undefined1 *)
          (*(int *)(iRam00701068 + 0x5ffc0 + (iVar6 + iVar4 + (uint)*(byte *)(iRam00701078 + 5)) * 4
                   ) + 0x5f);
    *(short *)(iRam00701078 + 0x12) =
         (short)(int)((*(float *)(*(int *)(*(int *)(iRam00701078 + 0x20) * 4 + iRam00701068 +
                                          0x5ffc0) + 0x38) - (float)*(int *)(iRam00701070 + 8)) +
                     10.0);
  }
  *(undefined1 *)(iRam00701078 + 4) = 0;
  return 0;
}



================================================================