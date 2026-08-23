FUNCTION FUN_005f16b0 @ 0x005f16b0  size=968
CALLERS (1): FUN_005f1da0@0x005f1da0
CALLEES (0): 
----------------------------------------------------------------

void FUN_005f16b0(int param_1,int param_2,int param_3,uint param_4)

{
  ushort uVar1;
  ushort uVar2;
  ushort uVar3;
  short sVar4;
  uint uVar5;
  int iVar6;
  ushort uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  ushort uVar12;
  uint uVar13;
  uint uVar14;
  ushort uVar15;
  uint uVar16;
  ushort auStack_80 [32];
  ushort auStack_40 [32];
  
  uVar8 = 0;
  if ((*(byte *)(param_1 + 0x46) & 1) == 0) {
    *(ushort *)(param_1 + 0x1c) =
         *(short *)(param_4 * 4 + param_3 + -2) +
         ((ushort)*(byte *)(param_1 + 0x45) + *(short *)(param_1 + 0x32)) * 2;
  }
  sVar4 = *(short *)(param_4 * 4 + param_2 + -2);
  uVar7 = *(short *)(param_1 + 0x1c) +
          ((ushort)*(byte *)(param_1 + 0x45) + *(short *)(param_1 + 0x32)) * -2;
  if ((sVar4 != 0) && (uVar3 = sVar4 - *(short *)(param_1 + 0x32), uVar3 < uVar7)) {
    uVar12 = 0;
    uVar15 = 0;
    for (iVar6 = 0; iVar6 < (int)param_4; iVar6 = iVar6 + 1) {
      uVar1 = *(ushort *)(param_2 + iVar6 * 4 + 2);
      if (uVar12 < uVar1) {
        auStack_40[iVar6] = uVar1 - uVar12;
      }
      else {
        auStack_40[iVar6] = 0;
      }
      uVar2 = *(ushort *)(param_3 + iVar6 * 4 + 2);
      if (uVar15 < uVar2) {
        auStack_80[iVar6] = uVar2 - uVar15;
      }
      else {
        auStack_80[iVar6] = 0;
      }
      uVar12 = uVar1;
      uVar15 = uVar2;
    }
    for (iVar6 = 0; iVar6 < (int)param_4; iVar6 = iVar6 + 1) {
      if (auStack_40[iVar6] <= auStack_80[iVar6]) {
        uVar8 = uVar8 + auStack_80[iVar6] & 0xffff;
      }
    }
    if (uVar8 == 0) {
      uVar8 = param_4 & 0xffff;
    }
    uVar5 = (uint)(ushort)(uVar7 - uVar3);
    uVar10 = 0;
    uVar9 = 0;
    uVar11 = 0;
    for (iVar6 = 0; iVar6 < (int)param_4; iVar6 = iVar6 + 1) {
      uVar7 = auStack_80[iVar6];
      uVar16 = (uint)uVar7;
      uVar14 = (uint)auStack_40[iVar6];
      if (uVar14 <= uVar16) {
        uVar13 = uVar5 - (int)(uVar5 * (uVar8 - uVar7)) / (int)uVar8 & 0xffff;
        uVar14 = uVar13 + uVar14;
        if (uVar14 < uVar16) {
          if (uVar13 != 0) {
            auStack_40[iVar6] = (ushort)uVar14;
            uVar9 = uVar9 + uVar7 & 0xffff;
            uVar10 = uVar10 + 1 & 0xff;
          }
        }
        else {
          auStack_40[iVar6] = uVar7;
          uVar11 = uVar11 + (uVar14 - uVar16 & 0xffff) & 0xffff;
        }
      }
    }
    while ((uVar8 = uVar11, uVar8 != 0 && (uVar10 != 0))) {
      uVar5 = uVar9;
      if (uVar9 == 0) {
        uVar5 = uVar10;
      }
      uVar10 = 0;
      uVar11 = 0;
      uVar9 = 0;
      for (iVar6 = 0; iVar6 < (int)param_4; iVar6 = iVar6 + 1) {
        uVar7 = auStack_80[iVar6];
        uVar16 = (uint)uVar7;
        uVar14 = (uint)auStack_40[iVar6];
        if (uVar14 < uVar16) {
          uVar13 = uVar8 - (int)(uVar8 * (uVar5 - uVar7)) / (int)uVar5 & 0xffff;
          uVar14 = uVar13 + uVar14;
          if (uVar14 < uVar16) {
            if (uVar13 != 0) {
              auStack_40[iVar6] = (ushort)uVar14;
              uVar9 = uVar9 + uVar7 & 0xffff;
              uVar10 = uVar10 + 1 & 0xff;
            }
          }
          else {
            auStack_40[iVar6] = uVar7;
            uVar11 = uVar11 + (uVar14 - uVar16 & 0xffff) & 0xffff;
          }
        }
      }
    }
    uVar11 = 0;
    if (uVar8 != 0) {
      for (iVar6 = 0; iVar6 < (int)param_4; iVar6 = iVar6 + 1) {
        if ((*(byte *)(param_3 + iVar6 * 4) & 4) == 0) {
          uVar11 = uVar11 + auStack_80[iVar6] & 0xffff;
        }
      }
      if (uVar11 == 0) {
        uVar11 = param_4 & 0xffff;
      }
      for (iVar6 = 0; iVar6 < (int)param_4; iVar6 = iVar6 + 1) {
        if ((*(byte *)(param_3 + iVar6 * 4) & 4) == 0) {
          auStack_40[iVar6] =
               auStack_40[iVar6] +
               ((short)uVar8 - (short)((int)(uVar8 * (uVar11 - auStack_80[iVar6])) / (int)uVar11));
        }
      }
    }
    sVar4 = 0;
    for (iVar6 = 0; iVar6 < (int)param_4; iVar6 = iVar6 + 1) {
      sVar4 = sVar4 + auStack_40[iVar6];
      *(short *)(param_2 + iVar6 * 4 + 2) = sVar4;
    }
  }
  return;
}



================================================================