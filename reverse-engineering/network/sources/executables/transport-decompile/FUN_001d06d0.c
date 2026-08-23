
void FUN_001d06d0(int param_1,int param_2,uint *param_3,int param_4,char param_5)

{
  uint uVar1;
  short sVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  ushort uVar6;
  int iVar7;
  int iVar8;
  int *piVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  char cStack_70;
  undefined1 auStack_20 [32];
  
  uVar12 = 0;
  iVar10 = 5;
  *(undefined1 *)(param_2 + 2) = 1;
  uVar3 = param_3[1];
  param_4 = iRam003435bc + param_4;
  for (; (uVar12 < 0x14 && (param_3 < (uint *)(uVar3 + param_1))); param_3 = param_3 + 2) {
    uVar4 = *param_3;
    if (uVar4 != 0) {
      uVar5 = param_3[1];
      iVar7 = uVar12 * 100;
      for (uVar11 = 0; uVar11 < uVar4; uVar11 = uVar11 + 1 & 0xffff) {
        uVar1 = uVar11 % (uint)*(byte *)(param_2 + 1);
        if (uVar1 == 0) {
          cStack_70 = '\0';
        }
        iVar8 = *(int *)(uVar5 + param_1 + uVar11 * 4);
        if ((iVar8 != -1) &&
           ((cStack_70 = '\x01', uVar1 != 0 ||
            (*(short *)(param_2 + (iVar7 + uVar11 / *(byte *)(param_2 + 1)) * 2 + 0xfa4) == 0)))) {
          piVar9 = (int *)(param_1 + iVar8);
          iVar8 = iVar10;
          if (param_5 != '\0') {
            iVar8 = 2000 - iVar10;
          }
          if (*piVar9 == -1) {
            *(short *)(param_2 + (iVar8 + uVar1) * 2 + 4) = (short)piVar9[1];
          }
          else {
            thunk_FUN_00198d30(auStack_20,param_4 + 0x3fU & 0xffffffc0,piVar9);
            uVar6 = FUN_00188a30(auStack_20);
            iVar8 = param_2 + (iVar8 + uVar1) * 2;
            sVar2 = *(short *)(iVar8 + 4);
            if (sVar2 != 0) {
              FUN_00188ad0(sVar2);
            }
            *(ushort *)(iVar8 + 4) = uVar6;
            *piVar9 = -1;
            piVar9[1] = (uint)uVar6;
          }
          if (param_5 == '\0') {
            *(ushort *)(param_2 + (iVar7 + uVar11 / *(byte *)(param_2 + 1)) * 2 + 0xfa4) =
                 (ushort)iVar10 | 0x8000;
          }
          else {
            *(ushort *)(param_2 + (iVar7 + uVar11 / *(byte *)(param_2 + 1)) * 2 + 0xfa4) =
                 2000 - (ushort)iVar10;
          }
        }
        if ((uVar1 == *(byte *)(param_2 + 1) - 1) && (cStack_70 != '\0')) {
          iVar10 = iVar10 + (uint)*(byte *)(param_2 + 1);
        }
      }
    }
    uVar12 = uVar12 + 1 & 0xffff;
  }
  if (param_5 == '\0') {
    *(short *)(param_2 + 0x1f44) = (short)iVar10 + -5;
  }
  else {
    *(short *)(param_2 + 0x1f46) = (short)iVar10 + -5;
  }
  return;
}

